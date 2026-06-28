/*
 * ============================================================
 * 第二阶段：基础排序 - 冒泡排序
 * 学习目标：理解相邻元素交换的排序思想
 * 时间复杂度：O(n²)，稳定排序
 * ============================================================
 * 输入：无（代码内置测试数据）
 * 输出：每轮的排序过程
 */
#include <stdio.h>

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int swapped = 0;
        printf("  第 %d 轮：", i + 1);

        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        for (int j = 0; j < size; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");

        if (!swapped) {   //如果当轮没有任何交换，说明已经有序了
            printf("  已有序，提前结束\n");
            break;
        }
    }
}

int main() {
    printf("========== 冒泡排序演示 ==========\n\n");

    int arr[] = {5, 2, 8, 1, 9};
    int size = 5;

    printf("原始数组：");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n\n");

    printf("--- 排序过程 ---\n");
    bubbleSort(arr, size);

    printf("\n--- 排序结果 ---\n");
    printf("最终数组：");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");

    printf("\n--- 特点 ---\n");
    printf("  每轮把最大的元素'冒泡'到最后\n");
    printf("  稳定排序，但 O(n²) 较慢\n");

    return 0;
}

/*

   计算数组长度 int len = sizeof(arr) / sizeof(arr[0]);

*/