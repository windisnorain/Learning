#include <stdio.h>
#include <math.h>
/*自定义函数-打印菱形*/
int diamond(int x, char ch)
{
	int i, j; 
	//打印中间行以上部分，包含中间行
	for (i = 1; i <= x / 2 + 1; i++){
			for (j = 1; j <= i + x / 2; j++){
				if (j <= (x - 2 * i + 1) / 2){
					printf(" \t");
				}
				else {
					printf("%c\t", ch);
				}
			}
			printf("\n");
		}
		//打印中间行以下部分
		for (i = x / 2 + 2; i <= x ; i++){
			for (j = 1; j <= x - i + x / 2 + 1; j++){
				if (j <= (2 * i - x) / 2){
					printf(" \t");
				}
				else {
					printf("%c\t", ch);
				}
			}
			printf("\n");
		}
}
/*主函数*/
int main(void)
{		
	int x;
	char ch;
	printf("请输入一个奇数和一个字符！\n");
	scanf("%d %c",&x,&ch);
    while(x % 2 ==0){
		printf("非奇数，请重新输入一个奇数！\n");
		scanf("%d",&x);
	}
	diamond(x, ch);
	return 0;
}
