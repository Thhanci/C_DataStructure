/*
 * ============================================================
 * 第一阶段：基础数据结构 - 哈希表
 * 学习目标：理解哈希函数、键值对存储、冲突解决
 * ============================================================
 * 输入：无（代码内置测试数据）
 * 输出：插入和查找的结果
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Entry {
    char* key;
    int value;
    struct Entry* next;
} Entry;

Entry* table[TABLE_SIZE];

//char* key 是指向字符的指针，它可以指向一个字符数组（字符串），所以可以用 key[i] 来访问数组中的每个字符。   key[i] 等价于 *(key + i)
// 哈希函数
int hash(char* key) {           //计算哈希值  "abc"	'a'=97, 'b'=98, 'c'=99	97+98+99 = 294	294 % 10 = 4	
    int sum = 0;                //"hello"	104+101+108+108+111 = 532	532 % 10 = 2	2
    for (int i = 0; key[i] != '\0'; i++) {  //"world"	119+111+114+108+100 = 552	552 % 10 = 2	2（冲突！）
        sum += key[i];                                      
    }
    return sum % TABLE_SIZE;
}
/*
字符串 "abc" 存入哈希表：

步骤1：计算
"abc" → 'a'(97) + 'b'(98) + 'c'(99) = 294

步骤2：取余
294 % 10 = 4

步骤3：存入
哈希表: [0] [1] [2] [3] [4] [5] [6] [7] [8] [9]
                      ↑
                    "abc" 存在这里！
*/

// 插入
void insert(char* key, int value) {//存入键值队
    int index = hash(key);
    Entry* newEntry = (Entry*)malloc(sizeof(Entry));
    newEntry->key = key;
    newEntry->value = value;
    newEntry->next = NULL;

    if (table[index] == NULL) {
        table[index] = newEntry;
        printf("  ✅ 插入：%s = %d（索引 %d）\n", key, value, index);
        return;
    }

    Entry* current = table[index];
    while (current->next != NULL) {//把哈希值一样的，挂在下面，形成链表，table[index]下，比如table[3](apple)->table[3]next(cat)
        if (strcmp(current->key, key) == 0) {
            current->value = value;
            free(newEntry);
            printf("  🔄 更新：%s = %d\n", key, value);
            return;
        }
        current = current->next;
    }
    current->next = newEntry;
    printf("  ✅ 插入：%s = %d（索引 %d，链式）\n", key, value, index);
}

