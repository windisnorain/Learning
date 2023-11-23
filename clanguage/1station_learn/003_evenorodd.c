#include <stdio.h>
#include <math.h>
/*自定义函数-打印奇偶数*/
void printParity(int x)
{
    if (x % 2 == 0)
	printf("this is even number.\n");
    else
	printf("this is odd number.\n");
}
void printNumber(int x)
{
    printf("x的十位数字是：%d\nx的个位数字是：%d\n", (x % 100) / 10, x % 10);
}
int main(void)
{
    int x;
    printf("请输入一个正整数：\n");
    scanf("%d", &x);
    printParity(x);
    printNumber(x);
}
