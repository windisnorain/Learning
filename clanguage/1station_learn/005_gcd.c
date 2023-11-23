#include <stdio.h>
#include <math.h>

/*自定义函数-求两个整数的最大公约数*/
int k = 0;
int return_GCD(int a, int b)
{
    k = k + 1;
    if (a % b == 0)
	return b;
    else
	return return_GCD(b, a % b);
}
/*自定义函数-用循环求两个整数的最大公约数*/
int return_GCD_loop(int a, int b)
{
    int c;
    while (a % b != 0) {
	c = b;
	b = a % c;
	a = c;
    }
    return b;
}
/*主函数*/
int main(void)
{
    int i, j;
    printf("请出入两个正整数：\n");
    scanf("%d %d", &i, &j);
    printf("%d 和 %d 的最大公约数是%d\n", i, j, return_GCD_loop(i, j));
    printf("%d 和 %d 的最大公约数是%d\n", i, j, return_GCD(i, j));
    return 0;
}
