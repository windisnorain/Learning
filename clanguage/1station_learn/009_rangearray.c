#include <stdio.h>
#define N 3
int a[N] = {1, 2, 3};

void print_reverse(int n) {
    if (n == 0)
	printf("\n");
    else {
	printf("%d ", a[n - 1]);
	print_reverse(n - 1);
    }
}

void print_array(int array[], int n) {
    int i;
    for (i = 0; i < n; i++) {
	printf("%d ", array[i]);
    }
    printf("\n");
}

void swap(int array[], int m, int n) {
    int temp;
    temp = array[n];
    array[n] = array[m];
    array[m] = temp;
}

void recursion(int array[], int p, int n) {
    int i;
    if (p == n)
	print_array(array, n);
    else {
	for (i = p; i < n; i++) {
	    swap(array, p, i);
	    recursion(array, p + 1, n);
	    //			swap(array,p,i);
	}
    }
}

void rangearray(int array[], int p, int n) {
    int i;
    if (p == 0) {
	print_array(array, n);
    } else {
	for (i = p; i >= 0; i--) {
	    swap(array, p, i);
	    rangearray(array, p - 1, n);
	    //			swap(array,p,i);
	}
    }
}

void main() {
    // print_reverse(N);
    rangearray(a, N - 1, N);
    recursion(a, 0, N);
}
