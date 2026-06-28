/*
 * ============================================================
 * 第四阶段：树与图 - 深度优先搜索（DFS）
 * 学习目标：理解递归在深入遍历中的应用
 * ============================================================
 * 输入：无（代码内置测试数据）
 * 输出：DFS 遍历顺序
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

void DFS(int current, bool visited[], int depth) {
    visited[current] = true;
    printf("%d ", current);

    for (int i = 0; i < vertexCount; i++) {
        if (graph[current][i] != 0 && !visited[i]) {
            printf("(深度 %d) ", depth + 1);
            DFS(i, visited, depth + 1);
        }
    }
}

int main() {
    printf("========== DFS 深度优先搜索演示 ==========\n\n");

    initGraph();

    printf("图结构（邻接表）：\n");
    printf("  0 连接 1, 2\n");
    printf("  1 连接 0, 3\n");
    printf("  2 连接 0, 4\n");
    printf("  3 连接 1, 4, 5\n");
    printf("  4 连接 2, 3\n");
    printf("  5 连接 3\n\n");

    bool visited[MAX] = {false};
    printf("DFS 遍历顺序：");
    DFS(0, visited, 0);
    printf("\n");

    printf("\n--- 特点 ---\n");
    printf("  DFS = 一条路走到黑，走不通再回头\n");
    printf("  使用递归，适合探索所有可能路径\n");

    return 0;
}