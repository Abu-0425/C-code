#include "contact.h"

static void ShowMenu()//��ӡ�˵�
{
	printf("                                ******************************************\n");
	printf("                                ******************************************\n");
	printf("                                -----------��ѡ����Ҫ���еĲ���-----------\n");
	printf("                                ---------------1.������ϵ��---------------\n");
	printf("                                ---------------2.ɾ����ϵ��---------------\n");
	printf("                                ---------------3.������ϵ��---------------\n");
	printf("                                ---------------4.�޸���ϵ��---------------\n");
	printf("                                ---------------5.��ʾ��ϵ��---------------\n");
	printf("                                ---------------6.�����ϵ��---------------\n");
	printf("                                ---------------7.������ϵ��---------------\n");
	printf("                                ---------------0.�˳�ͨѶ¼---------------\n");
	printf("                                ******************************************\n");
	printf("                                ******************************************\n");
}
//static void ShowMenu()//��ӡ�˵�
//{
//	printf("******************************************\n");
//	printf("******************************************\n");
//	printf("-----------��ѡ����Ҫ���еĲ���-----------\n");
//	printf("---------------1.������ϵ��---------------\n");
//	printf("---------------2.ɾ����ϵ��---------------\n");
//	printf("---------------3.������ϵ��---------------\n");
//	printf("---------------4.�޸���ϵ��---------------\n");
//	printf("---------------5.��ʾ��ϵ��---------------\n");
//	printf("---------------6.�����ϵ��---------------\n");
//	printf("---------------7.������ϵ��---------------\n");
//	printf("---------------0.�˳�ͨѶ¼---------------\n");
//	printf("******************************************\n");
//	printf("******************************************\n");
//}

int main()
{
	contact_t *ct = NULL;//����ṹ��ָ��
	InitContact(&ct);//��ͨѶ¼���г�ʼ��
	int select = 0;
	int quit = 0;
	while (!quit){
		ShowMenu();
		scanf("%d", &select);
		switch (select){
		case 1://������ϵ��
			AddContacts(&ct);
			break;
		case 2://ɾ����ϵ��
			DelContacts(ct);
			break;
		case 3://������ϵ��
			SearchContacts(ct);
			break;
		case 4://�޸���ϵ��
			ModContact(ct);
			break;
		case 5://��ʾ��ϵ��
			ShowContact(ct);
			break;
		case 6://�����ϵ��
			ClearContacts(ct);
			break;
		case 7://������ϵ��
			SortContact(ct);
			break;
		case 0://�˳�ͨѶ¼
			SaveContact(ct);
			quit = 1;
			printf("�˳��ɹ�!\n");
			break;
		default:
			printf("������������������!\n");
			system("pause");
			system("cls");
			break;
		}
	}
	free(ct);//������Ķѿռ��ͷ�,�����ڴ�й©����

	system("pause");
	return 0;
}