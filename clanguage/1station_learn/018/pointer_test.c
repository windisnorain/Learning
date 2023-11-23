#include <stdio.h>

int main(void)
{
        int i = 10;
        int *p = &i;
        *p = 0;
        char c = 'c';
        char *q = &c;
        printf("%d %d %d %d %d %d\n", i, *&i, &i, p, *p, &p);
        printf("%d %d\n", p, &*p);
        return 0;
}
