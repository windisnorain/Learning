#include <stdio.h>
#include <stdlib.h>
#define N 20

int a[N];
int count[9];

void gen_random(int upper_bound) {
    int i, j;
    for (i = 0; i < N; i++) {
	a[i] = rand() % upper_bound;
	count[a[i]] += 1;
    }
}

void print_random() {
    int i;
    for (i = 0; i < N; i++) printf("%d ", a[i]);
    printf("\n");
}

void print_count() {
    int i;
    for (i = 0; i <= 9; i++) {
	printf("%d : %d\n", i + 10, count[i]);
    }
}
//打印直方图
void print_histogram(char ch) {
    int i, j;
    int k;
    for (i = 0; i <= 9; i++) {
	printf("%d\t", i);
    }
    printf("\n\n");
    do {
	k = 0;
	for (j = 0; j <= 9; j++) {
	    if (count[j] > 0) {
		printf("%c\t", ch);
		count[j] -= 1;
	    } else
		printf(" \t");
	}
	printf("\n");
	for (i = 0; i <= 9; i++) {
	    if (count[i] > 0) {
		k = 1;
		break;
	    } else
		continue;
	}
    } while (k);
}

int main(void) {
    gen_random(10);
    //	print_random();
    //	print_count();
    print_histogram('*');
    return 0;
}
