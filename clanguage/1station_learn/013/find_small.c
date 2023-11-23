#include <stdio.h>

#define LEN 8
int a[LEN] = {4, 4, 3, 7, 8, 1, 5, 6};

int find_smallest(int start, int end)
{
    int tmp = a[start];
    int i;
    for (i = start + 1; i <= end; i++) {
        if (a[i] >= tmp) {
            continue;
        } else {
            tmp = a[i];
        }
    }
    return tmp;
}

int find_small_second(int start, int end)
{
    int small, second;
    int i;
    if (a[start] >= a[start + 1]) {
        small = a[start + 1];
        second = a[start];
    } else {
        small = a[start];
        second = a[start + 1];
    }
    for (i = start + 2; i <= end; i++) {
        if (a[i] >= second) {
            continue;
        } else if (a[i] >= small && a[i] < second) {
            second = a[i];
        } else {
            second = small;
            small = a[i];
        }
    }
    return second;
}
int find_second_small(int start, int end)
{
    int small;
    int tmp;
    int i = start;
    small = find_smallest(start, end);
    tmp = a[start] - small;
    while (tmp == 0) {
        tmp = a[++i] - small;
    }
    for (i; i <= end; i++) {
        if (a[i] - small >= tmp) {
            continue;
        } else if (a[i] - small == 0) {
            continue;
        } else {
            tmp = a[i] - small;
        }
    }
    return small + tmp;
}

int main(void)
{
    int small = find_smallest(0, LEN - 1);
    int second = find_second_small(0, LEN - 1);
    int small_second = find_small_second(0, LEN - 1);
    printf("smallest number is %d\n", small);
    printf("second small number is %d\n", second);
    printf("small second number is %d\n", small_second);
    return 0;
}

int partition_bn(int start, int end)
{
    int i, j, cnt;
    int k = end - start + 1;
    int b[k];
    int pivot = a[start];
    j = start;
    cnt = start;
    for (i = start + 1; i <= end; i++) {
        if (a[i] > pivot) {
            k--;
            b[k] = a[i];
        } else {
            b[j++] = a[i];
            cnt++;
        }
    }
    b[cnt - start] = pivot;
    for (i = start; i <= end; i++) {
        a[i] = b[i - start];
    }
    return cnt;
}

