//
// Created by whj on 2024/1/10.
//

#include <iostream>

/**
 * 数组的初始化
 */
void test_init1(){
    int a[3]; //未初始化就去访问 .
    printf("%d",a[0]); //未初始化访问获得的是个垃圾值.
}

void test_init2(){
    /**
     * 可以在申明数组的时候只初始化一部分元素,其他元素默认会初始化为0
     */
    int a[5] = {11,22,33};
    for (int i = 0; i < 5; ++i) {
        printf("a[%d] = %d \n",i,a[i]);
    }
    /** 打印结果:
        a[0] = 11
        a[1] = 22
        a[2] = 33
        a[3] = 0
        a[4] = 0
     */
}

int main() {
    // test_init();
    test_init2();
    return 0;
}

/**
 https://www.bilibili.com/video/BV1g7411F7Bn?p=162&vd_source=9d2ff4daa93ba2f65d04081137bf4e05
 这里的练习还没做  . 截止到这里了.
 */
