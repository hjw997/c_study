#include <iostream>

void test01(){
    //0b 开头 二进制.
    int i = 20; //十进制
    int i2 = 0b10100; //二进制 2^4 + 2^2 = 20 二进制转10进制就是挑是1的然后看第几个次方(最低的从0开始).
    int i3 = 0b10101; //二进制 2^4 + 2^2  + 2^0 = 16 + 4 + 1 = 21
    int i16 = 0x14; //十六进制
    //%d 就是以十进制的形式 展示出右边的数.
    printf("%d  %d %d %d", i, i2, i3, i16);


    int a = 20;
    printf("十进制:%d\n", a); //%d 十进制
    printf("十进制:%i\n", a); //%i 十进制

    printf("八进制:%o\n", a); //%o 八进制
    printf("十六进制:%x\n", a);//%x 十六进制

    /**
     sizeof 运算符的使用 : 查看某个类型占用的字节数.
     */
    int t = 10;
    int size = sizeof(t);
    int size_t = sizeof(int);
    int size_a = sizeof a;
    printf("size占=%d 个字节 \n", size);
    printf("size_t=%d \n", size_t);
}

/**
 * 变量的内存地址的细知末节.
 */
void test02(){
    /**
     * 变量的内存地址:
     * 取出某个变量(内存地址) 也就是这个变量的地址的首字节的内存地址.
     * &变量  &的发音: and @ at  & and
     */
    int a1 = 100;
    int *address = &a1;
    printf("address = %p \n",address);

    printf("a1的内存地址:%p \n", &a1);

}

int main() {

    // test01(); //基础语法测试.
    test02();
    return 0;
}
