#include "chess.h"

int main()
{
	int quit = 0;//��������whileѭ�����˳���Ϸ
	while (!quit){
		Menu();
		int select = 0;
		scanf("%d", &select);
		switch (select){
		case 1:
			Game();
			break;
		case 2:
			quit = 1;//����whileѭ��
			break;
		default:
			printf("Enter error!Please enter again:\n");
			break;
		}
	}

	system("pause");
	return 0;
}