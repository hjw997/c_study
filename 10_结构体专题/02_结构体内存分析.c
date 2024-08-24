#include <stdio.h>

int main() {

    /// 1. 定义结构体类型:
    struct Date {
        int year;
        int month;
        int day;
    }; /// 仅仅定义类型,不会占用内存空间.

    /// 2. 定义结构体变量: 2011-09-10
    ///  struct Date date = {2011,09,10};  //ps: 0开头表示 8进制
    struct Date date = {2011,9,10}; ///真正分配内存空间.
    printf("%lu\n",sizeof(date));
    ///0x16b6232d0 - 0x16b6232d0 -0x16b6232d4 - 0x16b6232d812
    printf("%p - %p -%p - %p ", &date, &date.year, &date.month, &date.day);


    struct Date d2 = {2015,12,10};
    /// 会将 date 所有成员的值对应的赋值给d2 的所有成员.
    d2 = date;

    printf("\n-----------------------------------\n");
    struct Student {
        int age; /// int 4个字节
        char *name; /// 指针占用 8 个字节
    }; /// 理论上 该结构体 占用 4 + 8  = 12 个字节. 实际是 16, 内存对齐(规则: 最大成员的倍数)

    struct Student stu;
    stu.age = 10;
    stu.name = "jack";
    int size = sizeof(stu);
    printf("stu size is %d \n",size);
    printf("&stu=%p --- \n&stu.age = %p ----- \n&stu.name = %p \n",&stu,&stu.age,&stu.name);


    char c ;
    c = 'A';
    printf("\nc ===  %ld \n", sizeof(c));


    #pragma  pack(show)  /// warning: value of #pragma pack(show) == 8

    struct Teacher {
        char a;
        int b;
    };

    struct Teacher teacher ;
    printf("\nteacher 的地址: = %p ,占用内存大小:%lu \n",&teacher, sizeof(teacher));
    /// 断点看内存:
    ///  61 00 00 00   0a 00 00 00   实际上的 字符 占了 4 个字节. 并非想象的 61  0a 00 00 00  这种结构. 读取多次等, 读取出来确实还要分离各个数据 比较麻烦.
    teacher.a = 'a';
    teacher.b = 10;

    struct TeacherB {
        char a; /// offset 是 0  占用一个字节, ⭐️⭐️⭐️⭐️⭐️⭐️⭐️
        ///  但是对齐规则  下一个成员的偏移地址 min(当前成员,pack(show)) 开始. 所以 a 后空出了 7个字节不用, 第8个字节开始放b
        double b; // offset 是 8   8开始 占8 个字节
        /// 所以总的占 8+8 16个字节. 最后在 结构体总体再对齐  最大成员的倍数.
    };


    struct TeacherB teacherB ;
    printf("\nteacherB 的地址: = %p ,占用内存大小:%lu \n",&teacherB, sizeof(teacherB));
    /// 断点看内存:
    /// 61 00 00 00   00 00 00 00    这里虽然看 有很多个补0 , 但是是空着没用的. 实际 只有一个 字节 那就是 61
    /// 00 00 00 00   00 00 24 40    b占用的空间 8 个字节.
    teacherB.a = 'a';
    teacherB.b = 10;


    struct TeacherC {
        char a;
        double b;
        int c;
    };

    struct TeacherC teacherC ;
    printf("\nteacherC 的地址: = %p ,占用内存大小:%lu \n",&teacherC, sizeof(teacherC));
    /// 断点看内存:
    ///                               61 00 a4 04   01 00 00 00
    ///   00 00 00 00   00 00 24 40   14 00 00 00   00 00 00 00
    teacherC.a = 'a';
    teacherC.b = 10;
    teacherC.c = 20;


    struct TeacherD {
        char a;
        char b;
    };

    struct TeacherD teacherD ;
    printf("\nteacherD 的地址: = %p ,占用内存大小:%lu \n",&teacherD, sizeof(teacherD));
    /// 断点看内存:

    teacherD.a = 'a';
    teacherD.b = 'b';


    struct Person {
        int a; ///  第一个元素偏移量 是 0
        char b; /// 第二个 offset 1
        double c; /// 偏移是 8  占用 8-15  8个字节
        float d; /// 16-19 4个字节
        /// 所有成员 占了 20个字节, 然后整体偏移 占最大成员的 倍数 . 8  .  20 再往上 就是 24 是8 的倍数.
    };
    struct Person person ;
    printf("\nperson 的地址: = %p ,占用内存大小:%lu \n",&person, sizeof(person)); //person 的地址: = 0x16f43b248 ,占用内存大小:24
    /// 断点看内存:
    ///                            0a 00 00 00(int a)   62(char b) 00 00 00
    ///00 00 00 00   00 00 59 40 (double c)   00 00 20 41 (float d)   98 54 e9 5d

    person.a = 10;
    person.b = 'b';
    person.c = 100;
    person.d = 10;

    return 0;
}

/**
* 结构体内存里面的内存是连续的 .
 * 结构体占用实际大小要考虑内存对齐
 *
 * 内置数据类型的对齐规则:自身的整数倍
*/