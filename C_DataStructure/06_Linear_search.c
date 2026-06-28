/*
 * ============================================================
 * 第二阶段：基础查找 - 顺序查找
 * 学习目标：理解最简单直接的查找方式
 * 时间复杂度：O(n)
 * ============================================================
 * 输入：无（代码内置测试数据）
 * 输出：查找结果
 */
#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

void printSearchResult(int arr[], int size, int target) {
    int pos = linearSearch(arr, size, target);
    if (pos != -1) {
        printf("  🔍 找到 %d，位置在索引 %d\n", target, pos);
    } else {
        printf("  ❌ 没找到 %d\n", target);
    }
}

int main() {
    printf("========== 顺序查找演示 ==========\n\n");

    int arr[] = {2, 5, 8, 1, 9, 4, 7, 6, 3, 0};
    int size = 10;

    printf("数组：");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n\n");

    printf("--- 查找测试 ---\n");
    printSearchResult(arr, size, 9);
    printSearchResult(arr, size, 10);
    printSearchResult(arr, size, 0);
    printSearchResult(arr, size, 99);

    printf("\n--- 特点 ---\n");
    printf("  优点：简单，数据不需要有序\n");
    printf("  缺点：慢，每次都要从头到尾遍历\n");

    return 0;
}