#include "chess.h"

int main()
{
	int quit = 0;//用来跳出while循环以退出游戏
	while (!quit){
		Menu();
		int select = 0;
		scanf("%d", &select);
		switch (select){
		case 1:
			Game();
			break;
		case 2:
			quit = 1;//跳出while循环
			break;
		default:
			printf("Enter error!Please enter again:\n");
			break;
		}
	}

	system("pause");
	return 0;
}