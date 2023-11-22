#include <stdio.h>

int recursion(int n)
{
    int result;
    if (n == 1) {
        return 1;
    } else {
        result = n * recursion(n - 1);
        printf("%d\n", n);
        return result;
    }
}

int main(void)
{
    int n = 5, m;
    m = recursion(n);
    printf("%d! is %d.\n", n, m);

    return 0;
}
