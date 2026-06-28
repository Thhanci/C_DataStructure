/*
 * ============================================================
 * 第六阶段：算法思想 - 贪心算法
 * 学习目标：理解每步局部最优的选择思想
 * ============================================================
 * 输入：无（代码内置测试数据）
 * 输出：找零钱方案和活动选择结果
 */
#include <stdio.h>

// 找零钱问题
void coinChange(int amount) {
    int coins[] = {25, 10, 5, 1};
    int count = 4;
    int result[4] = {0};

    printf("找零 %d 分：\n", amount);
    for (int i = 0; i < count; i++) {
        result[i] = amount / coins[i];
        amount = amount % coins[i];
        printf("  %d 分硬币 × %d\n", coins[i], result[i]);
    }
}

// 活动选择
typedef struct {
    int start;
    int end;
} Activity;

void activitySelection(Activity activities[], int n) {
    printf("选择的活动：");
    int lastEnd = 0;
    for (int i = 0; i < n; i++) {
        if (activities[i].start >= lastEnd) {
            printf("(%d-%d) ", activities[i].start, activities[i].end);
            lastEnd = activities[i].end;
        }
    }
    printf("\n");
}

int main() {
    printf("========== 贪心算法演示 ==========\n\n");

    printf("--- 找零钱问题 ---\n");
    coinChange(63);
    coinChange(89);

    printf("\n--- 活动选择问题 ---\n");
    Activity acts[] = {{1, 3}, {2, 4}, {3, 5}, {4, 6}, {5, 7}};
    int n = sizeof(acts) / sizeof(acts[0]);
    activitySelection(acts, n);

    printf("\n--- 特点 ---\n");
    printf("  每步选当前最优，不保证全局最优\n");
    printf("  但效率高，适合找零钱、活动选择等\n");

    return 0;
}