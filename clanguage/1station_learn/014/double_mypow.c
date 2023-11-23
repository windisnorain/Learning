#include <stdio.h>

double double_mypow(double x, int n);
int main(void)
{
    double x, y;
    int n;
    printf("请输入一个正实数和一个正整数：");
    scanf("%lf %d", &x, &n);
    y = double_mypow(x, n);
    printf("%lf 的%d次方是：%lf.\n", x, n, y);
    return 0;
}

double double_mypow(double x, int n)
{
    double y;
    if (n == 1) {
        return x;
    } else if (n % 2 == 0) {
        return double_mypow(x, n / 2) * double_mypow(x, n / 2);
    } else {
        return double_mypow(x, n / 2) * double_mypow(x, n / 2 + 1);
    }
}
