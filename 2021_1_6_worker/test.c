

#define _CRT_SECURE_NO_WARNINGS      //��Ϊ��scanf����ȫ������ʹ��
#include <stdio.h> 
#include <stdlib.h>  
#include <string.h>


struct workers   //����ְ��
{
	char jobNo[15];       //ְ����
	char name[15];        //����
	char sex;             //�Ա�
	char birthday[15];    //��������
	char degree[15];      //ѧ��
	char position[15];    //ְ�� 
	char salary[15];      //���� 
	char addr[15];        //סַ 
	char tel[15];         //�绰 
};


//����ָ��
typedef struct node
{
	struct workers data;
	struct node *next;

}Node;

int isExit(Node *worker)
{

}


//�����Ϣ����     "β�巨����"���½ڵ�嵽��ǰ������ı�β
void Add(Node *worker)
{
	Node *p, *q;  //���Զ�������Node����һ�������͵�ָ�����
	char n[10];  //����һ���ַ��ͱ���n�������洢ְ����ְ����
	q = worker;  //��ָ��*workerָ��*q
	while (q->next != NULL)  //��qָ�����һ����㲻Ϊ��ʱ����q->next��ֵ��q
	{
		q = q->next;
	}
	while (1)
	{
		printf("��ʾ������0�������˵���\n");
		printf("������ְ���ţ�");
		scanf("%s", n);
		if (strcmp(n, "0") == 0)  //�ַ����Ƚϣ��Ƚ������ַ��������ݱȽϽ���������������Ϊ0��С��Ϊ��������Ϊ��
		{
			break;   //���ж�Ϊ0��������ѭ��
		}
		p = (Node *)malloc(sizeof(Node));  //��Node*�ڴ�������һ������Ϊnode�����ռ�
		strcpy(p->data.jobNo, n);  //�Ѻ���'\0'���������ַ������Ƶ���һ����ַ�ռ䣬����ֵ����Ϊchar*

		printf("������������");  //���ݴ���
		scanf("%s", p->data.name);
		printf("������ְ���Ա�f��m��:");
		while (1) {
			fflush(stdin);
			scanf("%c", &p->data.sex);
			if (p->data.sex != 'm' && p->data.sex != 'f') {
				printf("������������������Ա���Ա�f��m��ע��f �� m : ");
				continue;
			}
			else {
				break;
			}
		}
		printf("������������£�");
		scanf("%s", p->data.birthday);
		printf("������ѧ����");
		scanf("%s", p->data.degree);
		printf("������ְ��");
		scanf("%s", p->data.position);
		printf("�����빤�ʣ�");
		scanf("%s", p->data.salary);
		printf("������סַ��");
		scanf("%s", p->data.addr);
		printf("������绰��");
		scanf("%s", p->data.tel);
		//if (isExit(p)) {

		//}
		printf("��ʾ���Ѿ����һ����¼����ӣ�");
		p->next = NULL; //��ʾp����һ�����Ϊ��
		q->next = p;   //��p ��ֵ��q->next��pΪq����һ�����
		q = p;
	}

}


