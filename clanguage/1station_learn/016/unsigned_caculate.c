#include <stdio.h>

int countbit(unsigned int x)
{
        int cnt = 0, i;
        unsigned int z;
        for (i = 0; i < 8 * sizeof(x); i++) {
                if (x % 2 != 0) {
                        cnt += 1;
                }
                x = x >> 1;
        }
        return cnt;
}

unsigned int multiply(unsigned int x, unsigned int y)
{
        int sum = 0, i;
        for (i = 0; i < 8 * sizeof(x); i++) {
                if (y % 2 != 0) {
                        sum = sum + (x << i);
                }
                y = y >> 1;
        }
        return sum;
}

int main(void)
{
        unsigned int m = 16, n = 5;
        printf("1 totally is %d\n", countbit(m));
        printf("%d * %d = %d\n", m, n, multiply(m, n));
        return 0;
}
