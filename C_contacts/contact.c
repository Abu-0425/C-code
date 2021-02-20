#include "contact.h"

void InitContact(contact_t **ct)
{
	assert(ct);
	FILE *fp = fopen(SAVE_FILE, "rb");
	if (fp == NULL){
		//������ļ�ʧ�ܻ��߸��ļ������ڣ���ʹ��Ĭ�Ϸ�ʽ���г�ʼ��
		*ct = (contact_t *)malloc(sizeof(contact_t)+INIT_NUM*sizeof(person_t));
		if (*ct == NULL){
			perror("malloc");
			exit(1);
		}
		(*ct)->size = 0;
		(*ct)->cap = INIT_NUM;
		printf("ʹ��Ĭ�ϵĳ�ʼ����ʽ!\n");
	}
	else{
		//���ļ��ɹ������ļ�����Ϣ������ͨѶ¼����ʹ���ļ�����Ϣ���г�ʼ��
		contact_t temp;//������ʱ�ṹ�����������������ļ��ڶ������Ϣ
		fread(&temp, sizeof(contact_t), 1, fp);//�����ļ��еĽṹ����Ϣ
		*ct = (contact_t *)malloc(sizeof(contact_t)+temp.cap * sizeof(person_t));
		if (*ct == NULL){
			perror("malloc");
			exit(2);
		}
		memcpy(*ct, &temp, sizeof(contact_t));
		fread((*ct)->contacts, sizeof(person_t), (*ct)->size, fp);//�����ļ��е���ϵ����Ϣ
		printf("�ļ��е���ϵ����Ϣ�Ѷ�����ͨѶ¼!\n");
		fclose(fp);
	}
}

static int IsExist(contact_t *ct, person_t *p) //�жϵ�ǰ��ϵ���Ƿ��Ѿ�����
{
	assert(ct);
	assert(p);
	int i = 0;
	for (; i < ct->size; i++){
		if (strcmp(ct->contacts[i].name, p->name) == 0){
			return 1;//��ʾ��ǰ��ϵ���Ѿ�����
		}
	}
	return 0;
}

static int IsFull(contact_t *ct)//�ж���ǰͨѶ¼�Ƿ�����
{
	return ct->size == ct->cap;
}
static int IsEmpty(contact_t *ct)//�ж���ǰͨѶ¼�Ƿ�Ϊ��
{
	return ct->size == 0;
}
static int Inc(contact_t **ct)//ͨѶ¼����
{
	assert(ct);
	contact_t *ct_inc = (contact_t *)realloc(*ct, sizeof(contact_t)+((*ct)->cap + INC_SIZE) * sizeof(person_t));
	if (ct_inc == NULL){
		return 0;//����ʧ��
	}
	*ct = ct_inc;
	(*ct)->cap += INC_SIZE;
	printf("�Զ����ݳɹ�!\n");
	return 1;//���ݳɹ�
}
void AddContacts(contact_t **ct)
{
	assert(ct);
	//�����ǰͨѶ¼δ�����������ϵ����ӣ����ͨѶ¼����������ʵ���Զ�����
	if (!IsFull(*ct) || Inc(ct)){
		person_t p;
		printf("������������ϵ�˵�����: ");
		scanf("%s", p.name);
		printf("������������ϵ�˵��Ա�: ");
		scanf("%s", p.sex);
		printf("������������ϵ�˵�����: ");
		scanf("%d", &(p.age));
		printf("������������ϵ�˵ĵ绰: ");
		scanf("%s", p.telephone);
		printf("������������ϵ�˵ĵ�ַ: ");
		scanf("%s", p.address);
		//�ж���ǰ�û��Ƿ��Ѿ�����
		if (IsExist(*ct, &p)){
			printf("��ϵ��%s�Ѵ��ڣ������ظ����!\n", p.name);
			system("pause");
			system("cls");
			return;
		}
		memcpy((*ct)->contacts + (*ct)->size, &p, sizeof(p));//ʹ��memcpy������ϵ�������ͨѶ¼
		//(*ct)->contacts[(*ct)->size] = p;//���ַ�ʽҲ�������
		(*ct)->size += 1;
		printf("��ϵ��%s��ӳɹ�!\n", p.name);
	}
	else{
		printf("����ʧ��!\n");
	}
	system("pause");
	system("cls");
}
static int SearchPerson(contact_t *ct, char *name)//�����ض���ϵ��
{
	assert(ct);
	assert(name);
	int i = 0;
	for (; i < ct->size; i++){
		person_t *p = ct->contacts + i;
		if (strcmp(name, p->name) == 0){
			return i;//�ҵ��ˣ��ͷ��ض�Ӧ�±�
		}
	}
	return -1;//���޴���

}
void SearchContacts(contact_t *ct)//������ϵ��
{
	assert(ct);
	printf("������������ҵ���ϵ������: ");
	char name[NAME_SIZE];
	scanf("%s", name);
	int i = SearchPerson(ct, name);
	if (i >= 0){
		person_t *p = ct->contacts + i;
		printf("����:%-10s�Ա�:%-5s����:%-5d�绰:%-15s��ַ:%-20s\n", p->name, p->sex, p->age, p->telephone, p->address);
	}
	else{
		printf("���޴���!\n");
	}
	system("pause");
	system("cls");
}
void ShowContact(contact_t *ct)//��ʾ��ϵ��
{
	assert(ct);
	if (ct->size == 0){
		printf("��ǰ��¼Ϊ��!\n");
		system("pause");
		system("cls");
		return;
	}
	int i = 0;
	//printf("��ǰ��������: %d\n", ct->size);//����о�û��Ҫд����������Ҳ����
	printf("                                �ҵ���ϵ��\n");
	printf("\n");
	for (; i < ct->size; i++){
		person_t *p = ct->contacts + i;//����*pʹ�������������
		printf("����:%-10s�Ա�:%-5s����:%-5d�绰:%-15s��ַ:%-20s\n", p->name, p->sex, p->age, p->telephone, p->address);
	}
	system("pause");
	system("cls");
}

