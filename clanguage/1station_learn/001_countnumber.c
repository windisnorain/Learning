#include <stdio.h>
#include <math.h>
int count_9(void)
{
	int a = 1;
	int count = 0;
	while (a <= 100){
		if(a / 10 == 9 || a == 9 || a % 10 == 9) 
			count = count + 1;
		a++;
	}
	return count;
}
int main(void)
{
	printf("%d\n", count_9()); 
	return 0;
}
