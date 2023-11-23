#include <stdio.h>

#define LEN 12
int a[LEN] = {5, 2, 4, 7, 8, 10, 1, 3, 0, 2, 6, 9};

int partition_bn(int start, int end)
{
    int i, j, k, cnt;
    int b[LEN];
    int pivot = a[start];
    j = start;
    k = 0;
    cnt = start;
    for (i = start + 1; i <= end; i++) {
        if (a[i] > pivot) {
            b[end - k] = a[i];
            k++;
        } else {
            b[j++] = a[i];
            cnt++;
        }
    }
    b[cnt] = pivot;
    for (i = start; i <= end; i++) {
        a[i] = b[i];
    }
    return cnt;
}

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

void quicksort(int start, int end)
{
    int mid;
    if (end > start) {
        mid = partition(start, end);
        quicksort(start, mid - 1);
        quicksort(mid + 1, end);
    }
}

int main(void)
{
    int i;
    /** printf("%d\n", partition(0, LEN - 1)); */
    quicksort(0, LEN - 1);
    for (i = 0; i < LEN; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

