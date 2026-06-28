/*
 * ============================================================
 * 第五阶段：最短路径 - Dijkstra 算法
 * 学习目标：理解贪心扩展最短节点的思想
 * 适用：带权图（权值为正）
 * ============================================================
 * 输入：无（代码内置测试数据）
 * 输出：从起点到各顶点的最短距离
 */
#include <stdio.h>
#include <stdbool.h>

#define MAX 100
#define INF 99999

int graph[MAX][MAX];
int vertexCount = 6;

void initGraph() {
    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++) {
            graph[i][j] = 0;
        }
    }
    // 带权有向图
    graph[0][1] = 4;
    graph[0][2] = 2;
    graph[1][2] = 1;
    graph[1][3] = 5;
    graph[2][3] = 8;
    graph[2][4] = 10;
    graph[3][4] = 2;
    graph[3][5] = 6;
    graph[4][5] = 3;
}

void dijkstra(int start) {
    int dist[MAX];
    bool visited[MAX];

    for (int i = 0; i < vertexCount; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[start] = 0;

    printf("--- 算法过程 ---\n");
    for (int count = 0; count < vertexCount - 1; count++) {
        int min = INF, u = -1;
        for (int i = 0; i < vertexCount; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1) break;
        visited[u] = true;
        printf("  选中最短节点 %d（距离=%d）\n", u, dist[u]);

        for (int v = 0; v < vertexCount; v++) {
            if (!visited[v] && graph[u][v] != 0 && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                printf("    更新 %d：%d + %d = %d\n", v, dist[u], graph[u][v], dist[v]);
            }
        }
    }

    printf("\n--- 结果 ---\n");
    for (int i = 0; i < vertexCount; i++) {
        if (dist[i] == INF) {
            printf("  从 %d 到 %d：无法到达\n", start, i);
        } else {
            printf("  从 %d 到 %d：%d\n", start, i, dist[i]);
        }
    }
}

int main() {
    printf("========== Dijkstra 最短路径演示 ==========\n\n");

    initGraph();
    printf("带权图：\n");
    printf("  0→1:4, 0→2:2, 1→2:1, 1→3:5, 2→3:8, 2→4:10, 3→4:2, 3→5:6, 4→5:3\n\n");

    dijkstra(0);

    return 0;
}