//�޸�ְ����Ϣ����
int  change(Node *worker)  //��������Ϊchange�ĺ���������һ��ָ�룬����Ϊ���ͷ���ֵ
{
	Node *p;
	char find[20];
	p = worker->next;  //��worker����һ�����Ϊp
	if (p == NULL)
	{
		printf("\n��ʾ��û�����Ͽ����޸ģ�\n");
		return 0;
	}

	printf("������Ҫ�޸ĵ�ְ����");
	scanf("%s", find);

	while (p != NULL)
	{
		if (strcmp(p->data.jobNo, find) == 0)  //�Ƚ��ַ�����ASCIIֵ��С���ж��Ƿ�Ϊ0
		{
			break;
		}
		p = p->next;  //��p����һ�����Ϊp
	}

	if (p != NULL)  //p����п�
	{
		int x;
		while (1)
		{
			printf("����޸�������0�����������0���ֽ����޸ģ�");
			scanf("%d", &x);
			if (x == 0)
			{
				break;
			}
			printf(" ��������ְ����: ");
			scanf("%s", p->data.jobNo);
			printf(" ��������ְ������: ");
			scanf("%s", p->data.name);
			printf("������ְ���Ա�f��m��:");
			while (1) {
				fflush(stdin);
				scanf("%c", &p->data.sex);
				if (p->data.sex != 'm' && p->data.sex != 'f') {
					printf("������������������Ա���Ա�f��m��ע��f �� m : ");
					continue;
				}
				else {
					break;
				}
			}
			printf(" ��������ְ����������: ");
			scanf("%s", p->data.birthday);
			printf(" ��������ְ��ѧ��: ");
			scanf("%s", p->data.degree);
			printf(" ��������ְ��ְ��: ");
			scanf("%s", p->data.position);
			printf(" ��������ְ������: ");
			scanf("%s", p->data.salary);
			printf(" ��������ְ��סַ: ");
			scanf("%s", p->data.addr);
			printf(" ��������ְ���绰: ");
			scanf("%s", p->data.tel);
			printf(" \n��ʾ����ְ�������Ѿ��޸ģ�\n ");
		}
	}
	else{
		printf("\n��ʾ��û����Ҫ�޸ĵ�����!\n ");
		return 0;
	}
	return 1;
}


//���ְ����Ϣ����
int  Disp(Node *worker)
{
	Node *p;
	p = worker->next;
	if (p == NULL)
	{
		printf(" \n��ʾ:û����Ϣ������ʾ!\n ");
		return 0;

	}
	printf("\t\t\t\t��ʾ���\n");
	printf(" \nְ����   ����	�Ա�	��������     ѧ��	  ְ��	����	  סַ	�绰	\n ");
	while (p != NULL)
	{
		printf("\n %s\t %s\t %c\t %s\t %s\t %s\t %s\t %s\t %s\t\n ", p->data.jobNo, p->data.name,
			p->data.sex, p->data.birthday, p->data.degree, p->data.position,
			p->data.salary, p->data.addr, p->data.tel);
		p = p->next;

	}
	return 1;
}


//��ѯְ����Ϣ����: ��ְ���Ų�ѯ	��ְ��������ѯ
int  Cha_xun(Node *worker)
{
	Node *p;
	int sel;
	char find[20];
	p = worker->next;

	if (p == NULL)
	{
		printf(" \n��ʾ��û�����Ͽ��Բ�ѯ��\n ");
		return 0;

	}

	printf("\n��ʾ��\n ���� 0---- �˳�\t ���� 1----��ְ���Ų�ѯ\t ���� 2-----��ְ��������ѯ\n");
	printf("��ѡ��");
	scanf("%d", &sel);

	if (sel == 1)
	{
		printf("\n��������Ҫ��ѯ�����ְ���ţ�");
		scanf("%s", find);
		while (p != NULL)
		{
			if (strcmp(p->data.jobNo, find) == 0)
			{
				printf(" ְ����	  ����  	�Ա�	 ��������	    ѧ��	      ְ��	����	  סַ	�绰 \n ");
				printf(" \n %s\t %s\t %c\t %s\t %s\t %s\t %s\t %s\t %s\t\n ", p->data.jobNo, p->data.name,
					p->data.sex, p->data.birthday, p->data.degree, p->data.position,
					p->data.salary, p->data.addr, p->data.tel);

			}
			p = p->next;

		}

	}

	else if (sel == 2)
	{
		printf(" \n������Ҫ��ѯ�����ְ��������");
		scanf("%s", find);
		while (p != NULL)
		{
			if (strcmp(p->data.name, find) == 0)
			{
				printf(" ְ����	����	�Ա�	 ��������	   ѧ��	  ְ��	����  	סַ	  �绰 \n ");
				printf(" \n %s\t %s\t %c\t %s\t %s\t %s\t %s\t %s\t %s\t \n ", p->data.jobNo, p->data.name,
					p->data.sex, p->data.birthday, p->data.degree, p->data.position,
					p->data.salary, p->data.addr, p->data.tel);

			}
			p = p->next;

		}
	}

	else if (sel == 0)
		return 0;
	return 1;
}


