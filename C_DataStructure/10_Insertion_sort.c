/*
 * ============================================================
 * 第三阶段：高级排序 - 插入排序
 * 学习目标：理解像打牌一样插入到正确位置
 * 时间复杂度：O(n²)，稳定排序
 * 小数据量时效率很好
 * ============================================================
 * 输入：无（代码内置测试数据）
 * 输出：每步插入过程
 */
#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        printf("  插入 %d：", key);

        while (j >= 0 && arr[j] > key) {  //把key的位置空出来，更大的数往后移
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;//j+1为插入手牌的位置

        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

int main() {
    printf("========== 插入排序演示 ==========\n\n");

    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = 6;

    printf("原始数组：");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n\n");

    printf("--- 排序过程 ---\n");
    insertionSort(arr, n);

    printf("\n--- 排序结果 ---\n");
    printf("最终数组：");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

/*

    数组状态：[2, 4, 5, 6, 1, 3]
            ↑        ↑
        已排序    要插入的 key=1

    执行 while 循环：

    第1次：j=3, arr[3]=6 > 1 ✅
        arr[4] = arr[3] → 6 往后移
        [2, 4, 5, 6, 6, 3]
        j=2

    第2次：j=2, arr[2]=5 > 1 ✅
        arr[3] = arr[2] → 5 往后移
        [2, 4, 5, 5, 6, 3]
        j=1

    第3次：j=1, arr[1]=4 > 1 ✅
        arr[2] = arr[1] → 4 往后移
        [2, 4, 4, 5, 6, 3]
        j=0

    第4次：j=0, arr[0]=2 > 1 ✅
        arr[1] = arr[0] → 2 往后移
        [2, 2, 4, 5, 6, 3]
        j=-1

    退出 while（j = -1）
    arr[0] = key = 1
    [1, 2, 4, 5, 6, 3]

*/