#include <stdio.h>
#include <stdlib.h>

// 链表节点
struct LinkList {
    char data;
    struct LinkList* next;
};

// 初始化链表
void initList(struct LinkList** L) {
    *L = (struct LinkList*)malloc(sizeof(struct LinkList));
    (*L)->next = NULL;
}

// 头插法创建链表
void createListHead(struct LinkList** L) {
    char ch;
    initList(L);
    printf("请输入链表的元素（以#结束）：");
    getchar();  // 吸收换行符
    ch = getchar();
    while (ch != '#') {
        struct LinkList* newNode =
            (struct LinkList*)malloc(sizeof(struct LinkList));
        newNode->data = ch;
        newNode->next = (*L)->next;
        (*L)->next = newNode;
        ch = getchar();
    }
}

// 在链表中插入元素
void insertElem(struct LinkList* L, int pos, char elem) {
    struct LinkList* p = L;
    int i = 0;
    while (p && i < pos - 1) {
        p = p->next;
        i++;
    }
    if (!p || i > pos - 1) {
        printf("插入位置无效\n");
        return;
    }
    struct LinkList* newNode =
        (struct LinkList*)malloc(sizeof(struct LinkList));
    newNode->data = elem;
    newNode->next = p->next;
    p->next = newNode;
}

// 删除链表中的元素
void deleteElem(struct LinkList* L, int pos) {
    struct LinkList* p = L;
    int i = 0;
    while (p->next && i < pos - 1) {
        p = p->next;
        i++;
    }
    if (!(p->next) || i > pos - 1) {
        printf("删除位置无效\n");
        return;
    }
    struct LinkList* q = p->next;
    p->next = q->next;
    free(q);
}

// 查找某一元素的位置
int findElem(struct LinkList* L, char elem) {
    struct LinkList* p = L->next;
    int pos = 1;
    while (p) {
        if (p->data == elem) {
            return pos;
        }
        p = p->next;
        pos++;
    }
    return -1;  // 未找到元素
}

// 获取某一位置的元素
char getElem(struct LinkList* L, int pos) {
    struct LinkList* p = L->next;
    int i = 1;
    while (p && i < pos) {
        p = p->next;
        i++;
    }
    if (!p || i > pos) {
        printf("位置无效\n");
        return '\0';
    }
    return p->data;
}

// 获取链表的长度
int getListLength(struct LinkList* L) {
    struct LinkList* p = L->next;
    int length = 0;
    while (p) {
        length++;
        p = p->next;
    }
    return length;
}

// 销毁链表
void destroyList(struct LinkList** L) {
    struct LinkList* p = *L;
    while (p) {
        struct LinkList* q = p;
        p = p->next;
        free(q);
    }
    *L = NULL;
}

// 判断链表是否为空
int isEmpty(struct LinkList* L) {
    return L->next == NULL;
}

// 输出链表的元素
void printList(struct LinkList* L) {
    struct LinkList* p = L->next;
    while (p) {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    struct LinkList* L;
    createListHead(&L);
    printf("链表的元素为：");
    printList(L);

    int length = getListLength(L);
    printf("链表的长度为：%d\n", length);

    printf("请输入要插入的元素和位置：");
    char elem;
    int pos;
    scanf(" %c %d", &elem, &pos);
    insertElem(L, pos, elem);
    printf("插入后的链表为：");
    printList(L);

    printf("请输入要删除的位置：");
    scanf("%d", &pos);
    deleteElem(L, pos);
    printf("删除后的链表为：");
    printList(L);

    printf("请输入要查找的元素：");
    scanf(" %c", &elem);
    int findPos = findElem(L, elem);
    if (findPos != -1) {
        printf("元素%c的位置为：%d\n", elem, findPos);
    } else {
        printf("未找到元素%c\n", elem);
    }

    printf("请输入要获取元素的位置：");
    scanf("%d", &pos);
    char getElemResult = getElem(L, pos);
    if (getElemResult != '\0') {
        printf("位置%d的元素为：%c\n", pos, getElemResult);
    }

    destroyList(&L);
    if (isEmpty(L)) {
        printf("链表已销毁\n");
    }

    return 0;
}