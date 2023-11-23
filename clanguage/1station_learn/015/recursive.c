#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5
int s = 0, t = 0;

struct point
{
    int row, col, predecessor;
} step[MAX_ROW * MAX_COL];

struct point goal;

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

struct point visit(int row, int col, struct point pre)
{
    step[s++] = pre;
    struct point p = {row, col, s - 1};
    maze[row][col] = 2;
    if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1) {
        t = s - 1;
        goal = p;
        return;
    }
    /** down   */
    if (p.row + 1 < MAX_ROW && maze[p.row + 1][p.col] == 0) {
        visit(p.row + 1, p.col, p);
    }
    /** left   */
    if (p.col - 1 >= 0 && maze[p.row][p.col - 1] == 0) {
        visit(p.row, p.col - 1, p);
    }
    /** up   */
    if (p.row - 1 >= 0 && maze[p.row - 1][p.col] == 0) {
        visit(p.row - 1, p.col, p);
    }
    /** right   */
    if (p.col + 1 < MAX_COL && maze[p.row][p.col + 1] == 0) {
        visit(p.row, p.col + 1, p);
    }
    return;
}

int main(void)
{
    struct point p = {0, 0, 0};
    visit(0, 0, p);
    print_maze();
    p = goal;
    if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1) {
        printf("(%d, %d, %d)\n", p.row, p.col, p.predecessor);
        while (p.predecessor != 0) {
            p = step[p.predecessor];
            printf("(%d, %d, %d)\n", p.row, p.col, p.predecessor);
        }
    } else
        printf("No path!\n");
    return 0;
}
