//
// Created by whj on 2024/1/10.
//
#include <iostream>


/**
 * 变量的内存地址的细知末节.
 * 本节可以结合 Qt Creator 的查看内存.
 */
void test(){
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
    test();
    return 0;
}

