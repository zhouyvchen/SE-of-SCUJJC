#include <stdio.h>

void hanoi(int n, char source, char target, char auxiliary) {
    if (n > 0) {
        hanoi(n - 1, source, auxiliary, target);
        printf("将圆盘 %d 从柱子 %c 移动到柱子 %c\n", n, source, target);
        hanoi(n - 1, auxiliary, target, source);
    }
}

int main() {
    int n;
    printf("输入圆盘数量n:");
    scanf("%d", &n);
    hanoi(n, 'A', 'C', 'B');  // A、B、C 分别表示柱子A、B、C

    return 0;
}
