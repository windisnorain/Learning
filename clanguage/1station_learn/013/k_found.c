#include <stdio.h>

#define LEN 15
int a[LEN] = {0, 100, 38, 23, 42, 3, 11, 10, 7, 58, 13, 15, 76, 98, 19};

int partition(int start, int end)
{
    int i, j, k;
    int tmp = 0;
    int pivot = a[start];
    j = start;
    k = 0;
    for (i = start + 1; i <= end - k; i++) {
        if (a[i] < pivot) {
            tmp = a[i];
            a[i] = pivot;
            a[i - 1] = tmp;
        } else if (a[i] > pivot) {
            tmp = a[end - k];
            a[end - k] = a[i];
            a[i] = tmp;
            k++;
            i--;
        } else
            pivot = a[i];
    }
    return end - k;
}

int order_stastistic(int start, int end, int k)
{

    int i;
    if (end > start) {
        i = partition(start, end);
        if (k == i) {
            return a[k];
        } else if (k > i) {
            order_stastistic(i + 1, end, k - i);
            return a[k - i];
        } else {
            order_stastistic(start, i - 1, k);
            return a[k];
        }
    }
}

int main(void)
{
    int k = 0;
    int k_small;
    while (1) {
        printf("Please enter k: ");
        scanf("%d", &k);
        if (k != 0) {
            k_small = order_stastistic(0, LEN - 1, k - 1);
            printf("%d small number is %d\n", k, k_small);
        }
        k = 0;
    }
    return 0;
}

