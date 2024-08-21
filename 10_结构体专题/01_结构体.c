
#include <stdio.h>

/**
 * 结构体构造类型的数据, 可以不同的 数据类型的 组合的数据结构
 * 数组 也可以是多个数据,但是 数组只能是相同类型的数据组成.
 * 结构体 需要我们自己去定义 这种类型.
 * 结构体--已经有了面向对象的思想了.
 * @return
 */

int main() {
    /// 1.定义结构体类型
    struct Person {
        /// 里面的3个变量,可以称为是结构体成员 或者 属性.
        int age; //年龄
        double height; //身高
        char *name; //姓名
    };

    /// 2.根据结构体类型,定义结构体变量.
    ///PS声明类型的时候 struct 关键字不能少:
    struct Person jack = {10, 1.88, "lmj"};

    /// 另一种赋值方法:
    struct Person rose;
    rose.age = 20,
    rose.height = 1.90,
    rose.name = "damage";

    /// 一次性赋值 只能在定义结构体变量的时候一次赋值,下面这种 {} 一次性赋值是错误的.
    struct Person lilei;
    //lilei = {10, 1.88, "lmj"}; ///❌

    /// 还可以通过这种方式赋值:
    struct Person jackma = {.height=1.88 , .name = "jack_ma", .age = 30};

    printf("person is age =%d, name is = %s, height is = %f", jack.age, jack.name, jack.height);
    return 0;
}