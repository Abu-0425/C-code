#ifndef _CONTACT_H_
#define _CONTACT_H_

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


#pragma warning(disable:4996)

//文件信息
#define SAVE_FILE "contact.txt"

//person内部元素的大小
#define NAME_SIZE 32
#define SEX_SIZE 8
#define TELEPHONE_SIZE 16
#define ADDRESS_SIZE 128

//通讯录初始化信息
#define INIT_NUM 100 //初始容量，可根据需求随意修改

//扩容数量
#define INC_SIZE (INIT_NUM * 2)  //一次性扩容原容量的一倍

//用来描述联系人的结构体
typedef struct person{
	char name[NAME_SIZE];
	char sex[SEX_SIZE];
	int age;
	char telephone[TELEPHONE_SIZE];
	char address[ADDRESS_SIZE];
}person_t;

//描述通讯录的结构体
typedef struct contact{
	int cap;//通讯录总容量
	int size;//通讯录当前联系人数量
	person_t contacts[0];//定义柔性数组，用来保存联系人的信息
}contact_t;

void InitContact(contact_t **ct);//初始化通讯录
void AddContacts(contact_t **ct);//添加联系人
void ShowContact(contact_t *ct);//显示联系人
void DelContacts(contact_t *ct);//删除联系人
void ModContact(contact_t *ct);//修改联系人
void SearchContacts(contact_t *ct);//查找联系人
void ClearContacts(contact_t *ct);//清空联系人
void SortContact(contact_t *ct);//排序联系人
void SaveContact(contact_t *ct);//将通讯录信息保存至文件


#endif /*_CONTACT_H_*/