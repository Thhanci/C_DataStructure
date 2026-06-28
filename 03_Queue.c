/*
 * ============================================================
 * 第一阶段：基础数据结构 - 队列（先进先出 FIFO）
 * 学习目标：理解队列的 enqueue/dequeue 操作
 * ============================================================
 * 输入：无（代码内置测试数据）
 * 输出：入队、出队的过程
 */
#include <stdio.h>
#include <stdbool.h>

#define MAX 5

int queue[MAX];
int front = 0;
int rear = -1;
int count = 0;

bool isEmpty() { return count == 0; }
bool isFull() { return count == MAX; }

void enqueue(int value) {
    if (isFull()) {
        printf("  ⚠️  队列已满，%d 无法入队\n", value);
        return;
    }
    rear = (rear + 1) % MAX;//有2个指针，rear & front,一直+早晚溢出，所以用%循环
    queue[rear] = value;
    count++;
    printf("  ✅ 入队：%d（队尾=%d，元素数=%d）\n", value, rear, count);
}

int dequeue() {
    if (isEmpty()) {
        printf("  ⚠️  队列为空，无法出队\n");
        return -1;
    }
    int value = queue[front];
    front = (front + 1) % MAX;
    count--;
    printf("  ➡️  出队：%d（队头=%d，元素数=%d）\n", value, front, count);
    return value;
}

void printQueue() {
    printf("  📦 当前队列：[");
    if (count > 0) {
        int idx = front;
        for (int i = 0; i < count; i++) {
            printf("%d", queue[idx]);
            if (i < count - 1) printf(", ");
            idx = (idx + 1) % MAX;
        }
    }
    printf("]  （front=%d, rear=%d, count=%d）\n", front, rear, count);
}

int main() {
    printf("========== 队列（先进先出）演示 ==========\n\n");

    printf("--- 入队操作 ---\n");
    enqueue(1);
    enqueue(2);
    enqueue(3);
    printQueue();

    printf("\n--- 出队操作 ---\n");
    dequeue();
    printQueue();

    dequeue();
    printQueue();

    printf("\n--- 继续入队 ---\n");
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);  // 第 5 个
    enqueue(8);  // 会失败（队列已满）
    printQueue();

    printf("\n--- 出队全部 ---\n");
    while (!isEmpty()) {
        dequeue();
    }
    printf("  队列已清空\n");

    return 0;
}