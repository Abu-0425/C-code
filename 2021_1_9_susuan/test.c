#define N 20
#define COL 100
#define ROW 40
#include "stdio.h"
#include "time.h" /*ϵͳʱ�亯��*/
#include "graphics.h "/*ͼ�κ���*/
#include "alloc.h"/*��̬��ַ���亯��*/
#include "stdlib.h" /*�⺯��*/
#include "string.h" /*�ַ�������*/
#include "ctype.h" /*�ַ���������*/
char p[4][13] = {
	{ 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K' },/*�˿��ƣ�10��0����ʾ*/
	{ 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K' },
	{ 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K' },
	{ 'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'J', 'Q', 'K' } };
typedef struct node
{
	int data;
	struct node* link;
}STACK1; /*ջ1*/
typedef struct node2
{
	char data;
	struct node2* link;
}STACK2; /*ջ2*/
void init(void);/*ͼ������*/
void close(void);/*ͼ�ιر�*/
void play(void);/*���Ƶľ������*/
void rand1(int j);/*������ƺ���*/
void change(char* e, char* a);  /*��׺���׺����*/
int computer(char* s);  /*��׺����ʽ���㺯��*/
STACK1* initstack1(STACK1* top);   /*ջ1��ʼ��*/
STACK1* push(STACK1* top, int x); /*ջ1��ջ����*/
STACK1* pop(STACK1* top); /*ջ1ɾ��ջ��Ԫ��*/
int topx(STACK1* top); /*ջ1��ջ��Ԫ��*/
STACK1* ptop(STACK1* top, int* x); /*ջ1����ջ��Ԫ��ֵ��ɾ��ջ��Ԫ��*/
int empty(STACK1* top); /*��ջ1�Ƿ�Ϊ�պ���*/
STACK2* initstack2(STACK2* top); /*ջ2��ʼ��*/
STACK2* push2(STACK2* top, char x); /*ջ2��ջ����*/
STACK2* pop2(STACK2* top); /*ջ2ɾ��ջ��Ԫ��*/
char topx2(STACK2* top); /*ջ2��ջ��Ԫ��*/
STACK2* ptop2(STACK2* top, char* x); /*ջ2����ջ��Ԫ��ֵ��ɾ��ջ��Ԫ��*/
int empty2(STACK2* top); /*��ջ2�Ƿ�Ϊ�պ���*
						 int text1(char *s) ; /*��ʾ�ı�*/
main()
{
	char s[N], s1[N], ch;
	int i, result;
	int gdriver, gmode;
	clrscr(); /*����*/
	init(); /*��ʼ������*/
	while (1)
	{
		setbkcolor(BLACK); /*���ñ�����ɫ*/
		cleardevice();/*����*/
		play();  /*����*/
		gotoxy(1, 15); /*�ƶ����*/
		printf("--------------------Note-------------------\n");
		printf("  Please enter express accroding to above four number\n"); /*��ʾ��Ϣ*/
		printf("  Format as follows:2.*(5.+7.)\n");/*��ʾ�����ַ�����ʽ*/
		printf(" ----------------------------------------------\n");
		scanf("%s%c", s1, &ch); /*�����ַ���ѹ�س���*/
		change(s1, s); /*����change��������׺����ʽs1ת��Ϊ��׺����ʽs*/
		result = computer(s); /*�����׺����ʽ��ֵ�����ؽ��result */
		if (result == 24) /*����������24*/
			text1("very good"); /*���ú���text1��ʾ�ַ���"very good"*/
		else
			text1("wrong!!!");/*������text1��ʾ�ַ���"wrong!!!"*/
		printf("Continue (y/n)?\n"); /*��ʾ��Ϣ���Ƿ����*/
		scanf("%c", &ch); /*����һ�ַ�*/
		if (ch == 'n' || ch == 'N') /*������ַ�����n��N*/
			break;   /*����ѭ�����������*/
	} /*���򣬿�ʼ��һ��ѭ��*/
	close();
	return; /*����*/
}
void rand1(int j)/*������ƺ���*/
{
	int kind, num;
	char str[3], n;
	randomize();
	while (1)/*ѭ��ֱ�����Ʒ�*/
	{
		kind = random(4); /*��ɫ�����*/
		num = random(13); /*��С�����*/
		if (p[kind][num] != -1) /*����δȡ��*/
		{
			n = p[kind][num]; /*ȡ��Ӧλ�õ��˿�����*/
			p[kind][num] = -1; /*�Ʒ����Ժ���Ӧλ�õ�Ԫ����-1*/
			break;
		}
	}
	switch (kind)/*��ʽ���ж�*/
	{
	case 0:setcolor(RED); sprintf(str, "%c", 3); break; /*����*/
	case 1:setcolor(BLACK); sprintf(str, "%c", 3); break; /*����*/
	case 2:setcolor(RED); sprintf(str, "%c", 4); break; /*��Ƭ*/
	case 3:setcolor(BLACK); sprintf(str, "%c", 5); break; /*�ݻ�*/
	}
	settextstyle(0, 0, 2);
	outtextxy(COL + j * 100 - 30, ROW + 100 - 46, str);/*��ʾ���Ͻǻ�ɫ*/
	outtextxy(COL + j * 100 + 16, ROW + 100 + 32, str); /*��ʾ���½ǻ�ɫ*/
	if (n != '0')/*���������*/
	{
		settextstyle(0, 0, 3);
		sprintf(str, "%c", n);
		outtextxy(COL + j * 100 - 5, ROW + 100 - 5, str);/*��ʾ�ƵĴ�С*/
	}
	else/*���10��ʱ��*/
	{
		sprintf(str, "%d", 10);
		outtextxy(COL + j * 100 - 6, ROW + 100 - 5, str);
	}
}
void play(void)/*���Ƶľ������*/
{
	int j;
	for (j = 0; j < 4; j++)
	{
		bar(COL + j * 100 - 35, ROW + 100 - 50, COL + j * 100 + 35, ROW + 1 * 100 + 50);/*������*/
		setcolor(BLUE);
		rectangle(COL + j * 100 - 32, ROW + 100 - 48, COL + j * 100 + 32, ROW + 100 + 48);  /*�����ο�*/
		rand1(j); /*���ȡ��*/
		delay(10000); /*��ʱ��ʾ*/
	}
}
void init(void)/*ͼ������*/
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "c:\\tc");
	cleardevice();
}
void close(void)/*ͼ�ιر�*/
{
	closegraph();
}
void change(char* e, char* a) /*��׺�ַ���eת��׺�ַ���a����*/
{
	STACK2* top = NULL; /* ����ջ��ָ��*/
	int i, j; char w;
	i = 0;
	j = 0;
	while (e[i] != '\0') /*���ַ���û�н���ʱ*/
	{
		if (isdigit(e[i])) /*����ַ�������*/
		{
			do {
				a[j] = e[i];  /*������ԭ������������a��*/
				i++;   /*e������±��1*/
				j++;  /*a������±��1*/
			} while (e[i] != '.'); /*ֱ���ַ�Ϊ���ֽ�������.��Ϊֹ*/
			a[j] = '.'; j++; /*�����ֽ�������.��������a������Ȼ���ֽ������*/
		}
		if (e[i] == '(')  /*����ַ��ǡ�(��ʱ*/
			top = push2(top, e[i]); /*����ѹ���ջ*/
		if (e[i] == ')')  /*����ַ��ǡ�)��ʱ*/
		{
			top = ptop2(top, &w); /*ȡ��ջ��Ԫ�أ�����ջ��ɾ����Ԫ��*/
			while (w != '(')  /*����ַ����ǡ�(��ʱ����ѭ��*/
			{
				a[j] = w;  /*��ջ��Ԫ�ش���a����*/
				j++;  /*�±��1*/
				top = ptop2(top, &w); /*ȡ��ջ��Ԫ�أ�����ջ��ɾ����Ԫ��*/
			}
		}
		if (e[i] == '+' || e[i] == '-') /*����ַ��Ǽӻ����ʱ*/
		{
			if (!empty2(top))  /*��ջ��Ϊ��*/
			{
				w = topx2(top);
				while (w != '(') /*��ջ��Ԫ�ز��ǡ�(��ʱ����ѭ��*/
				{
					a[j] = w;
					j++; /*��ջ��Ԫ�ش������ʽa�У�a���±��1*/
					top = pop2(top); /*ɾ��ջ��Ԫ��*/
					if (empty2(top)) /*���ջΪ��*/
						break; /*����ѭ��*/
					else
						w = topx2(top); /*�����ջ��Ԫ��*/
				}
			}
			top = push2(top, e[i]); /*����ǰe���ַ�Ԫ��ѹ���ջ*/
		}
		if (e[i] == '*' || e[i] == '/') /*����ַ��ǳ˻����ʱ*/
		{
			if (!empty2(top)) /*��ջ��Ϊ��*/
			{
				w = topx2(top); /*��ջ��Ԫ�ش���w*/
				while (w == '*' || w == '/')/*��ջ��Ԫ���ǳ˻��ʱ����ѭ��*/
				{
					a[j] = w;
					j++; /*��ջ��Ԫ�ش����ַ���a�У�a���±��1*/
					top = pop2(top); /*ɾ��ջ��Ԫ��*/
					if (empty2(top)) /*���ջΪ��*/
						break; /*����ѭ��*/
					else
						w = topx2(top); /*�����ջ��Ԫ��*/
				}
			}
			top = push2(top, e[i]); /*����ǰe�ַ�Ԫ��ѹ���ջ*/
		}
		i++; /*e���±��1*/
	}
	while (!empty2(top)) /*����Ϊ��ʱ����ѭ��*/
		top = ptop2(top, &a[j++]); /*��ջ��Ԫ�ش�������a��*/
	a[j] = '\0';  /*���ַ����������д�����һ������Ԫ���й����ַ���*/
}
int computer(char* s)  /* ���㺯��*/
{
	STACK1* top = NULL;
	int i, k, num1, num2, result;
	i = 0;
	while (s[i] != '\0')  /*���ַ���û�н���ʱ�����´���*/
	{
		if (isdigit(s[i])) /*���ַ��Ƿ�Ϊ����*/
		{
			k = 0;  /*k��ֵΪ0*/
			do {
				k = 10 * k + s[i] - '0';  /*���ַ�����Ϊʮ��������*/
				i++;   /*i��1*/
			} while (s[i] != '.'); /*���ַ���Ϊ��.��ʱ�ظ�ѭ��*/
			top = push(top, k); /*�����ɵ�����ѹ���ջ*/
		}
		if (s[i] == '+')  /*���Ϊ'+'��*/
		{
			top = ptop(top, &num2); /*��ջ��Ԫ��ȡ������num2��*/
			top = ptop(top, &num1);  /*��ջ��Ԫ��ȡ������num1��*/
			result = num2 + num1;  /*��num1��num2��Ӵ���result��*/
			top = push(top, result);  /*��resultѹ���ջ*/
		}
		if (s[i] == '-')  /*���Ϊ'-'��*/
		{
			top = ptop(top, &num2); /*��ջ��Ԫ��ȡ������num2��*/
			top = ptop(top, &num1); /*��ջ��Ԫ��ȡ������num1��*/
			result = num1 - num2; /*��num1��ȥnum2�������result��*/
			top = push(top, result); /*��resultѹ���ջ*/
		}
		if (s[i] == '*')  /*���Ϊ'*'��*/
		{
			top = ptop(top, &num2); /*��ջ��Ԫ��ȡ������num2��*/
			top = ptop(top, &num1); /*��ջ��Ԫ��ȡ������num1��*/
			result = num1 * num2; /*��num1��num2��˽������result��*/
			top = push(top, result); /*��resultѹ���ջ*/
		}
		if (s[i] == '/') /*���Ϊ'/'��*/
		{
			top = ptop(top, &num2); /*��ջ��Ԫ��ȡ������num2��*/
			top = ptop(top, &num1); /*��ջ��Ԫ��ȡ������num1��*/
			result = num1 / num2; /*��num1��num2�������result��*
								  top=push(top,result); /*��resultѹ���ջ*/
		}
		i++;  /*i��1*/
	}
	top = ptop(top, &result); /*���ջ��Ԫ�ص�ֵΪ����Ľ��*/
	return result;  /*���ؽ��*/
}
STACK1* initstack1(STACK1* top) /*��ʼ��*/
{
	top = NULL; /*ջ��ָ����Ϊ��*/
	return top;  /*����ջ��ָ��*/
}
STACK1* push(STACK1* top, int x) /*��ջ����*/
{
	STACK1* p;  /*��ʱָ������ΪSTACK1*/
	p = (STACK1*)malloc(sizeof(STACK1));  /*����STACK1��С�Ŀռ�*/
	if (p == NULL)  /*���pΪ��*/
	{
		printf("memory is overflow\n!!"); /*��ʾ�ڴ����*/
		exit(0);   /*�˳�*/
	}
	p->data = x; /*����ֵx���¿ռ�*/
	p->link = top;  /*�½��ĺ��Ϊ��ǰջ��ָ��*/
	top = p;  /*�µ�ջ��ָ��Ϊ�²���Ľ��*/
	return top; /*����ջ��ָ��*/
}
STACK1* pop(STACK1* top) /*��ջ*/
{
	STACK1* q; /*������ʱ����*/
	q = top;  /*���浱ǰջ��ָ��*/
	top = top->link; /*ջ��ָ�����*/
	free(q);  /*�ͷ�q*/
	return top; /*����ջ��ָ��*/
}
int topx(STACK1* top)  /*��ջ��Ԫ��*/
{
	if (top == NULL)  /*ջ�Ƿ�Ϊ��*/
	{
		printf("Stack is null\n"); /*��ʾջΪ����Ϣ*/
		return 0;   /*��������0*/
	}
	return top->data; /*����ջ��Ԫ��*/
}
STACK1* ptop(STACK1* top, int* x) /*ȡջ��Ԫ�أ���ɾ��ջ��Ԫ��*/
{
	*x = topx(top);  /*��ջ��Ԫ��*/
	top = pop(top); /*ɾ��ջ��Ԫ��*/
	return top; /*����ջ��ָ��*/
}
int empty(STACK1* top) /*��ջ�Ƿ�Ϊ��*/
{
	if (top == NULL) /*���Ϊ��*/
		return 1;  /*����1*/
	else
		return 0; /*���򷵻�0*/
}
STACK2* initstack2(STACK2* top) /*��ʼ��*/
{
	top = NULL; /*ջ��ָ����Ϊ��*/
	return top; /*����ջ��ָ��*/
}
STACK2* push2(STACK2* top, char x) /*��ջ����*/
{
	STACK2* p; /*��ʱָ������ΪSTACK2*/
	p = (STACK2*)malloc(sizeof(STACK2)); /*����STACK2��С�Ŀռ�*/
	if (p == NULL) /*���pΪ��*/
	{
		printf("memory is overflow\n!!"); /*��ʾ�ڴ����*/
		exit(0); /*�˳�*/
	}
	p->data = x; /*����ֵx���¿ռ�*/
	p->link = top; /*�½��ĺ��Ϊ��ǰջ��ָ��*/
	top = p; /*�µ�ջ��ָ��Ϊ�²���Ľ��*/
	return top; /*����ջ��ָ��*/
}
STACK2* pop2(STACK2* top) /*��ջ*/
{
	STACK2* q; /*������ʱ����*/
	q = top; /*���浱ǰջ��ָ��*/
	top = top->link; /*ջ��ָ�����*/
	free(q); /*�ͷ�q*/
	return top; /*����ջ��ָ��*/
}
char topx2(STACK2* top) /*��ջ��Ԫ��*/
{
	if (top == NULL) /*ջ�Ƿ�Ϊ��*/
	{
		printf("Stack is null\n"); /*��ʾջΪ����Ϣ*/
		return ' '; /*���ؿ��ַ�*/
	}
	return top->data; /*����ջ��Ԫ��*/
}
STACK2* ptop2(STACK2* top, char* x) /*ȡջ��Ԫ�أ���ɾ��ջ��Ԫ��*/
{
	*x = topx2(top); /*��ջ��Ԫ��*/
	top = pop2(top); /*ɾ��ջ��Ԫ��*/
	return top; /*����ջ��ָ��*/
}
int empty2(STACK2* top) /*��ջ�Ƿ�Ϊ��*/
{
	if (top == NULL) /*���Ϊ��*/
		return 1; /*����1*/
	else
		return 0; /*���򷵻�0*/
}

int text1(char *s)
{
	setbkcolor(BLUE); /*���ñ�����ɫΪ��ɫ*/
	cleardevice(); /*�����Ļ*/
	setcolor(12); /*�����ı���ɫΪ����ɫ*/
	settextstyle(1, 0, 8);/*���رʻ�����, �Ŵ�8��*/
	outtextxy(120, 120, s); /*����ַ���s*/
	setusercharsize(2, 1, 4, 1);/*ˮƽ�Ŵ�2��, ��ֱ�Ŵ�4��*/
	setcolor(15);   /*�����ı���ɫΪ*��ɫ/
					settextstyle(3, 0, 5); /*�޳��ֱʻ�, �Ŵ�5��*/
	outtextxy(220, 220, s); /*����ַ���s*/
	getch(); /*����������һ�ַ�*/
	return; /*����*/
}