/*
 * ============================================================
 * 第四阶段：树与图 - 图搜索综合
 * 学习目标：BFS 找最短路径 + DFS 检测环
 * ============================================================
 * 输入：无（代码内置测试数据）
 * 输出：最短路径长度和环检测结果
 */
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];
int vertexCount = 6;

void initGraph() {
    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++) {
            graph[i][j] = 0;
        }
    }
    graph[0][1] = graph[1][0] = 1;
    graph[0][2] = graph[2][0] = 1;
    graph[1][3] = graph[3][1] = 1;
    graph[2][4] = graph[4][2] = 1;
    graph[3][4] = graph[4][3] = 1;
    graph[3][5] = graph[5][3] = 1;
}

// BFS 找最短路径
int BFSShortestPath(int start, int target) {
    bool visited[MAX] = {false};
    int queue[MAX], dist[MAX];
    int front = 0, rear = 0;

    for (int i = 0; i < vertexCount; i++) dist[i] = -1;

    visited[start] = true;
    dist[start] = 0;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];
        if (current == target) return dist[current];

        for (int i = 0; i < vertexCount; i++) {
            if (graph[current][i] != 0 && !visited[i]) {
                visited[i] = true;
                dist[i] = dist[current] + 1;
                queue[rear++] = i;
            }
        }
    }
    return -1;
}

// DFS 检测环
bool hasCycleDFS(int current, int parent, bool visited[]) {
    visited[current] = true;
    for (int i = 0; i < vertexCount; i++) {
        if (graph[current][i] != 0) {
            if (!visited[i]) {
                if (hasCycleDFS(i, current, visited)) return true;
            } else if (i != parent) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    printf("========== 图搜索综合演示 ==========\n\n");

    initGraph();

    printf("图结构：\n");
    printf("  0-1, 0-2, 1-3, 2-4, 3-4, 3-5\n\n");

    printf("--- BFS 最短路径 ---\n");
    int dist = BFSShortestPath(0, 5);
    if (dist != -1) {
        printf("  从 0 到 5 的最短路径长度：%d\n", dist);
    } else {
        printf("  无法到达\n");
    }

    printf("\n--- DFS 环检测 ---\n");
    bool visited[MAX] = {false};
    bool hasCycle = hasCycleDFS(0, -1, visited);
    if (hasCycle) {
        printf("  这个图有环\n");
    } else {
        printf("  这个图没有环\n");
    }

    return 0;
}