//ɾ��ְ����Ϣ����
int  Delete(Node *worker)
{
	Node *p, *r;
	char find[10];
	p = worker->next;
	if (p == NULL)
	{
		printf("��ʾ��û��ְ����Ϣ����ɾ����\n ");
		return 0;

	}
	printf(" \n��ʾ����������Ҫɾ����ְ���ţ�\n ");
	scanf("%s", find);
	while (p != NULL)
	{
		if (strcmp(p->data.jobNo, find) == 0)
		{
			break;
		}
		p = p->next;

	}

	if (p != NULL)
	{
		r = worker;
		while (r->next != p)
		{
			r = r->next;
		}
		r->next = r->next->next;
	}
	return 1;
}


//��ְ����Ϣ���浽�ļ���
void save(Node *worker)
{
	int n;
	Node *p = NULL;
	FILE *fp;
	printf("�Ƿ񱣴浽�ļ���( 1-----���棡��0-----�����棡 )");
	scanf("%d", &n);

	if (n == 1)
	{
		if (worker->next == NULL)
		{
			printf(" û�м�¼��");
		}

		else
		{
			p = worker->next;
		}

		if ((fp = fopen(" ְ����Ϣ����ϵͳ.txt ", " wb ")) == NULL)
		{
			printf(" �ļ����ܴ򿪣�\n");
			return;
		}

		while (p != NULL)
		{
			fprintf(fp, " %s\t %s\t %c\t %s\t %s\t %s\t %s\t %s\t %s\t ", p->data.jobNo, p->data.name, &p->data.sex,
				p->data.birthday, p->data.degree, p->data.position, p->data.salary,
				p->data.addr, p->data.tel);
			p = p->next;

		}
		fclose(fp);
	}
}


//��ȡְ����Ϣ 
void Du_qu(Node *worker)
{
	Node *p;
	FILE *fp;

	if ((fp = fopen("ְ����Ϣ����ϵͳ.txt", "rb")) == NULL)
	{
		printf("�ļ����ܴ�!\n ");
		return;
	}
	p = worker->next;
	while (p != NULL)
	{
		fscanf(fp, " %s\t %s\t %c\t %s\t %s\t %s\t %s\t %s\t %s\t ", p->data.jobNo, p->data.name, &p->data.sex,
			p->data.birthday, p->data.degree, p->data.position, p->data.salary,
			p->data.addr, p->data.tel);
		p = p->next;

	}
	printf("��ȡ��Ϣ�ɹ�!\n");
	fclose(fp);
}

void Menu()
{
	printf("\t\t\t\t         ְ �� �� Ϣ �� �� ϵ ͳ\n");
	printf("\t\t\t\t==================�� ��==================\n ");
	printf("\t\t\t\t-------------1.����ְ����Ϣ-------------\n ");
	printf("\t\t\t\t-------------2.�޸�ְ����Ϣ-------------\n ");
	printf("\t\t\t\t-------------3.���ְ����Ϣ-------------\n ");
	printf("\t\t\t\t-------------4.��ѯְ����Ϣ-------------\n ");
	printf("\t\t\t\t-------------5.ɾ��ְ����Ϣ-------------\n ");
	printf("\t\t\t\t-------------6.��ȡְ����Ϣ-------------\n ");
	printf("\t\t\t\t-------------0.  �˳�ϵͳ  -------------\n ");

	printf("\t\t\t\t��ѡ����Ҫ���еĲ���(�������): ");
}

