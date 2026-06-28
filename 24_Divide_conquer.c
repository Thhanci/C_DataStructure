/*
 * ============================================================
 * 第六阶段：算法思想 - 分治算法
 * 学习目标：理解大问题拆成小问题的思想
 * ============================================================
 * 输入：无（代码内置测试数据）
 * 输出：最大子数组和
 */
#include <stdio.h>
#include <limits.h>

// 跨中点的最大子数组和
int maxCrossingSum(int arr[], int left, int mid, int right) {
    int sum = 0;
    int leftSum = INT_MIN;
    for (int i = mid; i >= left; i--) {
        sum += arr[i];
        if (sum > leftSum) leftSum = sum;
    }

    sum = 0;
    int rightSum = INT_MIN;
    for (int i = mid + 1; i <= right; i++) {
        sum += arr[i];
        if (sum > rightSum) rightSum = sum;
    }
    return leftSum + rightSum;
}

int maxSubArraySum(int arr[], int left, int right) {
    if (left == right) return arr[left];

    int mid = left + (right - left) / 2;
    printf("  分治 [%d..%d] → [%d..%d] + [%d..%d]\n",
           left, right, left, mid, mid + 1, right);

    int leftMax = maxSubArraySum(arr, left, mid);
    int rightMax = maxSubArraySum(arr, mid + 1, right);
    int crossMax = maxCrossingSum(arr, left, mid, right);

    int result = (leftMax > rightMax) ? leftMax : rightMax;
    result = (result > crossMax) ? result : crossMax;

    printf("  [%d..%d] 最大值：%d\n", left, right, result);
    return result;
}

int main() {
    printf("========== 分治算法 - 最大子数组和 ==========\n\n");

    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("数组：");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n\n");

    printf("--- 分治过程 ---\n");
    int result = maxSubArraySum(arr, 0, n - 1);

    printf("\n--- 结果 ---\n");
    printf("最大子数组和：%d\n", result);

    printf("\n--- 特点 ---\n");
    printf("  分治 = 大问题 → 小问题 → 合并结果\n");
    printf("  归并排序、快速排序也是分治思想\n");

    return 0;
}