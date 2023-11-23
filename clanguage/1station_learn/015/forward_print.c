#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5
int s = 0;

struct point
{
    int row, col;
} stack[512];
int top = 0;

void push(struct point p)
{
    stack[top++] = p;
}
struct point pop()
{
    return stack[--top];
}

int is_empty(void)
{
    return top == 0;
}

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

struct point predecessor[MAX_ROW][MAX_COL] = {
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}},
    {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}}, };

struct point step[MAX_ROW * MAX_COL];

void visit(int row, int col, struct point pre)
{
    struct point visit_point = {row, col};
    maze[row][col] = 2;
    predecessor[row][col] = pre;
    push(visit_point);
}

int main(void)
{
    struct point p = {0, 0};
    int i = 0;

    maze[p.row][p.col] = 2;
    push(p);
    /**print_maze();*/
    while (!is_empty()) {
        p = pop();
        if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1) {
            break;
        }
        if (p.col + 1 < MAX_COL && maze[p.row][p.col + 1] == 0) {
            visit(p.row, p.col + 1, p);
        }
        if (p.row + 1 < MAX_ROW && maze[p.row + 1][p.col] == 0) {
            visit(p.row + 1, p.col, p);
        }
        if (p.col - 1 >= 0 && maze[p.row][p.col - 1] == 0) {
            visit(p.row, p.col - 1, p);
        }
        if (p.row - 1 >= 0 && maze[p.row - 1][p.col] == 0) {
            visit(p.row - 1, p.col, p);
        }
        print_maze();
    }

    if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1) {
        /**forward store the steps in struct array step[].*/
        step[i] = p;
        while (predecessor[step[i].row][step[i].col].row != -1) {
            step[++i] = predecessor[step[i - 1].row][step[i - 1].col];
        }
        /**backward print out step[].*/
        while (i >= 0) {
            printf("(%d, %d)\n", step[i].row, step[i].col);
            i--;
        }
    } else
        printf("No path!\n");

    return 0;
}