//������ 
int main()
{
	Node *worker;
	int flag;
	worker = (Node*)malloc(sizeof(Node));
	worker->next = NULL;

	int quit = 0;  //�����˳�ϵͳ
	while (!quit)
	{
		Menu();
		scanf("%d", &flag);
		switch (flag)
		{
		case 0:
			printf(" \n��ʾ���˳�ϵͳ!\n ");
			quit = 1;
			break;
		case 1:
			Add(worker);
			save(worker);
			break;    //���ְ����Ϣ,���浽�ļ��� 
		case 2:
			change(worker);
			break;           //�޸�ְ����Ϣ 
		case 3:
			Disp(worker);
			break;             //��ʾְ����Ϣ 
		case 4:
			Cha_xun(worker);
			break;           //��ѯְ����Ϣ 
		case 5:
			Delete(worker);
			break;          //ɾ��ְ����Ϣ 
		case 6:
			Du_qu(worker);
			break;             //��ȡְ����Ϣ 
		default:
			printf("�����������������룡\n ");
			system("pause");
			system("cls");
			continue;
		}
		system("pause");
		system("cls");
	}
}


#if 0
#define _CRT_SECURE_NO_WARNINGS      //��Ϊ��scanf����ȫ������ʹ��

#include <stdio.h> 
#include <stdlib.h>  
#include <string.h>
#include <windows.h>

struct workers   //����ְ��
{
	char jobNo[15];       //ְ����
	char name[15];        //����
	char sex[15];         //�Ա�
	char birthday[15];    //��������
	char degree[15];      //ѧ��
	char position[15];    //ְ�� 
	char salary[15];      //���� 
	char addr[15];        //סַ 
	char tel[15];         //�绰 
};


//���Ͷ������  
typedef struct node
{
	struct workers data;
	struct node *next;

}Node;


//�����Ϣ����     "β�巨����"
void Add(Node *worker)
{
	Node *p, *q;
	char n[10];
	q = worker;
	while (q->next != NULL)
	{
		q = q->next;
	}
	while (1)
	{
		printf("��ʾ������0�������˵���\n");
		printf("������ְ���ţ�");
		scanf("%s", n);
		if (strcmp(n, "0") == 0)
		{
			break;
		}
		p = (Node *)malloc(sizeof(Node));
		strcpy(p->data.jobNo, n);

		printf("������������");
		scanf("%s", p->data.name);
		printf("�������Ա�");
		scanf("%s", p->data.sex);
		printf("������������£�");
		scanf("%s", p->data.birthday);
		printf("������ѧ����");
		scanf("%s", p->data.degree);
		printf("������ְ��");
		scanf("%s", p->data.position);
		printf("�����빤�ʣ�");
		scanf("%s", p->data.salary);
		printf("������סַ��");
		scanf("%s", p->data.addr);
		printf("������绰��");
		scanf("%s", p->data.tel);
		printf("��ʾ���Ѿ����һ����¼����ӣ�");
		p->next = NULL;
		q->next = p;
		q = p;
	}
}


//�޸�ְ����Ϣ����
int  change(Node *worker)
{
	Node *p;
	char find[20];
	p = worker->next;
	if (p == NULL)
	{
		printf("\n��ʾ��û�����Ͽ����޸ģ�\n");
		return 0;
	}

	printf("������Ҫ�޸ĵ�ְ����: ");
	scanf("%s", find);

	while (p != NULL)
	{
		if (strcmp(p->data.jobNo, find) == 0)
		{
			break;
		}
		p = p->next;
	}

	if (p != NULL)
	{
		int x;
		while (1)
		{
			printf("����޸�������0�����������0���ֽ����޸ģ�\n");
			scanf("%d", &x);
			if (x == 0)
			{
				break;
			}
			printf(" ��������ְ����: ");
			scanf("%s", p->data.jobNo);
			printf(" ��������ְ������: ");
			scanf("%s", p->data.name);
			printf(" ��������ְ���Ա�: ");
			scanf("%s", p->data.sex);
			printf(" ��������ְ����������: ");
			scanf("%s", p->data.birthday);
			printf(" ��������ְ��ѧ��: ");
			scanf("%s", p->data.degree);
			printf(" ��������ְ��ְ��: ");
			scanf("%s", p->data.position);
			printf(" ��������ְ������: ");
			scanf("%s", p->data.salary);
			printf(" ��������ְ��סַ: ");
			scanf("%s", p->data.addr);
			printf(" ��������ְ���绰: ");
			scanf("%s", p->data.tel);
			printf(" \n��ʾ����ְ�������Ѿ��޸ģ�\n ");
		}
	}
	else {
		printf("\n��ʾ����Ա��������!\n ");
		return 0;
	}
	return 1;
}


