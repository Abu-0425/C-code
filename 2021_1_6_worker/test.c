

#define _CRT_SECURE_NO_WARNINGS      //因为有scanf不安全函数的使用
#include <stdio.h> 
#include <stdlib.h>  
#include <string.h>


struct workers   //定义职工
{
	char jobNo[15];       //职工号
	char name[15];        //姓名
	char sex;             //性别
	char birthday[15];    //出生年月
	char degree[15];      //学历
	char position[15];    //职务 
	char salary[15];      //工资 
	char addr[15];        //住址 
	char tel[15];         //电话 
};


//定义指针
typedef struct node
{
	struct workers data;
	struct node *next;

}Node;

int isExit(Node *worker)
{

}


//添加信息函数     "尾插法建表"将新节点插到当前单链表的表尾
void Add(Node *worker)
{
	Node *p, *q;  //对自定义类型Node定义一个该类型的指针变量
	char n[10];  //定义一个字符型变量n，用来存储职工的职工号
	q = worker;  //把指针*worker指向*q
	while (q->next != NULL)  //当q指针的下一个结点不为空时，将q->next赋值给q
	{
		q = q->next;
	}
	while (1)
	{
		printf("提示：输入0返回主菜单！\n");
		printf("请输入职工号：");
		scanf("%s", n);
		if (strcmp(n, "0") == 0)  //字符串比较，比较两个字符串并根据比较结果返回整数，相等为0，小于为负，大于为正
		{
			break;   //若判断为0，跳出该循环
		}
		p = (Node *)malloc(sizeof(Node));  //在Node*内存中申请一个长度为node连续空间
		strcpy(p->data.jobNo, n);  //把含有'\0'结束符的字符串复制到另一个地址空间，返回值类型为char*

		printf("请输入姓名：");  //数据储存
		scanf("%s", p->data.name);
		printf("请输入职工性别（f或m）:");
		while (1) {
			fflush(stdin);
			scanf("%c", &p->data.sex);
			if (p->data.sex != 'm' && p->data.sex != 'f') {
				printf("输入有误，请重新输入员工性别（f或m）注意f 或 m : ");
				continue;
			}
			else {
				break;
			}
		}
		printf("请输入出生年月：");
		scanf("%s", p->data.birthday);
		printf("请输入学历：");
		scanf("%s", p->data.degree);
		printf("请输入职务：");
		scanf("%s", p->data.position);
		printf("请输入工资：");
		scanf("%s", p->data.salary);
		printf("请输入住址：");
		scanf("%s", p->data.addr);
		printf("请输入电话：");
		scanf("%s", p->data.tel);
		//if (isExit(p)) {

		//}
		printf("提示：已经完成一条记录的添加！");
		p->next = NULL; //表示p的下一个结点为空
		q->next = p;   //将p 赋值给q->next，p为q的下一个结点
		q = p;
	}

}


//修改职工信息函数
int  change(Node *worker)  //定义名字为change的函数，输入一个指针，函数为整型返回值
{
	Node *p;
	char find[20];
	p = worker->next;  //将worker的下一个结点为p
	if (p == NULL)
	{
		printf("\n提示：没有资料可以修改！\n");
		return 0;
	}

	printf("请输入要修改的职工号");
	scanf("%s", find);

	while (p != NULL)
	{
		if (strcmp(p->data.jobNo, find) == 0)  //比较字符串的ASCII值大小，判断是否为0
		{
			break;
		}
		p = p->next;  //将p的下一个结点为p
	}

	if (p != NULL)  //p结点判空
	{
		int x;
		while (1)
		{
			printf("完成修改请输入0，否则输入非0数字进行修改！");
			scanf("%d", &x);
			if (x == 0)
			{
				break;
			}
			printf(" 请输入新职工号: ");
			scanf("%s", p->data.jobNo);
			printf(" 请输入新职工姓名: ");
			scanf("%s", p->data.name);
			printf("请输入职工性别（f或m）:");
			while (1) {
				fflush(stdin);
				scanf("%c", &p->data.sex);
				if (p->data.sex != 'm' && p->data.sex != 'f') {
					printf("输入有误，请重新输入员工性别（f或m）注意f 或 m : ");
					continue;
				}
				else {
					break;
				}
			}
			printf(" 请输入新职工出生年月: ");
			scanf("%s", p->data.birthday);
			printf(" 请输入新职工学历: ");
			scanf("%s", p->data.degree);
			printf(" 请输入新职工职务: ");
			scanf("%s", p->data.position);
			printf(" 请输入新职工工资: ");
			scanf("%s", p->data.salary);
			printf(" 请输入新职工住址: ");
			scanf("%s", p->data.addr);
			printf(" 请输入新职工电话: ");
			scanf("%s", p->data.tel);
			printf(" \n提示：该职工资料已经修改！\n ");
		}
	}
	else{
		printf("\n提示：没有你要修改的资料!\n ");
		return 0;
	}
	return 1;
}


