#include <stdio.h>
#include <math.h>

double double_mysqrt(double y);
int main(void)
{
    double x, y;
    printf("请输入一个正实数：");
    scanf("%lf", &y);
    x = double_mysqrt(y);
    printf("%lf 的正平方根是：%lf.\n", y, x);
    return 0;
}

double double_mysqrt(double y)
{
    double x, start = 0, end = y;
    while (y >= 0) {
        x = (start + end) / 2;
        if ((x * x - y) >= 0.001) {
            end = x;
        } else if ((y - x * x) >= 0.001) {
            start = x;
        } else {
            return x;
        }
    }
    return -1;
}
