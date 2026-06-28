/*
 * ============================================================
 * 第五阶段：最短路径 - A* 寻路算法
 * 学习目标：理解 Dijkstra + 启发函数的结合
 * 适用：有明确目标的寻路（游戏 NPC 寻路）
 * ============================================================
 * 输入：无（代码内置测试数据）
 * 输出：找到的路径
 */
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#define MAX 100
#define INF 99999

int graph[MAX][MAX];
int vertexCount = 6;

// 启发函数：曼哈顿距离（估计到目标的距离）
int heuristic(int a, int b) {
    int x[] = {0, 2, 1, 4, 3, 5};
    int y[] = {0, 1, 3, 2, 4, 5};
    return abs(x[a] - x[b]) + abs(y[a] - y[b]);
}

void initGraph() {
    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++) {
            graph[i][j] = 0;
        }
    }
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

void aStar(int start, int target) {
    int gScore[MAX], fScore[MAX], prev[MAX];
    bool inOpen[MAX] = {false};
    int openSet[MAX], openCount = 0;

    for (int i = 0; i < vertexCount; i++) {
        gScore[i] = INF;
        fScore[i] = INF;
        prev[i] = -1;
    }

    gScore[start] = 0;
    fScore[start] = heuristic(start, target);
    openSet[openCount++] = start;
    inOpen[start] = true;

    printf("--- A* 搜索过程 ---\n");
    printf("  目标：%d\n", target);

    while (openCount > 0) {
        int current = -1, minF = INF;
        for (int i = 0; i < openCount; i++) {
            if (fScore[openSet[i]] < minF) {
                minF = fScore[openSet[i]];
                current = openSet[i];
            }
        }

        printf("  当前节点：%d（g=%d, h=%d, f=%d）\n",
               current, gScore[current],
               heuristic(current, target), fScore[current]);

        if (current == target) {
            printf("\n✅ 找到目标！\n");
            printf("路径：");
            int path[MAX], len = 0;
            for (int at = target; at != -1; at = prev[at]) {
                path[len++] = at;
            }
            for (int i = len - 1; i >= 0; i--) {
                printf("%d ", path[i]);
            }
            printf("\n");
            return;
        }

        inOpen[current] = false;
        for (int i = 0; i < openCount; i++) {
            if (openSet[i] == current) {
                openSet[i] = openSet[--openCount];
                break;
            }
        }

        for (int neighbor = 0; neighbor < vertexCount; neighbor++) {
            if (graph[current][neighbor] == 0) continue;
            int tentativeG = gScore[current] + graph[current][neighbor];

            if (tentativeG < gScore[neighbor]) {
                prev[neighbor] = current;
                gScore[neighbor] = tentativeG;
                fScore[neighbor] = gScore[neighbor] + heuristic(neighbor, target);
                if (!inOpen[neighbor]) {
                    openSet[openCount++] = neighbor;
                    inOpen[neighbor] = true;
                }
            }
        }
    }
    printf("\n❌ 没有找到路径\n");
}

int main() {
    printf("========== A* 寻路演示 ==========\n\n");

    initGraph();
    aStar(0, 5);

    printf("\n--- 特点 ---\n");
    printf("  A* = Dijkstra + 启发函数\n");
    printf("  比 Dijkstra 更快找到目标\n");

    return 0;
}