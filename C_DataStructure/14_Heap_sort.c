/*
 * ============================================================
 * 第三阶段：高级排序 - 堆排序
 * 学习目标：理解堆（完全二叉树）的性质
 * 时间复杂度：O(n log n)，不稳定排序
 * ============================================================
 * 输入：无（代码内置测试数据）
 * 输出：堆的构建和排序过程
 */

 //【排序算法：堆排序【图解+代码】】https://www.bilibili.com/video/BV1fp4y1D7cj?vd_source=3424baa0ba17a6687e097f58c68731c5

//排序不稳定是指：两个相等的元素，排序后它们的相对顺序可能发生改变。


#include <stdio.h>

// 交换函数
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 打印数组
void print_arr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 堆化（维护堆的性质）
// 参数：arr-数组，n-数组长度，i-待维护节点的下标
void heapify(int arr[], int n, int i) {
    int largest = i;      // 假设当前节点最大
    int lson = i * 2 + 1; // 左子节点
    int rson = i * 2 + 2; // 右子节点

    // 如果左子节点存在且大于当前最大值
    if (lson < n && arr[largest] < arr[lson])
        largest = lson;
    
    // 如果右子节点存在且大于当前最大值
    if (rson < n && arr[largest] < arr[rson])
        largest = rson;
    
    // 如果最大值不是当前节点，交换并递归堆化
    if (largest != i) {
        swap(&arr[largest], &arr[i]);
        heapify(arr, n, largest);
    }
}

// 堆排序入口
void heap_sort(int arr[], int n) {
    int i;
    
    // 1. 建堆（从最后一个非叶子节点开始）
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    
    // 2. 排序（每次把堆顶元素放到末尾）
    for (i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);   // 堆顶（最大值）放到末尾
        heapify(arr, i, 0);        // 重新堆化剩余元素
    }
}

int main() {
    int arr[] = {2, 3, 8, 1, 4, 9, 10, 7, 16, 14};
    int n = 10;
    
    printf("原始数组：");
    print_arr(arr, n);
    
    heap_sort(arr, n);
    
    printf("排序后数组：");
    print_arr(arr, n);
    
    return 0;
}

//2026年6月28日21:04:55

// #include <stdio.h>

// void heapify(int arr[], int n, int i) {
//     int largest = i;
//     int left = 2 * i + 1;
//     int right = 2 * i + 2;

//     if (left < n && arr[left] > arr[largest]) largest = left;
//     if (right < n && arr[right] > arr[largest]) largest = right;

//     if (largest != i) {
//         int temp = arr[i];
//         arr[i] = arr[largest];
//         arr[largest] = temp;
//         heapify(arr, n, largest);
//     }
// }

// void heapSort(int arr[], int n) {
//     printf("--- 建堆 ---\n");
//     for (int i = n / 2 - 1; i >= 0; i--) {
//         heapify(arr, n, i);
//         printf("  堆化位置 %d：", i);
//         for (int j = 0; j < n; j++) printf("%d ", arr[j]);
//         printf("\n");
//     }

//     printf("\n--- 排序 ---\n");
//     for (int i = n - 1; i > 0; i--) {
//         int temp = arr[0];
//         arr[0] = arr[i];
//         arr[i] = temp;
//         heapify(arr, i, 0);

//         printf("  第 %d 步：", n - i);
//         for (int j = 0; j < n; j++) printf("%d ", arr[j]);
//         printf("\n");
//     }
// }

// int main() {
//     printf("========== 堆排序演示 ==========\n\n");

//     int arr[] = {64, 34, 25, 12, 22, 11, 90};
//     int n = 7;

//     printf("原始数组：");
//     for (int i = 0; i < n; i++) printf("%d ", arr[i]);
//     printf("\n\n");

//     heapSort(arr, n);

//     printf("\n--- 排序结果 ---\n");
//     printf("最终数组：");
//     for (int i = 0; i < n; i++) printf("%d ", arr[i]);
//     printf("\n");

//     return 0;
// }