//输出职工信息函数
int  Disp(Node *worker)
{
	Node *p;
	p = worker->next;
	if (p == NULL)
	{
		printf(" \n提示:没有信息可以显示!\n ");
		return 0;

	}
	printf("\t\t\t\t显示结果\n");
	printf(" \n职工号   姓名	性别	出生年月     学历	  职务	工资	  住址	电话	\n ");
	while (p != NULL)
	{
		printf("\n %s\t %s\t %c\t %s\t %s\t %s\t %s\t %s\t %s\t\n ", p->data.jobNo, p->data.name,
			p->data.sex, p->data.birthday, p->data.degree, p->data.position,
			p->data.salary, p->data.addr, p->data.tel);
		p = p->next;

	}
	return 1;
}


//查询职工信息函数: 按职工号查询	按职工姓名查询
int  Cha_xun(Node *worker)
{
	Node *p;
	int sel;
	char find[20];
	p = worker->next;

	if (p == NULL)
	{
		printf(" \n提示：没有资料可以查询！\n ");
		return 0;

	}

	printf("\n提示：\n 输入 0---- 退出\t 输入 1----按职工号查询\t 输入 2-----按职工姓名查询\n");
	printf("请选择：");
	scanf("%d", &sel);

	if (sel == 1)
	{
		printf("\n请输入你要查询分类的职工号：");
		scanf("%s", find);
		while (p != NULL)
		{
			if (strcmp(p->data.jobNo, find) == 0)
			{
				printf(" 职工号	  姓名  	性别	 出生年月	    学历	      职务	工资	  住址	电话 \n ");
				printf(" \n %s\t %s\t %c\t %s\t %s\t %s\t %s\t %s\t %s\t\n ", p->data.jobNo, p->data.name,
					p->data.sex, p->data.birthday, p->data.degree, p->data.position,
					p->data.salary, p->data.addr, p->data.tel);

			}
			p = p->next;

		}

	}

	else if (sel == 2)
	{
		printf(" \n输入你要查询分类的职工姓名：");
		scanf("%s", find);
		while (p != NULL)
		{
			if (strcmp(p->data.name, find) == 0)
			{
				printf(" 职工号	姓名	性别	 出生年月	   学历	  职务	工资  	住址	  电话 \n ");
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


//删除职工信息函数
int  Delete(Node *worker)
{
	Node *p, *r;
	char find[10];
	p = worker->next;
	if (p == NULL)
	{
		printf("提示：没有职工信息可以删除！\n ");
		return 0;

	}
	printf(" \n提示：请输入你要删除的职工号！\n ");
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


//将职工信息保存到文件中
void save(Node *worker)
{
	int n;
	Node *p = NULL;
	FILE *fp;
	printf("是否保存到文件？( 1-----保存！，0-----不保存！ )");
	scanf("%d", &n);

	if (n == 1)
	{
		if (worker->next == NULL)
		{
			printf(" 没有记录！");
		}

		else
		{
			p = worker->next;
		}

		if ((fp = fopen(" 职工信息管理系统.txt ", " wb ")) == NULL)
		{
			printf(" 文件不能打开！\n");
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


//读取职工信息 
void Du_qu(Node *worker)
{
	Node *p;
	FILE *fp;

	if ((fp = fopen("职工信息管理系统.txt", "rb")) == NULL)
	{
		printf("文件不能打开!\n ");
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
	printf("读取信息成功!\n");
	fclose(fp);
}

void Menu()
{
	printf("\t\t\t\t         职 工 信 息 管 理 系 统\n");
	printf("\t\t\t\t==================菜 单==================\n ");
	printf("\t\t\t\t-------------1.输入职工信息-------------\n ");
	printf("\t\t\t\t-------------2.修改职工信息-------------\n ");
	printf("\t\t\t\t-------------3.浏览职工信息-------------\n ");
	printf("\t\t\t\t-------------4.查询职工信息-------------\n ");
	printf("\t\t\t\t-------------5.删除职工信息-------------\n ");
	printf("\t\t\t\t-------------6.读取职工信息-------------\n ");
	printf("\t\t\t\t-------------0.  退出系统  -------------\n ");

	printf("\t\t\t\t请选择你要进行的操作(输入序号): ");
}

//主函数 
int main()
{
	Node *worker;
	int flag;
	worker = (Node*)malloc(sizeof(Node));
	worker->next = NULL;

	int quit = 0;  //用来退出系统
	while (!quit)
	{
		Menu();
		scanf("%d", &flag);
		switch (flag)
		{
		case 0:
			printf(" \n提示：退出系统!\n ");
			quit = 1;
			break;
		case 1:
			Add(worker);
			save(worker);
			break;    //添加职工信息,保存到文件中 
		case 2:
			change(worker);
			break;           //修改职工信息 
		case 3:
			Disp(worker);
			break;             //显示职工信息 
		case 4:
			Cha_xun(worker);
			break;           //查询职工信息 
		case 5:
			Delete(worker);
			break;          //删除职工信息 
		case 6:
			Du_qu(worker);
			break;             //读取职工信息 
		default:
			printf("输入有误，请重新输入！\n ");
			system("pause");
			system("cls");
			continue;
		}
		system("pause");
		system("cls");
	}
}


#if 0
#define _CRT_SECURE_NO_WARNINGS      //因为有scanf不安全函数的使用

#include <stdio.h> 
#include <stdlib.h>  
#include <string.h>
#include <windows.h>

struct workers   //定义职工
{
	char jobNo[15];       //职工号
	char name[15];        //姓名
	char sex[15];         //性别
	char birthday[15];    //出生年月
	char degree[15];      //学历
	char position[15];    //职务 
	char salary[15];      //工资 
	char addr[15];        //住址 
	char tel[15];         //电话 
};


//类型定义语句  
typedef struct node
{
	struct workers data;
	struct node *next;

}Node;


//添加信息函数     "尾插法建表"
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
		printf("提示：输入0返回主菜单！\n");
		printf("请输入职工号：");
		scanf("%s", n);
		if (strcmp(n, "0") == 0)
		{
			break;
		}
		p = (Node *)malloc(sizeof(Node));
		strcpy(p->data.jobNo, n);

		printf("请输入姓名：");
		scanf("%s", p->data.name);
		printf("请输入性别：");
		scanf("%s", p->data.sex);
		printf("请输入出生年月：");
		scanf("%s", p->data.birthday);
		printf("请输入学历：");
		scanf("%s", p->data.degree);
		printf("请输入职务：");
		scanf("%s", p->data.position);
		printf("请输入工资：");
		scanf("%s", p->data.salary);
		printf("请输入住址：");
		scanf("%s", p->data.addr);
		printf("请输入电话：");
		scanf("%s", p->data.tel);
		printf("提示：已经完成一条记录的添加！");
		p->next = NULL;
		q->next = p;
		q = p;
	}
}


//修改职工信息函数
int  change(Node *worker)
{
	Node *p;
	char find[20];
	p = worker->next;
	if (p == NULL)
	{
		printf("\n提示：没有资料可以修改！\n");
		return 0;
	}

	printf("请输入要修改的职工号: ");
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
			printf("完成修改请输入0，否则输入非0数字进行修改！\n");
			scanf("%d", &x);
			if (x == 0)
			{
				break;
			}
			printf(" 请输入新职工号: ");
			scanf("%s", p->data.jobNo);
			printf(" 请输入新职工姓名: ");
			scanf("%s", p->data.name);
			printf(" 请输入新职工性别: ");
			scanf("%s", p->data.sex);
			printf(" 请输入新职工出生年月: ");
			scanf("%s", p->data.birthday);
			printf(" 请输入新职工学历: ");
			scanf("%s", p->data.degree);
			printf(" 请输入新职工职务: ");
			scanf("%s", p->data.position);
			printf(" 请输入新职工工资: ");
			scanf("%s", p->data.salary);
			printf(" 请输入新职工住址: ");
			scanf("%s", p->data.addr);
			printf(" 请输入新职工电话: ");
			scanf("%s", p->data.tel);
			printf(" \n提示：该职工资料已经修改！\n ");
		}
	}
	else {
		printf("\n提示：该员工不存在!\n ");
		return 0;
	}
	return 1;
}


//输出职工信息函数
int  Disp(Node *worker)
{
	Node *p;
	p = worker->next;
	if (p == NULL)
	{
		printf(" \n提示:没有信息可以显示!\n ");
		return 0;

	}
	printf("\t\t\t\t显示结果\n");
	printf(" \n职工号   姓名	性别	出生年月    学历	职务	工资	住址	电话	\n ");
	while (p != NULL)
	{
		printf("\n %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t\n ", p->data.jobNo, p->data.name,
			p->data.sex, p->data.birthday, p->data.degree, p->data.position,
			p->data.salary, p->data.addr, p->data.tel);
		p = p->next;

	}
	return 1;
}


//查询职工信息函数: 按职工号查询	按职工姓名查询
int  Cha_xun(Node *worker)
{
	Node *p;
	int sel;
	char find[20];
	p = worker->next;

	if (p == NULL)
	{
		printf(" \n提示：没有资料可以查询！\n ");
		return 0;

	}

	printf("\n提示：\n 输入 0---- 退出\t 输入 1----按职工号查询\t 输入 2-----按职工姓名查询\n");
	printf("请选择：");
	scanf("%d", &sel);

	if (sel == 1)
	{
		printf("\n请输入你要查询分类的职工号：");
		scanf("%s", find);
		while (p != NULL)
		{
			if (strcmp(p->data.jobNo, find) == 0)
			{
				printf(" 职工号	  姓名  	性别	出生年月	学历	职务	工资	住址	电话 \n ");
				printf(" \n %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t\n ", p->data.jobNo, p->data.name,
					p->data.sex, p->data.birthday, p->data.degree, p->data.position,
					p->data.salary, p->data.addr, p->data.tel);

			}
			p = p->next;

		}

	}

	else if (sel == 2)
	{
		printf(" \n输入你要查询分类的职工姓名：");
		scanf("%s", find);
		while (p != NULL)
		{
			if (strcmp(p->data.name, find) == 0)
			{
				printf(" 职工号		姓名	性别	出生年月	学历	职务	工资	住址	电话 \n ");
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


//删除职工信息函数
int  Delete(Node *worker)
{
	Node *p, *r;
	char find[10];
	p = worker->next;
	if (p == NULL)
	{
		printf("提示：没有职工信息可以删除！\n ");
		return 0;

	}
	printf(" \n提示：请输入你要删除的职工号！\n ");
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
	printf("删除信息成功!\n");
	return 1;
}


//将职工信息保存到文件中
void save(Node *worker)
{
	int n;
	Node *p = NULL;
	FILE *fp;
	printf("是否保存到文件？( 1-----保存！，0-----不保存！ ): ");
	scanf("%d", &n);

	if (n == 1)
	{
		if (worker->next == NULL)
		{
			printf(" 没有记录！\n");
		}

		else
		{
			p = worker->next;
		}

		if ((fp = fopen("职工信息管理系统.txt", " wb ")) == NULL)
		{
			printf(" 文件不能打开！\n");
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
	printf("联系人信息已成功保存至文件!\n");
}



void Du_qu(Node *worker)
{
	Node *p;
	FILE *fp;

	if ((fp = fopen("职工信息管理系统.txt", "rb")) == NULL)
	{
		printf("文件不能打开!\n ");
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
	printf("从文件读取员工信息成功!\n");
	fclose(fp);
}

//菜单函数
void Menu()
{
	printf("\t\t\t\t         职 工 信 息 管 理 系 统\n");
	printf("\t\t\t\t==================菜 单==================\n ");
	printf("\t\t\t\t-------------1.输入职工信息-------------\n ");
	printf("\t\t\t\t-------------2.修改职工信息-------------\n ");
	printf("\t\t\t\t-------------3.浏览职工信息-------------\n ");
	printf("\t\t\t\t-------------4.查询职工信息-------------\n ");
	printf("\t\t\t\t-------------5.删除职工信息-------------\n ");
	printf("\t\t\t\t-------------6.读取职工信息-------------\n ");
	printf("\t\t\t\t-------------0.  退出系统  -------------\n ");

	printf("\t\t\t\t请选择你要进行的操作(输入序号): ");
}

//主函数实现 
int main()
{
	Node *worker;
	int flag;

	worker = (Node*)malloc(sizeof(Node));
	worker->next = NULL;

	int quit = 0; //用来退出系统
	while (!quit)
	{
		Menu();
		scanf("%d", &flag);
		switch (flag)
		{
		case 0:  
			printf(" \n提示：退出系统!\n ");  
			quit = 1;
			break;
		case 1:	 
			Add(worker); save(worker);  
			break;    //添加职工信息,保存到文件中 
		case 2:  
			change(worker);  
			break;           //修改职工信息 
		case 3:  
			Disp(worker);  
			break;             //显示职工信息 
		case 4:  
			Cha_xun(worker);  
			break;           //查询职工信息 
		case 5:  
			Delete(worker);  
			break;          //删除职工信息 
		case 6:  
			Du_qu(worker);  
			break;             //读取职工信息 
		default: 
			printf("输入有误，请重新输入！\n ");
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