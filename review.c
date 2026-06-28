#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// ============================================================
// 1. 结构体定义（放在 main 外面，全局可用）
// ============================================================
struct Student {
    char name[20];
    int age;
    float score;
};

// ============================================================
// 2. 函数定义（放在 main 前面，才能被调用）
// ============================================================
int add(int x, int y) {
    return x + y;
}

void printInfo(char name[], int age) {
    printf("  姓名：%s，年龄：%d\n", name, age);
}

// ============================================================
// 3. main 函数 —— 程序的入口
// ============================================================
int main() {

    // ---------- 1. 基本数据类型 ----------
    printf("========== 1. 基本数据类型 ==========\n");

    int a = 1;
    float b = 2.0f;
    double c = 3.12;
    char d = 'A';
    bool e = true;

    printf("  int a = %d\n", a);
    printf("  float b = %.1f\n", b);
    printf("  double c = %.2f\n", c);
    printf("  char d = %c\n", d);
    printf("  bool e = %d\n", e);
    printf("\n");

    // ---------- 2. 数组 ----------
    printf("========== 2. 数组 ==========\n");

    int numbers[5] = {10, 20, 30, 40, 50};
    char name[] = "张三";

    printf("  数组 numbers：");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    printf("  字符数组 name：%s\n", name);
    printf("\n");

    // ---------- 3. 字符串 ----------
    printf("========== 3. 字符串 ==========\n");

    char str1[20] = "Hello";
    char str2[20] = "World";
    char str3[40];

    strcpy(str3, str1);
    strcat(str3, " ");
    strcat(str3, str2);

    printf("  str1 = %s\n", str1);
    printf("  str2 = %s\n", str2);
    printf("  str3 = %s\n", str3);
    printf("  str1 长度 = %lu\n", strlen(str1));
    printf("\n");

    // ---------- 4. 结构体 ----------
    printf("========== 4. 结构体 ==========\n");

    struct Student s1 = {"李四", 20, 95.5};
    struct Student s2;

    strcpy(s2.name, "王五");
    s2.age = 22;
    s2.score = 88.0;

    printf("  学生1：%s，年龄%d，分数%.1f\n", s1.name, s1.age, s1.score);
    printf("  学生2：%s，年龄%d，分数%.1f\n", s2.name, s2.age, s2.score);
    printf("\n");

    // ---------- 5. 指针 ----------
    printf("========== 5. 指针 ==========\n");

    int num = 100;
    //int *p = &num;
    int *p;
    p=&num;

    printf("  num 的值：%d\n", num);
    printf("  num 的地址：%p\n", &num);
    printf("  p 指向的地址：%p\n", p);
    printf("  p 指向的值：%d\n", *p);
    printf("\n");

    // ---------- 6. 条件判断 ----------
    printf("========== 6. 条件判断 ==========\n");

    int score = 85;

    if (score >= 90) {
        printf("  成绩优秀\n");
    } else if (score >= 70) {
        printf("  成绩良好\n");
    } else {
        printf("  需要加油\n");
    }
    printf("\n");

    // ---------- 7. 循环 ----------
    printf("========== 7. 循环 ==========\n");

    printf("  for 循环：");
    for (int i = 0; i < 5; i++) {
        printf("%d ", i);
    }
    printf("\n");

    printf("  while 循环：");
    int j = 0;
    while (j < 5) {
        printf("%d ", j);
        j++;
    }
    printf("\n");
    printf("\n");

    // ---------- 8. 函数调用 ----------
    printf("========== 8. 函数调用 ==========\n");

    int sum = add(3, 7);
    printf("  3 + 7 = %d\n", sum);

    printInfo("赵六", 25);
    printf("\n");

    // ---------- 9. 格式化输出总结 ----------
    printf("========== 9. 常用格式符 ==========\n");
    printf("  %%d   → 整数：%d\n", 100);
    printf("  %%f   → 浮点数：%.2f\n", 3.14159);
    printf("  %%c   → 字符：%c\n", 'A');
    printf("  %%s   → 字符串：%s\n", "Hello");
    printf("  %%p   → 地址：%p\n", &a);
    printf("  %%lu  → 无符号长整数（如 sizeof）\n");

    // ---------- 10. sizeof ----------
    printf("\n========== 10. 数据类型大小 ==========\n");
    printf("  int 占 %lu 字节\n", sizeof(int));
    printf("  float 占 %lu 字节\n", sizeof(float));
    printf("  double 占 %lu 字节\n", sizeof(double));
    printf("  char 占 %lu 字节\n", sizeof(char));
    printf("  struct Student 占 %lu 字节\n", sizeof(struct Student));

    // ============================================================
    // 你的问题：printf 和 print 的区别
    // ============================================================
    printf("\n========== 注意 ==========\n");
    printf("  ✅ printf() 是 C 语言的输出函数\n");
    printf("  ❌ print() 是 Python 的输出函数，C 语言里不能用\n");
    printf("  所以你的代码里 print(\"hello world!\") 会报错\n");

    return 0;
}