// 查找
int search(char* key) {//遍历当前index，以及下面的链表
    int index = hash(key);
    Entry* current = table[index];

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

// 打印哈希表
void printTable() {
    printf("\n  📦 哈希表内容：\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("    索引 %2d：", i);
        Entry* current = table[i];
        if (current == NULL) {
            printf("空\n");
        } else {
            while (current != NULL) {
                printf("%s=%d", current->key, current->value);
                if (current->next != NULL) printf(" → ");
                current = current->next;
            }
            printf("\n");
        }
    }
}

int main() {
    printf("========== 哈希表演示 ==========\n\n");

    insert("apple", 10);
    insert("banana", 20);
    insert("grape", 30);
    insert("orange", 40);
    insert("melon", 50);

    printTable();

    printf("\n--- 查找测试 ---\n");
    char* keys[] = {"apple", "banana", "grape", "watermelon"};
    for (int i = 0; i < 4; i++) {
        int val = search(keys[i]);
        if (val != -1) {
            printf("  🔍 %s = %d\n", keys[i], val);
        } else {
            printf("  ❌ 没找到：%s\n", keys[i]);
        }
    }

    return 0;
}


/*
地址:  1000  1001  1002  1003  1004  1005
       ┌────┬────┬────┬────┬────┬────┐
       │ h  │ e  │ l  │ l  │ o  │ \0 │
       └────┴────┴────┴────┴────┴────┘
        ↑
       key 指向这里

key[0] = 从 key 的位置开始，偏移 0 个 → 'h'
key[1] = 从 key 的位置开始，偏移 1 个 → 'e'
key[2] = 从 key 的位置开始，偏移 2 个 → 'l'
*/



/*


 * ============================================================
 * 哈希表（Hash Table）完整笔记
 * ============================================================
 * 
 * 哈希表是一种通过"键（Key）"直接访问"值（Value）"的数据结构。
 * 核心思想：把 key 通过哈希函数计算出一个整数（下标），
 *          把 value 存到对应下标的数组位置。
 * 
 * ============================================================
 * 一、哈希表的组成部分
 * ============================================================
 * 
 * 1. 数组（Array）：存储数据的容器，大小固定（TABLE_SIZE）
 * 2. 哈希函数（Hash Function）：把 key 映射成数组下标
 * 3. 键值对（Key-Value Pair）：要存储的数据
 * 4. 冲突处理（Collision Resolution）：解决不同 key 得到相同下标的问题
 * 
 * ============================================================
 * 二、哈希函数
 * ============================================================
 * 
 * 作用：把任意长度的 key，计算成一个固定范围内的整数
 * 
 * 简单实现（字符串哈希）：
 *     遍历字符串，累加每个字符的 ASCII 码
 *     对 TABLE_SIZE 取余数，保证结果在 0 ~ TABLE_SIZE-1 之间
 * 
 * 代码示例：
 *     int hash(char* key) {
 *         int sum = 0;
 *         for (int i = 0; key[i] != '\0'; i++) {
 *             sum += key[i];          // 累加 ASCII 码
 *         }
 *         return sum % TABLE_SIZE;    // 保证下标不越界
 *     }
 * 
 * 为什么 key[i] 能访问字符串的每个字符？
 *     因为 char* key 是指针，指向字符串首地址
 *     key[i] 等价于 *(key + i)，从首地址偏移 i 个位置
 * 
 * 为什么要取余 % TABLE_SIZE？
 *     避免下标越界，把结果限制在 0 ~ TABLE_SIZE-1 范围内
 *     比如：sum = 294，TABLE_SIZE = 10 → 294 % 10 = 4
 * 
 * ============================================================
 * 三、数据存储结构
 * ============================================================
 * 
 * 存储一个键值对（Key-Value Pair）：
 *     typedef struct Entry {
 *         char* key;        // 键（字符串）
 *         int value;        // 值（整数）
 *         struct Entry* next;  // 指向下一个节点（处理冲突）
 *     } Entry;
 * 
 * 数组 + 链表的组合：
 *     Entry* table[TABLE_SIZE];  // 每个位置存一个链表的头指针
 * 
 * ============================================================
 * 四、插入操作
 * ============================================================
 * 
 * 插入流程：
 *     1. 计算哈希值：index = hash(key)
 *     2. 创建新节点：newEntry
 *     3. 检查 table[index] 是否为空
 *        a. 为空 → 直接存入
 *        b. 不为空 → 遍历链表，检查 key 是否已存在
 *           - 存在 → 更新 value，释放新节点
 *           - 不存在 → 挂到链表末尾
 * 
 * 代码分析：
 *     void insert(char* key, int value) {
 *         int index = hash(key);
 *         Entry* newEntry = (Entry*)malloc(sizeof(Entry));
 *         newEntry->key = key;
 *         newEntry->value = value;
 *         newEntry->next = NULL;
 * 
 *         if (table[index] == NULL) {          // 位置为空
 *             table[index] = newEntry;         // 直接存入
 *             return;
 *         }
 * 
 *         // 位置有数据（发生冲突）
 *         Entry* current = table[index];
 *         while (current->next != NULL) {      // 遍历到链表末尾
 *             if (strcmp(current->key, key) == 0) {  // 找到相同 key
 *                 current->value = value;            // 更新值
 *                 free(newEntry);                    // 释放新节点
 *                 return;
 *             }
 *             current = current->next;
 *         }
 *         current->next = newEntry;            // 挂到末尾
 *     }
 * 
 * 关键点：
 *     - strcmp(current->key, key) == 0  → 两个字符串相等
 *     - strcmp() 不能直接用 == 比较，因为 == 比较的是地址
 *     - current 是"观察者"，遍历链表时不释放节点
 *     - 释放的是 newEntry（重复插入时创建但没用上的节点）
 * 
 * while (current->next != NULL) 的含义：
 *     - "只要当前节点的下一个节点不为空，就继续往后走"
 *     - 目的是走到链表末尾（最后一个节点）
 *     - 退出循环时，current 指向最后一个节点
 *     - 然后 current->next = newEntry 挂载新节点
 * 
 * ============================================================
 * 五、哈希冲突（Collision）
 * ============================================================
 * 
 * 什么是哈希冲突？
 *     两个不同的 key，计算出的哈希值相同
 * 
 * 例子：
 *     hash("apple") = 3
 *     hash("cat") = 3   ← 冲突！
 * 
 * 解决方式：链地址法（Chaining）
 *     把哈希值相同的节点串成一条链表
 * 
 * 图示：
 *     table[3] → [apple:100] → [cat:150] → [dog:50] → NULL
 *                └─ 头节点     └─ 第2个     └─ 第3个
 * 
 * 冲突后插入过程：
 *     1. 插入 "apple"（hash=3）：table[3] 为空 → 直接存入
 *     2. 插入 "cat"（hash=3）：table[3] 不为空 → 遍历链表，挂到末尾
 *     3. 插入 "dog"（hash=3）：继续挂到末尾
 * 
 * 查找冲突数据：
 *     1. 计算 hash(key)
 *     2. 去对应的 index 位置
 *     3. 遍历链表，比较每个节点的 key
 *     4. 匹配则返回 value，否则返回 -1（未找到）
 * 
 * ============================================================
 * 六、查找操作
 * ============================================================
 * 
 * 查找流程：
 *     1. 计算哈希值：index = hash(key)
 *     2. 遍历 table[index] 链表
 *     3. 比较每个节点的 key
 *     4. 匹配则返回 value，否则返回 -1
 * 
 * 代码示例：
 *     int search(char* key) {
 *         int index = hash(key);
 *         Entry* current = table[index];
 *         
 *         while (current != NULL) {
 *             if (strcmp(current->key, key) == 0) {
 *                 return current->value;   // 找到了
 *             }
 *             current = current->next;
 *         }
 *         return -1;  // 没找到
 *     }
 * 
 * ============================================================
 * 七、完整数据结构示例
 * ============================================================
 * 
 * 哈希表结构：
 *     TABLE_SIZE = 10
 * 
 *     table[0]: NULL
 *     table[1]: [banana:200] → [egg:300] → NULL
 *     table[2]: NULL
 *     table[3]: [apple:100] → [cat:150] → [fish:250] → NULL
 *     table[4]: [dog:50] → [grape:120] → NULL
 *     table[5]: NULL
 *     table[6]: NULL
 *     table[7]: NULL
 *     table[8]: [bird:80] → NULL
 *     table[9]: NULL
 * 
 * 解读：
 *     - table[1] 有 2 个节点 (banana, egg)
 *     - table[3] 有 3 个节点 (apple, cat, fish)  ← 冲突最多的位置
 *     - table[4] 有 2 个节点 (dog, grape)
 *     - table[8] 有 1 个节点 (bird)
 *     - 其他位置为空
 * 
 * ============================================================
 * 八、重要概念总结
 * ============================================================
 * 
 * 1. char* key 是什么？
 *    → 字符指针，指向字符串的首地址
 *    → key[i] 可以访问字符串中的每个字符
 * 
 * 2. '\0' 是什么？
 *    → 空字符，ASCII 码为 0
 *    → 标记字符串的结束
 *    → key[i] != '\0' 用于遍历字符串
 * 
 * 3. strcmp() 是什么？
 *    → string compare，字符串比较函数
 *    → 返回 0 表示两个字符串相等
 *    → 在哈希表中用于比较 key 是否相同
 * 
 * 4. NULL 是什么？
 *    → 空指针，表示"不指向任何地方"
 *    → 链表中表示"没有下一个节点了"
 * 
 * 5. 为什么用链表？
 *    → 解决哈希冲突
 *    → 相同 hash 的 key 串在一起
 *    → 查找时遍历链表匹配 key
 * 
 * 6. current 为什么不 free？
 *    → current 是"观察者"，指向链表中的节点
 *    → 释放 current 会删除链表中的节点，破坏链表
 *    → 只有 delete 操作时才释放节点
 * 
 * ============================================================
 * 九、关键代码片段
 * ============================================================
 * 
 * // 定义节点结构
 * typedef struct Entry {
 *     char* key;
 *     int value;
 *     struct Entry* next;
 * } Entry;
 * 
 * // 哈希函数
 * int hash(char* key) {
 *     int sum = 0;
 *     for (int i = 0; key[i] != '\0'; i++) {
 *         sum += key[i];
 *     }
 *     return sum % TABLE_SIZE;
 * }
 * 
 * // 插入（带冲突处理）
 * void insert(char* key, int value) {
 *     int index = hash(key);
 *     Entry* newEntry = (Entry*)malloc(sizeof(Entry));
 *     newEntry->key = key;
 *     newEntry->value = value;
 *     newEntry->next = NULL;
 * 
 *     if (table[index] == NULL) {
 *         table[index] = newEntry;
 *         return;
 *     }
 * 
 *     Entry* current = table[index];
 *     while (current != NULL) {
 *         if (strcmp(current->key, key) == 0) {
 *             current->value = value;
 *             free(newEntry);
 *             return;
 *         }
 *         if (current->next == NULL) {
 *             current->next = newEntry;
 *             return;
 *         }
 *         current = current->next;
 *     }
 * }
 * 
 * // 查找
 * int search(char* key) {
 *     int index = hash(key);
 *     Entry* current = table[index];
 *     while (current != NULL) {
 *         if (strcmp(current->key, key) == 0) {
 *             return current->value;
 *         }
 *         current = current->next;
 *     }
 *     return -1;
 * }
 * 
 * ============================================================
 * 十、记忆口诀
 * ============================================================
 * 
 * 哈希表，真奇妙，键值对，往里放
 * 哈希函数算下标，数组位置找得到
 * 冲突来了不要慌，链表串起排成行
 * 查找先算哈希值，遍历链表找钥匙
 * 
 * ============================================================
 * 
 * 
 */

