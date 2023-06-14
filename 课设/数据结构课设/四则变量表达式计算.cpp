#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 100  //���Ա����洢������������ʽ�ĳ���

//����������Ϣ�ṹ��
typedef struct
{
	char name;//���ַ�������
	int value;//��Ӧ��ֵ
} Var;

//ջ�Ľṹ
typedef struct
{
	char *elem;
	int top; //ջ��
} SeqStack;

//Ԫ�ع��ɵ����Ա��Լ�������Ϣ
typedef struct
{
	Var *arrayList ; //���Ա�
	int count ; //���Ա���Ԫ�صĸ���
	char *ex;//������ʽ������ʽ-��׺���ʽ
	char *backEx;//��׺���ʽ
	int sum;//������ʽ�Ľ��
	SeqStack *stack;
} List;



//��ʼ�����Ա��������ݵ�����
void init(List *list);

//��ʾ������Ϣ�Լ�������ʽ���
void print(List  *list);

//�ҵ����ַ����������Ӧ����ֵ
int find(char name, List *list);

//�ж��Ƿ�Ϊ�����
bool isOperator(char ch);

//�ж��Ƿ�Ϊ���ַ�����������
bool isChar(char ch) ;

//����
int calculate(int front, int top, char operators);

//��ջ
void push( char ch, List *list) ;

//��ջ
char pop(List *list) ;

//��ȡջ��Ԫ��
char getTop(List *list) ;

//�ж�ջ�Ƿ�Ϊ��
bool isEmpty(List *list) ;

//�ж�ջ�Ƿ�Ϊ��
bool isFull(List *list) ;
//�ж����ȼ�
int getPriority(char ex) ;

//��׺���ʽת��Ϊ��׺���ʽ
void transform(List *list) ;

//�������ս��
void result(List *list);

int main()
{
	List *list = (List *)malloc(sizeof(List));
	init(list);
	transform(list);
	result(list);
	print(list);
}

void result(List *list)
{
	int temp[MAXN];
	int last = -1;
	char *str = list->backEx;
	int length = strlen(str);
	for (int i = 0; i < length; i++ )
		{
			if (isChar(str[i]))
				temp[++last] = find(str[i], list);
			else if (isOperator(str[i]))
				{
					int top = temp[last--];
					int front = temp[last--];
					int res = calculate(front, top, str[i]);
					temp[++last] = res;
				}
		}
	list->sum = temp[last];
}

void transform(List *list)
{
	char *str = list->ex;
	char *backex = list->backEx ;
	int count = 0;
	int length = strlen(str);
	for (int i = 0; i < length; i++)
		{
			if (isChar(str[i]))
				backex[count++] = str[i];
			else if (str[i] == '(')
				push(str[i], list );
			else if (isOperator(str[i]))
				{
					if (isEmpty(list))
						push(str[i], list);
					else
						{
							char top = getTop(list);
							int topPriority = getPriority(top);
							int curPriority = getPriority(str[i]);
							if (topPriority > curPriority)
								{
									pop(list);
									backex[count++] = top;
								}
							else
								push(str[i], list);
						}
				}
			else	if (str[i] == ')')
				{
					while (true)
						{
							char	top = pop(list);
							if (top == '(')
								break;
							else
								backex[count++] = top;

						}
				}
		}
	while (!isEmpty(list))
		{
			char top = pop(list);
			backex[count++] = top;
		}
}

bool isOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		return true;
	else
		return false;
}

bool isChar(char ch)
{
	if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
		return true;
	else
		return false;
}

void init(List *list)
{

	//��ʼ��list
	list->arrayList = (Var *)malloc(sizeof(Var) * MAXN);
	list->count = 0;
	list->sum = 0;
	list->ex = (char *)malloc(sizeof(char) * MAXN);
	list->backEx = (char *)malloc(sizeof(char) * MAXN);
	list->stack = (SeqStack *)malloc(sizeof(SeqStack));
	//��ʼ��ջ
	list->stack->elem = (char *)malloc(sizeof(char) * MAXN);
	list->stack->top = -1;

	//������ݵ�����
	printf("������һ�鵥�ַ������������Ӧ��ֵ�������Ա�,���ַ�������Ϊ��=����ʾ��������\n");
	while (true)
		{
			fflush(stdin);
			char name;
			printf("�����뵥�ַ���������");
			scanf("%c", &name);
			list->arrayList[list->count].name = name;
			if (name == '=')
				break;
			int value;
			printf("���������Ӧ��ֵ: ");
			scanf("%d", &value);
			list->arrayList[list->count].value = value;
			list->count++;
		}
	fflush(stdin);
	printf("����������������ʽ��\n");
	scanf("%s", list->ex);

}

void print(List  *list)
{
	printf("%���Ա���Ԫ���ܸ���Ϊ��%d\n", (list)->count );
	if (list->count == 0)
		return ;
	for (int i = 0; i < list->count ; i++)
		{
			printf("%c=%d", list->arrayList[i].name, list->arrayList[i].value);
			if (i < list->count - 1)
				printf(",");
		}
	printf("\n");
	printf("�����%s=%d", list->ex, list->sum);
}

int find(char name, List *list)
{
	for (int i = 0; i < list->count; i++)
		{
			if (name == list->arrayList[i].name)
				return list->arrayList[i].value;
		}
	return -1;//δ�ҵ�
}

int getPriority(char ex)
{
	int priority = 0;
	switch (priority)
		{
			case '+':
			case '-':
				priority = 1;
				break;
			case '*':
			case '/':
				priority = 2;
				break;
			default:
				break;
		}
	return priority;
}

int calculate(int front, int top, char operators)
{
	int res = 0;
	switch (operators)
		{
			case '+':
				res = front + top;
				break;
			case '-':
				res = front - top;
				break;
			case '*':
				res = front * top;
				break;
			case '/':
				res = front / top;
				break;
			default:
				printf("������ַ����Ϸ�\n");
				exit(0);
		}
	return res;
}

bool isFull(List *list)
{
	return list->stack->top == MAXN - 1;
}

//��ջ
void push( char ch, List *list)
{
	if (isFull(list))
		{
			printf("��ջʧ�ܣ�ջ����\n");
			exit(0);
		}

	list->stack->top++;
	list->stack->elem[list->stack->top] = ch;
}

//��ջ
char pop(List *list)
{
	if (isEmpty(list))
		{
			printf("��ջʧ�ܣ�ջΪ��\n");
			exit(0);
		}
	char ch = list->stack->elem[list->stack->top];
	list->stack->top--;
	return ch;

}

//��ȡջ��Ԫ��
char getTop(List *list)
{
	return list->stack->elem[list->stack->top];
}

//�ж�ջ�Ƿ�Ϊ��
bool isEmpty(List *list)
{
	return	list->stack->top == -1;
}