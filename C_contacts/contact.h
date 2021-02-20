#ifndef _CONTACT_H_
#define _CONTACT_H_

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


#pragma warning(disable:4996)

//�ļ���Ϣ
#define SAVE_FILE "contact.txt"

//person�ڲ�Ԫ�صĴ�С
#define NAME_SIZE 32
#define SEX_SIZE 8
#define TELEPHONE_SIZE 16
#define ADDRESS_SIZE 128

//ͨѶ¼��ʼ����Ϣ
#define INIT_NUM 100 //��ʼ�������ɸ������������޸�

//��������
#define INC_SIZE (INIT_NUM * 2)  //һ��������ԭ������һ��

//����������ϵ�˵Ľṹ��
typedef struct person{
	char name[NAME_SIZE];
	char sex[SEX_SIZE];
	int age;
	char telephone[TELEPHONE_SIZE];
	char address[ADDRESS_SIZE];
}person_t;

//����ͨѶ¼�Ľṹ��
typedef struct contact{
	int cap;//ͨѶ¼������
	int size;//ͨѶ¼��ǰ��ϵ������
	person_t contacts[0];//�����������飬����������ϵ�˵���Ϣ
}contact_t;

void InitContact(contact_t **ct);//��ʼ��ͨѶ¼
void AddContacts(contact_t **ct);//�����ϵ��
void ShowContact(contact_t *ct);//��ʾ��ϵ��
void DelContacts(contact_t *ct);//ɾ����ϵ��
void ModContact(contact_t *ct);//�޸���ϵ��
void SearchContacts(contact_t *ct);//������ϵ��
void ClearContacts(contact_t *ct);//�����ϵ��
void SortContact(contact_t *ct);//������ϵ��
void SaveContact(contact_t *ct);//��ͨѶ¼��Ϣ�������ļ�


#endif /*_CONTACT_H_*/