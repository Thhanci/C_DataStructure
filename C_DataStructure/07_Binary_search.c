/*
 * ============================================================
 * 第二阶段：基础查找 - 二分查找
 * 学习目标：理解折半查找的原理
 * 前置条件：数组必须有序！
 * 时间复杂度：O(log n)
 * ============================================================
 * 输入：无（代码内置测试数据）
 * 输出：查找过程和结果
 */
#include <stdio.h>

// 二分查找（递归）
int binarySearch(int arr[], int left, int right, int target) {
    if (left > right) return -1;

    int mid = left + (right - left) / 2;  //起始点： 0+1/2 * 首尾差

    printf("  查找范围 [%d, %d]，中间位置 %d（值=%d）\n",
           left, right, mid, arr[mid]);

    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        printf("  目标在右边，继续\n");
        return binarySearch(arr, mid + 1, right, target);
    } else {
        printf("  目标在左边，继续\n");
        return binarySearch(arr, left, mid - 1, target);
    }
}

int main() {
    printf("========== 二分查找演示 ==========\n\n");

    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = 10;

    printf("有序数组：");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n\n");

    int targets[] = {7, 15, 2};

    for (int t = 0; t < 3; t++) {
        int target = targets[t];
        printf("--- 查找 %d ---\n", target);
        int pos = binarySearch(arr, 0, size - 1, target);
        if (pos != -1) {
            printf("  ✅ 找到 %d，在索引 %d\n\n", target, pos);
        } else {
            printf("  ❌ 没找到 %d\n\n", target);
        }
    }

    printf("--- 特点 ---\n");
    printf("  优点：速度极快，O(log n)\n");
    printf("  缺点：数据必须有序\n");

    return 0;
}