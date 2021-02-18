1. 单一出口原则
2. 函数的声明（函数原型）
   int sum(int a, int b); // 函数声明
   int sum(int a, int b) // 函数定义
   {
     return a + b;
   }
3. %d: 格式化int
4. %f: 格式化double
5. %p: 格式化指针类型
6. %x: 格式化int为16进制
7. %u: 无符号10进制int
8. %lu: 无符号长整型（long unsigned）
9. %c: 格式化char类型
10. 指针：int *p,q;
   *p: 是一个int. p是一个指针。
11. 函数通过返回值表明函数执行的状态（是否成功执行）；函数通过指针返回实际的运算结果。
12. #define编译预处理指令，定义宏。
13. char < short< int < float < double
14. char一个字节，long double 16个字节
15. sizeof计算某个类型或某个变量在内存中的字节数
16. 补码：拿补码和原码可以加出一个溢出的”零“
    1.  十进制1为：0000 0001
    2.  十进制0为：0000 0000
    3.  十进制-1为: 0 - 1，即1111 1111
    4.  保证1+(-1)直接相加等0，简化计算机内部标识逻辑。
    5.  同理：对于-a，其补码就是0-a, 实际是2^n-a，n是这种类型的位数。
17. 除了直接操作硬件，其他直接使用int、double。现在的cpu为64位，一次传输数据的最小单元就是8个字节。
18. 编译多个文件：gcc main.c swap.c -o main.ex
19. 指针应用场景：
    1.  交换两个变量
    2.  函数返回多个值
    3.  函数返回运算状态，结果通过指针返回。
20. 指针常见错误：
    1.  定义了指针变量，没有指向任何地址就开始使用。
21. 数组：数组变量是const指针。
    ```
    // int a[] <===> int * const a
    
    int * const q = &i; // q是const 
    *q = 26; // 正确
    q++; // Error

    const int *p = &i;
    *p = 26; // Error
    i = 26; // ok
    p = &j; // ok

    void f(const int* x); // 定义一个指针，不能通过该指针修改指向的内容。常用于函数参数声明，表明函数内部不会对改指针指向的内容做修改。

    int a[]; // a这个指针不能被再次修改赋值。
    const int a[]; // a这个指针指向的元素都是const int不能被修改。

    int sum(const int a[], int len); // 表明该函数不会对array中的元素进行修改。

    ``` 
22. malloc动态申请内存
    1.  malloc申请内存后，需要手动调用free进行释放。
    2.  malloc返回的指针类型为void *
    3.  free释放时传入的指针必须为申请内存的首地址。
23. getchar/putchar
    1.  mac EOF的输入键为：control+D
24. string.h
    1.  字符型char和整型int；
    2.  字符型变量用于存储一个单一字符，在 C 语言中用 char 表示，其中每个字符变量都会占用 1 个字节（8位二进制数）。
    3.  整型int在内存中占用空间为四个字节（32位二进制数）
    4.  字符'0'：char c = '0'; 它的ASCII码实际上是48。内存中存放表示：00110000
    5.  字符'\0' :ASCII码为0，表示一个字符串结束的标志。这是转义字符（整体视为一个字符）。由于内存中存储字符，依然是存储的是对应字符集的字符编码；所以内存中的表现形式为00000000
    6.  整数0 ：内存中表示为：00000000 00000000 00000000 00000000；虽然都是0，但是跟上面字符'\0'存储占用长度是不一样的；
25. string.h
    1.  restrict关键字，告诉编译器两个指针不指向同一数据。参考：https://www.zhihu.com/question/41653775
    2.  strchr 查找char在string中的位置。
    3.  strstr 查找str在string中的位置。
26. 结构
    1.  `enum color {red, blue, yellow}`, 枚举在c语言就是int。可以通过宏、const int来定义类似enum的变量。
    2.  struct结构是值传递，不是引用传递。
        1.  `(*p).xx` 等价于 `p->xx`即`->`含义为取指针指向的内容，然后访问改内容内部的变量。
    3.  `typedef long int_64`. typedef 给数据类型起别名。 `typedef 原始类型 新类型名称`
    4.  `union`定义一个共用内存的数据结构。
    5.  `sizeof(struct point)` 内存大小并不是简单的数据结构相加，里边涉及到`内存对齐`。参考：https://zhuanlan.zhihu.com/p/41039356
27. vscode
    1.  congfig文件中的各种变量名：https://www.cnblogs.com/dusf/p/10609185.html
28. 程序结构
    1.  全局变量: 
        1.  全局变量所有地方都可以访问
        2.  全局变量有默认初始值
        3.  全局变量只能用编译时已知的值来初始化
        4.  全局变量不应该和另外的全局变量或常亮联系在一块。
        5.  全局变量和内部变量重名，全局变量会被隐藏
    2.  静态本地变量 static
        1.  实际就是全局变量
        2.  作用域是本地作用域
    3.  `__func__`获取当前函数的名称
29. 预编译指令
    1.  #号开头是预编译指令
    2.  它不是C语言的成分，但离不开它
    3. .c(源代码)-->(预编译、预处理)-->.i(文本文件)-->(编译)-->.s(汇编文本)-->(汇编)-->.o(目标文件)-->(链接)-->.out(可执行文件)
    4. `#define <名字> <值>`
       1. 结尾没有分号
       2. 名字必须是一个单词，值可以是任何东西
       3. 预编译做全文本替换
       4. `gcc -save-temps`保存编译中间产物
       5. 如果一个宏的值中有其他宏的名字，也会被替换
       6. 像函数的宏`#define cube(x) ((x)*(x)*(x))`
       7. 带参数的宏：部分宏会被inline函数替代
30. 大型程序结构
    1.  头文件
    2.  `int i;` 变量的定义
    3.  `extern int i;` 变量的声明
31. printf & scanf
    1.  printf
        1.  `%[flags][width][.prec][hIL]type`
            1.  flag
                1.  `-`: 左对齐
                2.  `+`: 前面放+或-
                3.  `(spage)`: 正数留空
                4.  `0`: 0填充
            2.  with.prec
                1.  number: 输出字符个数
                2.  *: 占位代码配置输出字符的个数
                3.  .number: 小数点后的字符数
                4.  .*: 占位代码配置小数点后的字符数
            3.  hIL
                1.  hh：当做单个字节
                2.  h: 当做short
                3.  l: 当做long
                4.  ll: 当做long long
                5.  L: 当做long double
    1.  scanf
        1.  `%[flag]type`
            1.  flag
                1.  *: 跳过
                2.  数字：最大字符数
                3.  hh: char
                4.  h: short
                5.  l: long, double
                6.  ll: long long
                7.  L: long double

32. `<`做重定向输入，`>`做重定向输出。eg: `main < a.txt > b.txt`