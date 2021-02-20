#include "contact.h"

void InitContact(contact_t **ct)
{
	assert(ct);
	FILE *fp = fopen(SAVE_FILE, "rb");
	if (fp == NULL){
		//如果打开文件失败或者该文件不存在，则使用默认方式进行初始化
		*ct = (contact_t *)malloc(sizeof(contact_t)+INIT_NUM*sizeof(person_t));
		if (*ct == NULL){
			perror("malloc");
			exit(1);
		}
		(*ct)->size = 0;
		(*ct)->cap = INIT_NUM;
		printf("使用默认的初始化方式!\n");
	}
	else{
		//打开文件成功，则将文件内信息读入至通讯录，即使用文件内信息进行初始化
		contact_t temp;//定义临时结构体变量，用来保存从文件内读入的信息
		fread(&temp, sizeof(contact_t), 1, fp);//读入文件中的结构体信息
		*ct = (contact_t *)malloc(sizeof(contact_t)+temp.cap * sizeof(person_t));
		if (*ct == NULL){
			perror("malloc");
			exit(2);
		}
		memcpy(*ct, &temp, sizeof(contact_t));
		fread((*ct)->contacts, sizeof(person_t), (*ct)->size, fp);//读入文件中的联系人信息
		printf("文件中的联系人信息已读入至通讯录!\n");
		fclose(fp);
	}
}

static int IsExist(contact_t *ct, person_t *p) //判断当前联系人是否已经存在
{
	assert(ct);
	assert(p);
	int i = 0;
	for (; i < ct->size; i++){
		if (strcmp(ct->contacts[i].name, p->name) == 0){
			return 1;//表示当前联系人已经存在
		}
	}
	return 0;
}

static int IsFull(contact_t *ct)//判定当前通讯录是否已满
{
	return ct->size == ct->cap;
}
static int IsEmpty(contact_t *ct)//判定当前通讯录是否为空
{
	return ct->size == 0;
}
static int Inc(contact_t **ct)//通讯录扩容
{
	assert(ct);
	contact_t *ct_inc = (contact_t *)realloc(*ct, sizeof(contact_t)+((*ct)->cap + INC_SIZE) * sizeof(person_t));
	if (ct_inc == NULL){
		return 0;//扩容失败
	}
	*ct = ct_inc;
	(*ct)->cap += INC_SIZE;
	printf("自动扩容成功!\n");
	return 1;//扩容成功
}
void AddContacts(contact_t **ct)
{
	assert(ct);
	//如果当前通讯录未满，则进行联系人添加，如果通讯录已满，我们实现自动扩容
	if (!IsFull(*ct) || Inc(ct)){
		person_t p;
		printf("请输入新增联系人的姓名: ");
		scanf("%s", p.name);
		printf("请输入新增联系人的性别: ");
		scanf("%s", p.sex);
		printf("请输入新增联系人的年龄: ");
		scanf("%d", &(p.age));
		printf("请输入新增联系人的电话: ");
		scanf("%s", p.telephone);
		printf("请输入新增联系人的地址: ");
		scanf("%s", p.address);
		//判定当前用户是否已经存在
		if (IsExist(*ct, &p)){
			printf("联系人%s已存在，请勿重复添加!\n", p.name);
			system("pause");
			system("cls");
			return;
		}
		memcpy((*ct)->contacts + (*ct)->size, &p, sizeof(p));//使用memcpy将该联系人添加至通讯录
		//(*ct)->contacts[(*ct)->size] = p;//这种方式也可以添加
		(*ct)->size += 1;
		printf("联系人%s添加成功!\n", p.name);
	}
	else{
		printf("扩容失败!\n");
	}
	system("pause");
	system("cls");
}
static int SearchPerson(contact_t *ct, char *name)//查找特定联系人
{
	assert(ct);
	assert(name);
	int i = 0;
	for (; i < ct->size; i++){
		person_t *p = ct->contacts + i;
		if (strcmp(name, p->name) == 0){
			return i;//找到了，就返回对应下标
		}
	}
	return -1;//查无此人

}
void SearchContacts(contact_t *ct)//查找联系人
{
	assert(ct);
	printf("请输入你想查找的联系人姓名: ");
	char name[NAME_SIZE];
	scanf("%s", name);
	int i = SearchPerson(ct, name);
	if (i >= 0){
		person_t *p = ct->contacts + i;
		printf("姓名:%-10s性别:%-5s年龄:%-5d电话:%-15s地址:%-20s\n", p->name, p->sex, p->age, p->telephone, p->address);
	}
	else{
		printf("查无此人!\n");
	}
	system("pause");
	system("cls");
}
void ShowContact(contact_t *ct)//显示联系人
{
	assert(ct);
	if (ct->size == 0){
		printf("当前记录为空!\n");
		system("pause");
		system("cls");
		return;
	}
	int i = 0;
	//printf("当前好友数量: %d\n", ct->size);//这个感觉没必要写，不过加上也可以
	printf("                                我的联系人\n");
	printf("\n");
	for (; i < ct->size; i++){
		person_t *p = ct->contacts + i;//定义*p使后续操作更简便
		printf("姓名:%-10s性别:%-5s年龄:%-5d电话:%-15s地址:%-20s\n", p->name, p->sex, p->age, p->telephone, p->address);
	}
	system("pause");
	system("cls");
}

