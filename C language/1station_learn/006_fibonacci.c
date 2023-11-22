#include <stdio.h>
#include <math.h>
/*自定义函数-求Fibonacci数列的第n项*/
int return_Fn(int n) {
    if (n <= 1)
	return 1;
    else
	return return_Fn(n - 1) + return_Fn(n - 2);
}
/*自定义函数-循环求Fibonacci数列的第n项*/
int return_Fn_loop(int n) {
    int result = 1;
    int a1 = 1;
    int a2;
    while (n > 1) {
	a2 = a1;
	a1 = result;
	result = a1 + a2;
	n = n - 1;
    }
    return result;
}
/*主函数*/

int main(void) {
    int n;
    printf("请出入一个正整数：\n");
    scanf("%d", &n);
    printf("Fibonacci数列的第%d项是:%d\n", n, return_Fn(n));
    printf("Fibonacci数列的第%d项是:%d\n", n, return_Fn_loop(n));
    return 0;
}
