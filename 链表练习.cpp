//����ʽ��������
#include <iostream>
using namespace std;

typedef struct node {
	int coefficient;
	int index;
	node *next;
} node;
node *polScanf();
void attach(int coefficent, int index, node **rear);
node *polAdd(node **p1, node **p2);
void polPrintf(node **head);

int main() {
//	1.������  ����Ҫ�����ݽṹ +����
	node *p1, *p2, *add, * mul;
	//����ʽ������
	p1 = polScanf();
	p2 = polScanf();
	//����ʽ���
	add = polAdd(&p1, &p2);
	//���
//	polPrintf(&add);
	//����ʽ���
//	mul=polMultiply(p1,p2);
	//���
//	polPrintf(mul);
}

node *polScanf() {
	int N;
	int coefficent, index;
	scanf("%d", &N);
	node *head, *rear, *temp;
	head = (node *)malloc(sizeof(node));
	rear = head;
	while (N--) {
		scanf("%d%d", &coefficent, &index);
		attach(coefficent, index, &rear);
	}
	rear->next = NULL;
	temp = head;
	head = head->next;
	free(temp);
	return head;
}
void attach(int coefficent, int index, node **rear) {
	node *p = (node *)malloc(sizeof(node));
	p->coefficient = coefficent;
	p->index = index;
	(*rear)->next = p;
	(*rear) = p;
}
node *polAdd(node **p1, node **p2) {
	node *head = (node *)malloc(sizeof(node)), *rear, *temp;
	rear = head;
	node *one = *p1;
	node *two = *p2;
	while (one && two) {

		if (one->index == two->index) {
			int sum = one->coefficient + two->coefficient;
			attach(one->coefficient, sum, &head);
			one = one->next;
			two = two->next;

		} else if (one->index > two->index) {
			rear->next = one;
			rear = one;
			one = one->next;

		} else {
			rear->next = two;
			rear = two;
			two = two->next;
		}
	}
	while (one) {
		rear->next = one;
		rear = one;
		one = one->next;
	}
	while (two) {
		rear->next = two;
		rear = two;
		two = two->next;
	}
	rear->next = NULL;
	temp = head;
	head = head->next;
	free(temp);
	while (head) {
		printf("%d %d", (head)->coefficient,  (head)->index);
		head = (head)->next;
	}
	return head;
}
void polPrintf(node **head) {
	node *p = *head;
	while (*head) {
		printf("%d %d", (*head)->coefficient,  (*head)->index);
		*head = (*head)->next;
	}
}