void ModContact(contact_t *ct)//修改联系人
{
	assert(ct);
	printf("请输入你要修改的联系人姓名: ");
	char name[NAME_SIZE];
	scanf("%s", name);
	int i = SearchPerson(ct, name);
	if (i >= 0){
		person_t *p = ct->contacts + i;
		printf("找到该联系人，信息如下: \n");
		printf("姓名:%-10s性别:%-5s年龄:%-5d电话:%-15s地址:%-20s\n", p->name, p->sex, p->age, p->telephone, p->address);
		printf("请输入该联系人的新信息: \n");
		printf("姓名: ");
		scanf("%s", p->name);
		printf("性别: ");
		scanf("%s", p->sex);
		printf("年龄: ");
		scanf("%s", &(p->age));
		printf("电话: ");
		scanf("%s", p->telephone);
		printf("地址: ");
		scanf("%s", p->address);
		printf("修改联系人成功!\n");
	}
	else{
		printf("查无此人!\n");
	}
	system("pause");
	system("cls");
}
void DelContacts(contact_t *ct)//删除联系人
{
	assert(ct);
	printf("请输入你要删除的联系人姓名: ");
	char name[NAME_SIZE];
	scanf("%s", name);
	int i = SearchPerson(ct, name);
	if (i >= 0){
		//将最后一个联系人覆盖到当前位置，即完成了删除需求
		ct->contacts[i] = ct->contacts[ct->size - 1];
		ct->size -= 1;
		printf("联系人%s已成功删除!\n", name);
	}
	else{
		printf("查无此人!\n");
	}
	system("pause");
	system("cls");
}
void ClearContacts(contact_t *ct)//清空联系人
{
	assert(ct);
	ct->size = 0;//将当前联系人数量设置为0即完成了联系人的清空
	printf("联系人已成功清空!\n");
	system("pause");
	system("cls");
}

static int CmpPerson(const void *p1, const void *p2)//qsort的回调函数，比较俩个联系人姓名的大小
{
	assert(p1);
	assert(p2);
	person_t *_p1 = (person_t *)p1;
	person_t *_p2 = (person_t *)p2;
	return strcmp(_p1->name, _p2->name);//1,0,-1
}

void SortContact(contact_t *ct)//以姓名排序联系人
{
	assert(ct);
	if (!IsEmpty(ct)){
		qsort(ct->contacts, ct->size, sizeof(person_t), CmpPerson);//使用qsort进行排序
		printf("排序成功!\n");
	}
	else{
		printf("当前通讯录为空，无法进行排序!\n");
	}
	system("pause");
	system("cls");
}

void SaveContact(contact_t *ct)//将联系人信息保存至文件
{
	assert(ct);
	FILE *fp = fopen(SAVE_FILE, "w");
	if (fp == NULL){
		printf("保存失败!\n");
		return;
	}
	fwrite(ct, sizeof(contact_t), 1, fp);//把ct->size 和ct->cap写入文件
	int i = 0;
	for (; i < ct->size; i++){
		fwrite(ct->contacts +i , sizeof(person_t), ct->size, fp);//将联系人信息写入文件
	}
	printf("联系人信息已成功保存至文件!\n");

	fclose(fp);
}