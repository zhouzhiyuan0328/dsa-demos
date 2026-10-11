#include<stdio.h>
#include<stdlib.h>

struct Node {		//定义节点
	int val;
	struct Node* next;
};

//创建链表
struct Node* create_list(int arr[], int n) {

	//定义头尾两个指针，不具有等同于节点的数据结构
	struct Node* head = NULL;
	struct Node* tail = NULL;

	for (int i = 0; i < n; i++) {		//循环创建相应数量的节点
		struct Node* node = malloc(sizeof(struct Node));		//创建地址
		node->val = arr[i];		//依据数组值依次赋值
		node->next = NULL;		//清空下个节点指针的值或者说表示没有

		//根据是否有head地址开始真正意义的创建链表
		if (head == NULL) {

			//若头指针不存在则把head和tail都指向当前生成的node
			head = node;		//第一个节点，头尾都指向它
			tail = node;
		}
		else {

			//头节点已存在则通过tail访问下一节点并指向新建节点
			tail->next = node;

			//同时更新tail指针的位置，指向新建的节点也就是最后一个节点
			tail = node;
		}
	}
	//返还头地址
	return head;
}


//尾插节点
//从链表尾部插入一个节点存储数据
struct Node* append(struct Node* head, int val) {		//输入链表的head和要输入的数据
	struct Node* node = malloc(sizeof(struct Node));		//创建节点
	node->val = val;		//存储数据
	node->next = NULL;		//清空节点地址

	//判断head是否存在，不存在就返还节点
	if (head == NULL) {
		return node;
	}

	//定义一个节点类型的指针从head开始找到最后一个节点
	struct Node* p = head;
	while (p->next != NULL) {
		p = p->next;
	}

	//找到最后一个节点后插入链表中并返还head
	p->next = node;
	return head;
}

//输出链表里面的内容
void print_list(struct Node* head) {

	//定义一个节点类型的地址接收head，通过遍历输出链表中的数据
	struct Node* p = head;
	while (p != NULL) {
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n");
}

//清空链表
struct Node* clear_Llist(struct Node* head) {
	struct Node* p = head;
	while (p != NULL) {
		struct Node* next = p->next;
		free(p);
		p = next;
	}
	return NULL;
}

//删除节点
//给出一个val的值找到第一个val值相同的节点并删除
struct Node* delete_node(struct Node* head, int val) {
	//如果head为空 
	if (head == NULL)
		return NULL;
	//如果头节点的值就是val
	if (head->val == val) {
		struct Node* next = head->next;
		free(head);
		return next;
	}
	//如果中间值是val
	struct Node* pre = head;
	while (pre->next != NULL && pre->next->val != val) {
		pre = pre->next;
	}
	//找到了
	if (pre->next != NULL) {
		struct Node* temp = pre->next;
		pre->next = temp->next;
		free(temp);
	}
	return head;
}

//反转链表
struct Node* reverse_list(struct Node* head) {
	struct Node* prev = NULL;
	struct Node* curr = head;
	struct Node* next;
	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}
int main(void) {
	int arr[] = { 1,2,3,8 };
	struct Node* head = create_list(arr, 4);
	printf("创建初始列表");
	print_list(head);
	printf("测试尾插函数");
	head = append(head, 12);
	print_list(head);
	printf("测试删除节点");
	head = delete_node(head, 99);
	print_list(head);
	printf("测试反转链表");
	head = reverse_list(head);
	print_list(head);
	head = clear_Llist(head);
	print_list(head);
	return 0;
}