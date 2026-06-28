/*
 * ============================================================
 * 第一阶段：基础数据结构 - 链表（动态存储）
 * 学习目标：理解链表的节点、插入、删除、遍历
 * ============================================================
 * 输入：无（代码内置测试数据）
 * 输出：链表的构建和操作结果
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 在头部插入
Node* insertAtHead(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    printf("  ✅ 头插：%d\n", value);
    return newNode;
}

// 在尾部插入
Node* insertAtTail(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
/*
malloc(sizeof(Node))	申请一块大小为 sizeof(Node) 字节的内存
(Node*)	                  把申请到的内存地址强制转换成 Node* 类型
*/
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) return newNode;//如果只有空的头结点，直接给头结点赋值返回就行

    Node* temp = head;              //否则就往后找到空位塞
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("  ✅ 尾插：%d\n", value);
    return head;
}

// 删除指定值
Node* deleteNode(Node* head, int value) {
    Node* current = head;
    Node* prev = NULL;//previous上一个，从头开始找

    if (current != NULL && current->data == value) {//如果头节点就是要删的，直接删
        Node* temp = head;//原本头结点是指向被删除的节点的
        head = head->next;
        free(temp);
        printf("  ❌ 删除：%d（头节点）\n", value);
        return head;
    }

    while (current != NULL && current->data != value) {//先遍历找到值
        prev = current;
        current = current->next;
    }

    if (current == NULL) {//找到最后一个结点都没有
        printf("  ⚠️  没找到 %d\n", value);
        return head;
    }

    prev->next = current->next;
    free(current);
    printf("  ❌ 删除：%d\n", value);
    return head;
}

// 打印链表
void printList(Node* head) {
    printf("  📦 链表：");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" → ");
        temp = temp->next;
    }
    printf(" → NULL\n");
}

int main() {
    printf("========== 链表演示 ==========\n\n");

    Node* head = NULL;

    printf("--- 插入节点 ---\n");
    head = insertAtHead(head, 3);
    head = insertAtHead(head, 2);
    head = insertAtHead(head, 1);
    printList(head);

    printf("\n--- 尾部插入 ---\n");
    head = insertAtTail(head, 4);
    head = insertAtTail(head, 5);
    printList(head);

    printf("\n--- 删除节点 ---\n");
    head = deleteNode(head, 2);
    printList(head);

    head = deleteNode(head, 2);  // 再次删除不存在的节点
    printList(head);

    printf("\n--- 删除头节点 ---\n");
    head = deleteNode(head, 1);
    printList(head);

    return 0;
}