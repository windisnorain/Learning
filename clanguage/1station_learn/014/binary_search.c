#include <stdio.h>

#define LEN 8
int a[LEN] = {1, 2, 2, 2, 5, 6, 8, 9};

int binary_search(int number)
{
    int i;
    int mid, start = 0, end = LEN - 1;
    while (start <= end) {
        mid = (start + end) / 2;
        if (a[mid] < number) {
            start = mid + 1;
        } else if (a[mid] < number) {
            end = mid - 1;
        } else {
            i = mid;
            while (a[i - 1] == number) {
                mid = mid - 1;
                i--;
            }
            return mid;
        }
    }
    return -1;
}

int main(void)
{
    int m, n;
    printf("Please give a number: ");
    scanf("%d", &n);
    m = binary_search(n);
    printf("%d is no.%d.\n", n, m);
    return 0;
}
