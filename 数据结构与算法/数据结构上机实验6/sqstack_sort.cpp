#include "sqstack.cpp"

int main() {
	Stack stack;
	initStack(&stack);
	
	// 初始时进栈元素依次是a, c, d, b
	push(&stack, 'a');
	push(&stack, 'c');
	push(&stack, 'd');
	push(&stack, 'b');
	
	printf("初始栈为：\n");
	printStack(&stack);
	
	printf("排序中：\n");
	sortStack(&stack);
	
	printf("排序后：\n");
	printStack(&stack);
	
	return 0;
}