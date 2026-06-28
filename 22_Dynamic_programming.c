/*
 * ============================================================
 * 第六阶段：算法思想 - 动态规划
 * 学习目标：理解重叠子问题 + 状态转移
 * ============================================================
 * 输入：无（代码内置测试数据）
 * 输出：斐波那契和背包问题的结果
 */
#include <stdio.h>

// 斐波那契
int fib(int n) {
    int dp[n + 1];
    dp[0] = 0;
    if (n >= 1) dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// 0-1 背包
int knapsack(int values[], int weights[], int n, int capacity) {
    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                int take = values[i - 1] + dp[i - 1][w - weights[i - 1]];
                int skip = dp[i - 1][w];
                dp[i][w] = (take > skip) ? take : skip;
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // 打印 DP 表
    printf("  DP 表：\n");
    for (int i = 0; i <= n; i++) {
        printf("    ");
        for (int w = 0; w <= capacity; w += 10) {
            printf("%4d ", dp[i][w]);
        }
        printf("\n");
    }

    return dp[n][capacity];
}

int main() {
    printf("========== 动态规划演示 ==========\n\n");

    printf("--- 斐波那契数列 ---\n");
    for (int i = 0; i <= 10; i++) {
        printf("  fib(%d) = %d\n", i, fib(i));
    }

    printf("\n--- 0-1 背包问题 ---\n");
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int n = 3, capacity = 50;

    printf("  物品：(价值, 重量) = (60,10), (100,20), (120,30)\n");
    printf("  背包容量：%d\n\n", capacity);

    int result = knapsack(values, weights, n, capacity);
    printf("  最大价值：%d\n", result);

    printf("\n--- 特点 ---\n");
    printf("  把大问题拆成重叠子问题，保存结果\n");
    printf("  避免重复计算，效率高\n");

    return 0;
}