//���ְ����Ϣ����
int  Disp(Node *worker)
{
	Node *p;
	p = worker->next;
	if (p == NULL)
	{
		printf(" \n��ʾ:û����Ϣ������ʾ!\n ");
		return 0;

	}
	printf("\t\t\t\t��ʾ���\n");
	printf(" \nְ����   ����	�Ա�	��������    ѧ��	ְ��	����	סַ	�绰	\n ");
	while (p != NULL)
	{
		printf("\n %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t\n ", p->data.jobNo, p->data.name,
			p->data.sex, p->data.birthday, p->data.degree, p->data.position,
			p->data.salary, p->data.addr, p->data.tel);
		p = p->next;

	}
	return 1;
}


//��ѯְ����Ϣ����: ��ְ���Ų�ѯ	��ְ��������ѯ
int  Cha_xun(Node *worker)
{
	Node *p;
	int sel;
	char find[20];
	p = worker->next;

	if (p == NULL)
	{
		printf(" \n��ʾ��û�����Ͽ��Բ�ѯ��\n ");
		return 0;

	}

	printf("\n��ʾ��\n ���� 0---- �˳�\t ���� 1----��ְ���Ų�ѯ\t ���� 2-----��ְ��������ѯ\n");
	printf("��ѡ��");
	scanf("%d", &sel);

	if (sel == 1)
	{
		printf("\n��������Ҫ��ѯ�����ְ���ţ�");
		scanf("%s", find);
		while (p != NULL)
		{
			if (strcmp(p->data.jobNo, find) == 0)
			{
				printf(" ְ����	  ����  	�Ա�	��������	ѧ��	ְ��	����	סַ	�绰 \n ");
				printf(" \n %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t\n ", p->data.jobNo, p->data.name,
					p->data.sex, p->data.birthday, p->data.degree, p->data.position,
					p->data.salary, p->data.addr, p->data.tel);

			}
			p = p->next;

		}

	}

	else if (sel == 2)
	{
		printf(" \n������Ҫ��ѯ�����ְ��������");
		scanf("%s", find);
		while (p != NULL)
		{
			if (strcmp(p->data.name, find) == 0)
			{
				printf(" ְ����		����	�Ա�	��������	ѧ��	ְ��	����	סַ	�绰 \n ");
				printf(" \n %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t \n ", p->data.jobNo, p->data.name,
					p->data.sex, p->data.birthday, p->data.degree, p->data.position,
					p->data.salary, p->data.addr, p->data.tel);
			}
			p = p->next;

		}
	}

	else if (sel == 0)
		return 0;
	return 1;
}


//ɾ��ְ����Ϣ����
int  Delete(Node *worker)
{
	Node *p, *r;
	char find[10];
	p = worker->next;
	if (p == NULL)
	{
		printf("��ʾ��û��ְ����Ϣ����ɾ����\n ");
		return 0;

	}
	printf(" \n��ʾ����������Ҫɾ����ְ���ţ�\n ");
	scanf("%s", find);
	while (p != NULL)
	{
		if (strcmp(p->data.jobNo, find) == 0)
		{
			break;
		}
		p = p->next;

	}

	if (p != NULL)
	{
		r = worker;
		while (r->next != p)
		{
			r = r->next;
		}
		r->next = r->next->next;
	}
	printf("ɾ����Ϣ�ɹ�!\n");
	return 1;
}


