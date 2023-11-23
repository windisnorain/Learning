#include <stdio.h>

int main(void)
{
    int i = 0;
    int a, b, c, d;
    a = i++;
    b = ++i;
    c = i--;
    d = --i;
    printf("%d %d %d %d\n", a, b, c, d);
}
