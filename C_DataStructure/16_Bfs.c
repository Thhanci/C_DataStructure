/*
 * ============================================================
 * 第四阶段：树与图 - 广度优先搜索（BFS）
 * 学习目标：理解队列在逐层遍历中的应用
 * ============================================================
 * 输入：无（代码内置测试数据）
 * 输出：BFS 遍历顺序
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

void BFS(int start) {
    bool visited[MAX] = {false};
    int queue[MAX];
    int front = 0, rear = 0;
    int step = 0;

    visited[start] = true;
    queue[rear++] = start;

    printf("BFS 遍历顺序（从 %d 开始）：\n", start);
    printf("  第0层：%d\n", start);

    while (front < rear) {
        int current = queue[front++];
        step++;

        for (int i = 0; i < vertexCount; i++) {
            if (graph[current][i] != 0 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
                printf("  从 %d 发现 %d\n", current, i);
            }
        }
    }

    printf("\n遍历顺序：");
    for (int i = 0; i < rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    printf("========== BFS 广度优先搜索演示 ==========\n\n");

    initGraph();

    printf("图结构（邻接表）：\n");
    printf("  0 连接 1, 2\n");
    printf("  1 连接 0, 3\n");
    printf("  2 连接 0, 4\n");
    printf("  3 连接 1, 4, 5\n");
    printf("  4 连接 2, 3\n");
    printf("  5 连接 3\n\n");

    BFS(0);

    printf("\n--- 特点 ---\n");
    printf("  BFS = 一层一层往外扩展\n");
    printf("  使用队列，适合找无权图的最短路径\n");

    return 0;
}