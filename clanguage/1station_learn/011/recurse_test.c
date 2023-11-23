#include <stdio.h>

int factorial(int n)
{
    if (n == 0) {
        return 1;
    } else {
        int resurse = factorial(n - 1);
        int result = n * resurse;
        return result;
    }
}

void main()
{
    int m = 3;
    printf("%d的阶乘是 %d.\n", m, factorial(m));
}
