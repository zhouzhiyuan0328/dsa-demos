#include <stdio.h>
#include <stdlib.h>
/*这里写的是带表头节点的链表的一些基本知识及函数实现*/
//定义Node的结构
typedef struct Node {
	int val;
	struct Node* next;
}Node;

//创建带表头节点的链表
/*思路：先创建一个空节点，然后再通过for循环对链表里面的val进行逐一赋值，通过指针tail将空节点head与正常节点相连*/
Node* create_list(int arr[], int n){
	Node* head = malloc(sizeof(Node));
	Node* tail = head;
	for (int i = 0;i < n;i++) {
		Node* node = malloc(sizeof(Node));
		//先给节点赋值
		node->val = arr[i];
		//清空节点的指向
		node->next = NULL;
		//将当前tail与创建的节点相连
		tail->next = node;
		//更新tail的位置，把tail置于最后一个节点，也就是当前创建的node
		tail = node;
	}
	return head;
}

//输出链表里面的值
Node* print_list(Node* head){
	Node* node = head->next;
	while (node != NULL){
		printf("%d",node->val);
		node = node->next;
		printf("\n");
	}
	return head;
}

int main(void) { 
	int arr[] = {1,2,3,4,5,8};
	Node* head = create_list(arr,6);
	print_list(head);
	return 0; 
}
