//
// Created by whj on 2024/1/10.
//
#include <iostream>

void charTest(){

    //字符:
    int i = 97;
    char c1 = 'a';
    char c2 = 'A';

    printf("%c %c %d \n",c1,c2,i);
    printf("%d",c1);
    /**
     把c1,内存中的0101二进制数据以十进制的形式打印出
     始终记得字符的本质就是 以ASCII 编码后的一个数值.
     ASCII码就是单字节编码方案.✅✅
     字符在内存中就是这个数值以二进制放到内存中.
    */

}

void charTest01(){

    /**
     * 注意下面这两句是可以的:
     * 因为字符本质上在内存中就是 一个数值.
     */
    int  i = 'a';
    char c = 97;

    /**
     * %c 以字符形式把内存中的 0101的二进制数据展示出来
     * %d 以十进制形式把内存中的 0101的二进制数据展示出来
     */
    printf("%d \n",i);
    printf("%c \n",i);

    printf("%d \n",c);
    printf("%c \n",c);

}

int main() {

    charTest();
    charTest01();
    return 0;
}