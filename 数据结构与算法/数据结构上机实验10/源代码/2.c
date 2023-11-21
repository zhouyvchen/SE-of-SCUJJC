#include <stdio.h>

#define MAX_ROW 2
#define MAX_COL 5

int paths[MAX_ROW + MAX_COL - 1][MAX_ROW][MAX_COL] = {0};
int pathCount = 0;

void backtrack(int row, int col, int path[MAX_ROW + MAX_COL - 1]) {
    if (row == MAX_ROW - 1 && col == MAX_COL - 1) {
        printf("路径 %d: ", pathCount + 1);
        for (int i = 0; i < row + col; i++) {
            printf("(%d, %d) ", path[i] / MAX_COL + 1, path[i] % MAX_COL + 1);
        }
        printf("\n");
        pathCount++;
        return;
    }

    // 向下移动
    if (row < MAX_ROW - 1) {
        path[row + col] = (row + 1) * MAX_COL + col;
        backtrack(row + 1, col, path);
    }

    // 向右移动
    if (col < MAX_COL - 1) {
        path[row + col] = row * MAX_COL + (col + 1);
        backtrack(row, col + 1, path);
    }
}

int main() {
    int path[MAX_ROW + MAX_COL - 1];
    backtrack(0, 0, path);
    printf("总路径数: %d\n", pathCount);
    return 0;
}