void ModContact(contact_t *ct)//�޸���ϵ��
{
	assert(ct);
	printf("��������Ҫ�޸ĵ���ϵ������: ");
	char name[NAME_SIZE];
	scanf("%s", name);
	int i = SearchPerson(ct, name);
	if (i >= 0){
		person_t *p = ct->contacts + i;
		printf("�ҵ�����ϵ�ˣ���Ϣ����: \n");
		printf("����:%-10s�Ա�:%-5s����:%-5d�绰:%-15s��ַ:%-20s\n", p->name, p->sex, p->age, p->telephone, p->address);
		printf("���������ϵ�˵�����Ϣ: \n");
		printf("����: ");
		scanf("%s", p->name);
		printf("�Ա�: ");
		scanf("%s", p->sex);
		printf("����: ");
		scanf("%s", &(p->age));
		printf("�绰: ");
		scanf("%s", p->telephone);
		printf("��ַ: ");
		scanf("%s", p->address);
		printf("�޸���ϵ�˳ɹ�!\n");
	}
	else{
		printf("���޴���!\n");
	}
	system("pause");
	system("cls");
}
void DelContacts(contact_t *ct)//ɾ����ϵ��
{
	assert(ct);
	printf("��������Ҫɾ������ϵ������: ");
	char name[NAME_SIZE];
	scanf("%s", name);
	int i = SearchPerson(ct, name);
	if (i >= 0){
		//�����һ����ϵ�˸��ǵ���ǰλ�ã��������ɾ������
		ct->contacts[i] = ct->contacts[ct->size - 1];
		ct->size -= 1;
		printf("��ϵ��%s�ѳɹ�ɾ��!\n", name);
	}
	else{
		printf("���޴���!\n");
	}
	system("pause");
	system("cls");
}
void ClearContacts(contact_t *ct)//�����ϵ��
{
	assert(ct);
	ct->size = 0;//����ǰ��ϵ����������Ϊ0���������ϵ�˵����
	printf("��ϵ���ѳɹ����!\n");
	system("pause");
	system("cls");
}

static int CmpPerson(const void *p1, const void *p2)//qsort�Ļص��������Ƚ�������ϵ�������Ĵ�С
{
	assert(p1);
	assert(p2);
	person_t *_p1 = (person_t *)p1;
	person_t *_p2 = (person_t *)p2;
	return strcmp(_p1->name, _p2->name);//1,0,-1
}

void SortContact(contact_t *ct)//������������ϵ��
{
	assert(ct);
	if (!IsEmpty(ct)){
		qsort(ct->contacts, ct->size, sizeof(person_t), CmpPerson);//ʹ��qsort��������
		printf("����ɹ�!\n");
	}
	else{
		printf("��ǰͨѶ¼Ϊ�գ��޷���������!\n");
	}
	system("pause");
	system("cls");
}

void SaveContact(contact_t *ct)//����ϵ����Ϣ�������ļ�
{
	assert(ct);
	FILE *fp = fopen(SAVE_FILE, "w");
	if (fp == NULL){
		printf("����ʧ��!\n");
		return;
	}
	fwrite(ct, sizeof(contact_t), 1, fp);//��ct->size ��ct->capд���ļ�
	int i = 0;
	for (; i < ct->size; i++){
		fwrite(ct->contacts +i , sizeof(person_t), ct->size, fp);//����ϵ����Ϣд���ļ�
	}
	printf("��ϵ����Ϣ�ѳɹ��������ļ�!\n");

	fclose(fp);
}