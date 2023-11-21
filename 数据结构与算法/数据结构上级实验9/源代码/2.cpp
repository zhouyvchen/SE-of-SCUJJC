#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

Node* insert(Node *head, int data){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = head;
	return newNode;
}
void Print(Node* current){
	if(current == NULL){
		return;
	}
	printf("%d ", current->data);
	Print(current->next);
}

int main(){
	Node *head = NULL;
	head = insert(head, 1);
	head = insert(head, 2);
	head = insert(head, 3);
	head = insert(head, 4);
	head = insert(head, 5);
	head = insert(head, 6);
	
	printf("节点值为：");
	Print(head);
}


