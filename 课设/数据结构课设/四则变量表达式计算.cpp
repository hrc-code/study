#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 100  //线性表最大存储数量和四则表达式的长度

//存变量相关信息结构体
typedef struct
{
	char name;//单字符变量名
	int value;//对应数值
} Var;

//栈的结构
typedef struct
{
	char *elem;
	int top; //栈顶
} SeqStack;

//元素构成的线性表以及其他信息
typedef struct
{
	Var *arrayList ; //线性表
	int count ; //线性表中元素的个数
	char *ex;//四则表达式运算表达式-中缀表达式
	char *backEx;//后缀表达式
	int sum;//四则表达式的结果
	SeqStack *stack;
} List;



//初始化线性表和相关数据的输入
void init(List *list);

//显示变量信息以及四则表达式结果
void print(List  *list);

//找到单字符变量名其对应的数值
int find(char name, List *list);

//判断是否为运算符
bool isOperator(char ch);

//判断是否为单字符变量和数字
bool isChar(char ch) ;

//计算
int calculate(int front, int top, char operators);

//进栈
void push( char ch, List *list) ;

//出栈
char pop(List *list) ;

//获取栈顶元素
char getTop(List *list) ;

//判断栈是否为空
bool isEmpty(List *list) ;

//判断栈是否为满
bool isFull(List *list) ;
//判断优先级
int getPriority(char ex) ;

//中缀表达式转换为后缀表达式
void transform(List *list) ;

//计算最终结果
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

	//初始化list
	list->arrayList = (Var *)malloc(sizeof(Var) * MAXN);
	list->count = 0;
	list->sum = 0;
	list->ex = (char *)malloc(sizeof(char) * MAXN);
	list->backEx = (char *)malloc(sizeof(char) * MAXN);
	list->stack = (SeqStack *)malloc(sizeof(SeqStack));
	//初始化栈
	list->stack->elem = (char *)malloc(sizeof(char) * MAXN);
	list->stack->top = -1;

	//相关数据的输入
	printf("请输入一组单字符变量名及其对应数值存入线性表,单字符变量名为‘=’表示结束输入\n");
	while (true)
		{
			fflush(stdin);
			char name;
			printf("请输入单字符变量名：");
			scanf("%c", &name);
			list->arrayList[list->count].name = name;
			if (name == '=')
				break;
			int value;
			printf("请输入其对应数值: ");
			scanf("%d", &value);
			list->arrayList[list->count].value = value;
			list->count++;
		}
	fflush(stdin);
	printf("请输入四则运算表达式：\n");
	scanf("%s", list->ex);

}

void print(List  *list)
{
	printf("%线性表中元素总个数为：%d\n", (list)->count );
	if (list->count == 0)
		return ;
	for (int i = 0; i < list->count ; i++)
		{
			printf("%c=%d", list->arrayList[i].name, list->arrayList[i].value);
			if (i < list->count - 1)
				printf(",");
		}
	printf("\n");
	printf("结果：%s=%d", list->ex, list->sum);
}

int find(char name, List *list)
{
	for (int i = 0; i < list->count; i++)
		{
			if (name == list->arrayList[i].name)
				return list->arrayList[i].value;
		}
	return -1;//未找到
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
				printf("输入的字符不合法\n");
				exit(0);
		}
	return res;
}

bool isFull(List *list)
{
	return list->stack->top == MAXN - 1;
}

//进栈
void push( char ch, List *list)
{
	if (isFull(list))
		{
			printf("进栈失败，栈已满\n");
			exit(0);
		}

	list->stack->top++;
	list->stack->elem[list->stack->top] = ch;
}

//出栈
char pop(List *list)
{
	if (isEmpty(list))
		{
			printf("出栈失败，栈为空\n");
			exit(0);
		}
	char ch = list->stack->elem[list->stack->top];
	list->stack->top--;
	return ch;

}

//获取栈顶元素
char getTop(List *list)
{
	return list->stack->elem[list->stack->top];
}

//判断栈是否为空
bool isEmpty(List *list)
{
	return	list->stack->top == -1;
}