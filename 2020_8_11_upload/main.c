#include "mine.h"

int main()
{
	int quit = 0;
	do{
		int select = 0;
		Menu();
		scanf("%d", &select);
		switch (select){
		case 1:
			Game();
			printf("Game end! Do you want to play again?\n");
			break;
		case 2:
			quit = 1;//����whileѭ�������˳�
			printf("Bye, and welcome to play next time!\n");
			break;
		default:
			printf("Enter erorr! Please enter again!\n");//��������
			break;
		}
	} while (!quit);

	system("pause");
	return 0;
}