/*
 * ============================================================
 * 第一阶段：基础数据结构 - 栈（先进后出 LIFO）
 * 学习目标：理解栈的 push/pop/peek 操作
 * ============================================================
 * 输入：无（代码内置测试数据）
 * 输出：入栈、出栈、查看栈顶的过程
 */
#include <stdio.h>
#include <stdbool.h>

#define MAX 5  // 用小容量便于观察满栈

int stack[MAX];
int top = -1;

bool isEmpty() { return top == -1; }
bool isFull() { return top == MAX - 1; }

void push(int value) {
    if (isFull()) {
        printf("  ⚠️  栈已满，%d 无法入栈\n", value);
        return;
    }
    stack[++top] = value;
    printf("  ✅ 入栈：%d（栈顶索引=%d）\n", value, top);
}

int pop() {
    if (isEmpty()) {
        printf("  ⚠️  栈为空，无法出栈\n");
        return -1;
    }
    int value = stack[top--];
    printf("  ➡️  出栈：%d（栈顶索引=%d）\n", value, top);
    return value;
}

int peek() {
    if (isEmpty()) {
        printf("  ⚠️  栈为空\n");
        return -1;
    }
    return stack[top];
}

void printStack() {
    printf("  📦 当前栈：[");
    for (int i = 0; i <= top; i++) {
        printf("%d", stack[i]);
        if (i < top) printf(", ");
    }
    printf("]  ← 栈顶\n");
}

int main() {
    printf("========== 栈（先进后出）演示 ==========\n\n");

    printf("--- 入栈操作 ---\n");
    push(10);
    push(20);
    push(30);
    printStack();

    printf("\n--- 查看栈顶 ---\n");
    printf("  栈顶元素：%d\n", peek());

    printf("\n--- 出栈操作 ---\n");
    pop();
    printStack();

    pop();
    printStack();

    printf("\n--- 继续入栈填满 ---\n");
    push(40);
    push(50);
    push(60);  // 第 5 个
    push(70);  // 第 6 个，会失败（栈已满）
    printStack();

    printf("\n--- 出栈全部 ---\n");
    while (!isEmpty()) {
        pop();
    }
    printf("  栈已清空\n");

    return 0;
}