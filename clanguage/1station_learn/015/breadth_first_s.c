#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5
#define N 5

struct point
{
    int row, col, predecessor;
} queue[N];
int head = 0, tail = 0, isempty = 0, isfull = 0;

void enqueue(struct point p)
{
    if (tail == N) tail = 0;
    queue[tail++] = p;
    if (tail == head || (tail == N && head == 0))
        isfull = 1;
    else
        isfull = 0;
}
struct point dequeue()
{
    if (head == N) head = 0;
    return queue[head++];
    if (head == tail)
        isempty = 1;
    else
        isempty = 0;
}

/**int is_full(void)*/
/**{*/
/**    if (full || (tail == N && head == 0)) return 1;*/
/**}*/
/***/
/**int is_empty(void)*/
/**{*/
/**    return head == tail;*/
/**}*/

int maze[MAX_ROW][MAX_COL] = {0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0,
                              0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, };
void print_maze(void)
{
    int i, j;
    for (i = 0; i < MAX_ROW; i++) {
        for (j = 0; j < MAX_COL; j++) {
            printf("%d ", maze[i][j]);
        }
        putchar('\n');
    }
    printf("*********\n");
}

void visit(int row, int col)
{
    struct point visit_point = {row, col, head - 1};
    maze[row][col] = 2;
    enqueue(visit_point);
}

int main(void)
{
    struct point p = {0, 0, -1};

    maze[p.row][p.col] = 2;
    enqueue(p);

    while (!isempty) {
        p = dequeue();
        if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1) {
            break;
        }
        if (p.col + 1 < MAX_COL && maze[p.row][p.col + 1] == 0) {
            if (isfull) {

                printf("Queue[%d] is full!\n", N);
                break;
            } else
                visit(p.row, p.col + 1);
        }
        if (p.row + 1 < MAX_ROW && maze[p.row + 1][p.col] == 0) {
            if (isfull) {

                printf("Queue[%d] is full!\n", N);
                break;
            } else
                visit(p.row + 1, p.col);
        }
        if (p.col - 1 >= 0 && maze[p.row][p.col - 1] == 0) {
            if (isfull) {

                printf("Queue[%d] is full!\n", N);
                break;
            } else
                visit(p.row, p.col - 1);
        }
        if (p.row - 1 >= 0 && maze[p.row - 1][p.col] == 0) {
            if (isfull) {

                printf("Queue[%d] is full!\n", N);
                break;
            } else
                visit(p.row - 1, p.col);
        }
        print_maze();
    }

    if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1) {
        printf("Have path!\n");
    } else
        printf("No path!\n");
    /***/
    return 0;
}
