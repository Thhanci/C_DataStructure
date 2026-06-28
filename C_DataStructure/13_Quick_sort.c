/*
 * ============================================================
 * 第三阶段：高级排序 - 快速排序
 * 学习目标：理解选基准、分区、递归的思想
 * 时间复杂度：平均 O(n log n)，不稳定排序
 * ============================================================
 * 输入：无（代码内置测试数据）
 * 输出：每轮分区过程
 */

// 【数据结构-快速排序-C语言实现】https://www.bilibili.com/video/BV1Eu411v7QD?vd_source=3424baa0ba17a6687e097f58c68731c5

#include <stdio.h>

void printArray(int array[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int partition(int array[], int i, int j) {//i为基准pivot
    int x = array[i];  // 选第一个元素作为基准
    
    while (i < j) {//因为最终是i=j，所以以此为判断条件
        // 从右向左找第一个大于基准的元素
        while (i < j && array[j] >= x) {
            j--;
        }
        if (i < j) {
            array[i] = array[j];  // 移到右边
            i++;
        }
        
        // 从左向右找第一个小于等于基准的元素
        while (i < j && array[i] < x) {
            i++;
        }
        if (i < j) {
            array[j] = array[i];  // 移到左边
            j--;
        }
    }
    
    array[i] = x;  // 基准放到最终位置
    return i;      // 返回基准位置
}

void quickSort(int array[], int i, int j) {
    if (i < j) {
        int index = partition(array, i, j);
        printArray(array, 8);  // 打印每一轮分区后的结果
        quickSort(array, i, index - 1);   //i
        quickSort(array, index + 1, j);   //index+1为基准元素
    }
}

int main() {
    int array[8] = {27, 38, 13, 49, 76, 97, 65, 49};
    
    printf("原始数组：");
    printArray(array, 8);
    printf("\n--- 排序过程 ---\n");
    
    quickSort(array, 0, 7);
    
    printf("\n--- 排序结果 ---\n");
    printf("最终数组：");
    printArray(array, 8);
    
    return 0;
}

 
// #include <stdio.h>

// int partition(int arr[], int low, int high) {//partition：选基准，把小的放左边，大的放右边，返回基准的最终位置
//     int pivot = arr[high];
//     int i = low - 1;

//     printf("  基准=%d", pivot);

//     for (int j = low; j < high; j++) {  
//         if (arr[j] <= pivot) {
//             i++;
//             int temp = arr[i];
//             arr[i] = arr[j];
//             arr[j] = temp;
//         }
//     }

//     int temp = arr[i + 1];
//     arr[i + 1] = arr[high];
//     arr[high] = temp;

//     printf(" → 分区位置 %d\n", i + 1);
//     return i + 1;
// }

// void quickSort(int arr[], int low, int high) {//quickSort：递归调用 partition，分别排序基准左边和右边
//     if (low < high) {
//         int pi = partition(arr, low, high);

//         printf("  左区间 [%d..%d]，右区间 [%d..%d]\n", low, pi - 1, pi + 1, high);

//         quickSort(arr, low, pi - 1);
//         quickSort(arr, pi + 1, high);
//     }
// }

// int main() {
//     printf("========== 快速排序演示 ==========\n\n");

//     int arr[] = {10, 7, 8, 9, 1, 5};
//     int n = 6;

//     printf("原始数组：");
//     for (int i = 0; i < n; i++) printf("%d ", arr[i]);
//     printf("\n\n");

//     printf("--- 排序过程 ---\n");
//     quickSort(arr, 0, n - 1);

//     printf("\n--- 排序结果 ---\n");
//     printf("最终数组：");
//     for (int i = 0; i < n; i++) printf("%d ", arr[i]);
//     printf("\n");

//     return 0;
// }


//Tip：找基准，小的放左边,大的放右边


/*
 * ============================================================
 * 快速排序（Quick Sort）完整笔记
 * ============================================================
 * 
 * 核心思想：分治 + 分区
 *   1. 选一个基准（pivot）
 *   2. 把小于等于基准的放左边，大于基准的放右边
 *   3. 递归处理左右两边
 * 
 * 时间复杂度：平均 O(n log n)，最坏 O(n²)
 * 空间复杂度：O(log n)（递归栈）
 * 稳定性：不稳定
 * 
 * ============================================================
 * 一、partition 函数 —— 分区
 * ============================================================
 * 
 * 作用：选基准，把数组分成"左小右大"，返回基准最终位置
 * 
 * 逻辑：
 *   1. 选最后一个元素作为基准 pivot
 *   2. i 指向"小元素区域"的最后一个位置（初始为 low-1）
 *   3. j 从 low 遍历到 high-1
 *      - 如果 arr[j] <= pivot，i++，交换 arr[i] 和 arr[j]
 *      - 否则不动
 *   4. 最后把基准放到 i+1 位置
 *   5. 返回 i+1（基准的位置）
 * 
 * ============================================================
 * 二、partition 执行过程图解
 * ============================================================
 * 
 * 数组：[10, 7, 8, 9, 1, 5]，pivot=5，i=-1
 * 
 * j=0: [10, 7, 8, 9, 1, 5]  10>5 ❌ 不动
 * j=1: [10, 7, 8, 9, 1, 5]  7>5 ❌  不动
 * j=2: [10, 7, 8, 9, 1, 5]  8>5 ❌  不动
 * j=3: [10, 7, 8, 9, 1, 5]  9>5 ❌  不动
 * j=4: [10, 7, 8, 9, 1, 5]  1<5 ✅  i=0，交换 arr[0]↔arr[4]
 *      [1, 7, 8, 9, 10, 5]
 * 
 * 最后：把基准放到 i+1 位置（索引1）
 *      [1, 5, 8, 9, 10, 7]
 *          ↑
 *       基准到位
 * 
 * 分区结果：
 *   左边：[1]           ← 都 ≤ 5
 *   右边：[8, 9, 10, 7] ← 都 > 5
 * 
 * ============================================================
 * 三、quickSort 函数 —— 递归排序
 * ============================================================
 * 
 * 作用：递归调用 partition，分别排序左右区间
 * 
 * 逻辑：
 *   1. 如果 low < high（至少两个元素）
 *   2. 调用 partition 分区，得到基准位置 pi
 *   3. 递归排序左区间 [low, pi-1]
 *   4. 递归排序右区间 [pi+1, high]
 * 
 * ============================================================
 * 四、完整执行过程图解
 * ============================================================
 * 
 * 原始：[10, 7, 8, 9, 1, 5]
 * 
 * 第1次 partition [0..5]：
 *   [1, 5, 8, 9, 10, 7]  → pi=1
 *   左 [0..0]：[1]
 *   右 [2..5]：[8, 9, 10, 7]
 * 
 * 第2次 partition [2..5]（右边）：
 *   [1, 5, 7, 9, 10, 8]  → pi=4
 *   左 [2..3]：[7]
 *   右 [5..5]：[8, 9, 10]
 * 
 * 第3次 partition [3..5]：
 *   [1, 5, 7, 8, 9, 10]  → pi=5
 *   左 [3..4]：[8]
 *   右 [6..5]：空
 * 
 * 第4次 partition [4..5]：
 *   [1, 5, 7, 8, 9, 10]  → pi=4
 *   左 [3..3]：[8]
 *   右 [5..5]：[10]
 * 
 * 完成：[1, 5, 7, 8, 9, 10] ✅
 * 
 * ============================================================
 * 五、代码
 * ============================================================
 */

 /*

#include <stdio.h>

// 分区函数
int partition(int arr[], int low, int high) {
    int pivot = arr[high];   // 选最后一个元素作为基准
    int i = low - 1;         // i 指向"小元素区域"的最后一个位置

    printf("  基准=%d", pivot);

    // 遍历所有元素（除了基准本身）
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {   // 发现小元素
            i++;                 // 扩大"小元素区域"
            // 交换 arr[i] 和 arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // 把基准放到 i+1 位置（小元素区域的后面）
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    printf(" → 分区位置 %d\n", i + 1);
    return i + 1;  // 返回基准的位置
}

// 快速排序
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // 分区

        printf("  左区间 [%d..%d]，右区间 [%d..%d]\n", low, pi - 1, pi + 1, high);

        quickSort(arr, low, pi - 1);   // 排序左边
        quickSort(arr, pi + 1, high);  // 排序右边
    }
}

int main() {
    printf("========== 快速排序演示 ==========\n\n");

    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = 6;

    printf("原始数组：");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n\n");

    printf("--- 排序过程 ---\n");
    quickSort(arr, 0, n - 1);

    printf("\n--- 排序结果 ---\n");
    printf("最终数组：");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
*/

/*
 * ============================================================
 * 六、关键点总结
 * ============================================================
 * 
 * 1. partition 是核心
 *    - i：小元素区域的边界
 *    - j：遍历指针
 *    - 找到小元素就交换到前面
 * 
 * 2. 基准的选择
 *    - 选最后一个元素（代码中）
 *    - 也可以选第一个、中间、随机
 * 
 * 3. 递归终止条件
 *    - low >= high 时停止（只有一个元素或空）
 * 
 * 4. 分区结果
 *    - 基准左边都 ≤ 基准
 *    - 基准右边都 > 基准
 *    - 基准已经在最终位置
 * 
 * 5. 与归并排序对比
 *    归并：先拆到底，再合并（从底向上）
 *    快排：先分区，再递归（从顶向下）
 * 
 * 6. 记忆口诀
 *    选基准，分两边，
 *    小左大右排中间。
 *    递归处理左右块，
 *    直到全部排完满。
 * 
 * ============================================================
 */