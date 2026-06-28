/*
 * ============================================================
 * 第六阶段：算法思想 - 回溯算法
 * 学习目标：理解试错 + 退回的搜索思想
 * ============================================================
 * 输入：无（代码内置测试数据）
 * 输出：N 皇后问题的一个解
 */
#include <stdio.h>
#include <stdbool.h>

#define N 8

int board[N][N];
int solutionCount = 0;

bool isSafe(int row, int col) {
    // 检查列
    for (int i = 0; i < row; i++) {
        if (board[i][col]) return false;
    }
    // 检查左上对角线
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) return false;
    }
    // 检查右上对角线
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j]) return false;
    }
    return true;
}

bool solveNQueens(int row) {
    if (row == N) return true;

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;
            printf("  第 %d 行放皇后在 %d 列 ✓\n", row + 1, col);

            if (solveNQueens(row + 1)) {
                return true;
            }

            // 回溯：走不通，撤销皇后
            board[row][col] = 0;
            printf("  第 %d 行 %d 列 ✗ 回溯\n", row + 1, col);
        }
    }
    return false;
}

void printBoard() {
    printf("\n  ");
    for (int i = 0; i < N; i++) printf(" %d ", i);
    printf("\n");

    for (int i = 0; i < N; i++) {
        printf("%d ", i);
        for (int j = 0; j < N; j++) {
            printf(" %s ", board[i][j] ? "Q" : ".");
        }
        printf("\n");
    }
}

int main() {
    printf("========== 回溯算法 - N 皇后演示 ==========\n\n");
    printf("在 %d×%d 棋盘上放置 %d 个皇后\n", N, N, N);
    printf("皇后不能在同一行、同一列、同一斜线\n\n");

    printf("--- 搜索过程 ---\n");
    if (solveNQueens(0)) {
        printBoard();
    } else {
        printf("无解\n");
    }

    printf("\n--- 特点 ---\n");
    printf("  试错：先放，不行就撤\n");
    printf("  适合解决约束满足问题\n");

    return 0;
}