//��ְ����Ϣ���浽�ļ���
void save(Node *worker)
{
	int n;
	Node *p = NULL;
	FILE *fp;
	printf("�Ƿ񱣴浽�ļ���( 1-----���棡��0-----�����棡 ): ");
	scanf("%d", &n);

	if (n == 1)
	{
		if (worker->next == NULL)
		{
			printf(" û�м�¼��\n");
		}

		else
		{
			p = worker->next;
		}

		if ((fp = fopen("ְ����Ϣ����ϵͳ.txt", " wb ")) == NULL)
		{
			printf(" �ļ����ܴ򿪣�\n");
			return;
		}

		while (p != NULL)
		{
			fprintf(fp, " %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t ", p->data.jobNo, p->data.name, p->data.sex,
				p->data.birthday, p->data.degree, p->data.position, p->data.salary,
				p->data.addr, p->data.tel);
			p = p->next;

		}
		fclose(fp);
	}
	printf("��ϵ����Ϣ�ѳɹ��������ļ�!\n");
}



void Du_qu(Node *worker)
{
	Node *p;
	FILE *fp;

	if ((fp = fopen("ְ����Ϣ����ϵͳ.txt", "rb")) == NULL)
	{
		printf("�ļ����ܴ�!\n ");
		return;
	}

	p = worker;
	Node *q = p;
	while (!feof(fp))
	{
		p = (Node*)malloc(sizeof(Node));
		fscanf(fp, " %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t ", p->data.jobNo, p->data.name, p->data.sex,
			p->data.birthday, p->data.degree, p->data.position, p->data.salary,
			p->data.addr, p->data.tel);
		p->next = NULL;
		q->next = p;
		q = p;
	}
	printf("���ļ���ȡԱ����Ϣ�ɹ�!\n");
	fclose(fp);
}

//�˵�����
void Menu()
{
	printf("\t\t\t\t         ְ �� �� Ϣ �� �� ϵ ͳ\n");
	printf("\t\t\t\t==================�� ��==================\n ");
	printf("\t\t\t\t-------------1.����ְ����Ϣ-------------\n ");
	printf("\t\t\t\t-------------2.�޸�ְ����Ϣ-------------\n ");
	printf("\t\t\t\t-------------3.���ְ����Ϣ-------------\n ");
	printf("\t\t\t\t-------------4.��ѯְ����Ϣ-------------\n ");
	printf("\t\t\t\t-------------5.ɾ��ְ����Ϣ-------------\n ");
	printf("\t\t\t\t-------------6.��ȡְ����Ϣ-------------\n ");
	printf("\t\t\t\t-------------0.  �˳�ϵͳ  -------------\n ");

	printf("\t\t\t\t��ѡ����Ҫ���еĲ���(�������): ");
}

//������ʵ�� 
int main()
{
	Node *worker;
	int flag;

	worker = (Node*)malloc(sizeof(Node));
	worker->next = NULL;

	int quit = 0; //�����˳�ϵͳ
	while (!quit)
	{
		Menu();
		scanf("%d", &flag);
		switch (flag)
		{
		case 0:  
			printf(" \n��ʾ���˳�ϵͳ!\n ");  
			quit = 1;
			break;
		case 1:	 
			Add(worker); save(worker);  
			break;    //���ְ����Ϣ,���浽�ļ��� 
		case 2:  
			change(worker);  
			break;           //�޸�ְ����Ϣ 
		case 3:  
			Disp(worker);  
			break;             //��ʾְ����Ϣ 
		case 4:  
			Cha_xun(worker);  
			break;           //��ѯְ����Ϣ 
		case 5:  
			Delete(worker);  
			break;          //ɾ��ְ����Ϣ 
		case 6:  
			Du_qu(worker);  
			break;             //��ȡְ����Ϣ 
		default: 
			printf("�����������������룡\n ");
			system("pause");
			system("cls");
			continue;
		}
		system("pause");
		system("cls");
	}
	return 0;
}
#endif