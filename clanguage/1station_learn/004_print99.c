#include <stdio.h>
#include <math.h>
/*自定义函数-打印九九乘法表*/
int print_99(void)
{
	int i, j;
	for(i = 1; i <= 9; i++){
		for(j = 1; j <= i; j++){
			printf("%d * %d = %d\t", j, i, i*j);
		}
		printf("\n");
	}
}
/*主函数*/
int main(void)
{
	print_99();
}
