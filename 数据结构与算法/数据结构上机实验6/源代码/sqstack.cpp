#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
	int data[MAX_SIZE];
	int top;
} Stack;

void initStack(Stack *stack) {
	stack->top = -1;
}

int isEmpty(Stack *stack) {
	return stack->top == -1;
}

int isFull(Stack *stack) {
	return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, int value) {
	if (isFull(stack)) {
		printf("栈已满\n");
		return;
	}
	
	stack->top++;
	stack->data[stack->top] = value;
}

int pop(Stack *stack) {
	if (isEmpty(stack)) {
		printf("栈为空\n");
		return -1;
	}
	
	int value = stack->data[stack->top];
	stack->top--;
	return value;
}

int peek(Stack *stack) {
	if (isEmpty(stack)) {
		printf("栈为空\n");
		return -1;
	}
	
	return stack->data[stack->top];
}

void printStack(Stack *stack) {
	if (isEmpty(stack)) {
		printf("栈为空。\n");
		return;
	}
	
	printf("栈内容：");
	for (int i = 0; i <= stack->top; i++) {
		printf("%c ", stack->data[i]);
	}
	printf("\n");
}

void sortStack(Stack *originalStack) {
	Stack tempStack;
	initStack(&tempStack);
	
	while (!isEmpty(originalStack)) {
		int temp = pop(originalStack);
		
		while (!isEmpty(&tempStack) && peek(&tempStack) > temp) {
			int popped = pop(&tempStack);
			push(originalStack, popped);
			printf("将 %c 从临时栈移回原始栈。\n", popped);
		}
		
		push(&tempStack, temp);
		printf("将 %c 从原始栈移入临时栈。\n", temp);
	}
	
	// 将临时栈的元素移回原始栈
	while (!isEmpty(&tempStack)) {
		int temp = pop(&tempStack);
		push(originalStack, temp);
		printf("将 %c 从临时栈移回原始栈。\n", temp);
	}
}


