#include "mine.h"

void Menu()
{
	printf("**********************************\n");
	printf("*** Welcome to mine clearance! ***\n");
	printf("**********************************\n");
	printf("***1.Play!              2.Exit!***\n");
	printf("**********************************\n");
	printf("Please enter your selection: ");
}

void InitBoard(char show_board[][COL], int row, int col, char elem)//初始化面板
{
	int i = 0;
	for (; i < row; i++){
		int j = 0;
		for (; j < col; j++){
			show_board[i][j] = elem;//分别传递不同的实参可以分别初始化游戏面板和布雷面板
		}
	}
}

void SetMine(char mine_board[][COL], int row, int col)//随机布雷函数
{
	int n = MINE_NUM;
	while (n){//当雷布置完之后结束循环
		int x = rand() % (row - 2) + 1;
		int y = rand() % (col - 2) + 1;//使随机布的雷在正确的范围内
		if (mine_board[x][y] == '1'){
			continue;//如果一个位置已经有雷，则重新找一个位置
		}
		mine_board[x][y] = '1';//布雷
		n--;
	}
}

void ShowBoard(char show_board[][COL], int row, int col)//打印游戏面板
{
	int i = 1;
	printf("----");
	for (i = 1; i <= col - 2; i++){
		printf("%3s", "----");
	}
	printf("\n");
	printf("   |");
	for (i = 1; i <= col - 2; i++){
		printf(" %-2d|", i);
	}
	printf("\n");
	printf("----");
	for (i = 1; i <= col - 2; i++){
		printf("%3s", "----");
	}
	printf("\n");

	for (i = 1; i <= row - 2; i++){
		printf(" %2d|", i);
		int j = 1;
		for (; j <= col - 2; j++){
			printf(" %-2c|", show_board[i][j]);
		}
		printf("\n");
		for (j = 1; j <= col - 2; j++){
			printf("%3s", "----");
		}
		printf("----\n");
	}
}
char GetNum(char mine_board[][COL], int x, int y)//获取周围雷数
{
	//根据'1' - '0'= 1可知将这个坐标周围的所有坐标中的内容相加之后再减去8*'0'
	//即可得到周围雷的数量(整形)，则少减去1个'0'就是该数字对应的字符类型
	return mine_board[x - 1][y - 1] + mine_board[x - 1][y] + mine_board[x - 1][y + 1] + \
		   mine_board[x][y - 1] + mine_board[x][y + 1] + \
		   mine_board[x + 1][y - 1] + mine_board[x + 1][y] + mine_board[x + 1][y + 1] - 7 * '0';
}


void Extend(char show_board[][COL], char mine_board[][COL], int row, int col, int x, int y)
{
	if (GetNum(mine_board, x, y)=='0')//调用GetNum函数，计算周围雷的个数，若为'0'，则需要展开
	{
		show_board[x][y] = ' ';
		int i = 0;
		int j = 0;
		for (i = x - 1; i <= x + 1; i++)
		{
			for (j = y - 1; j <= y + 1; j++)
			{
				if (show_board[i][j] == '*' &&\
					i >= 1 && i <= (row-2) && j >= 1 && j <= (col-2))//若该位置未被扫过且在棋盘范围内则继续递归调用Extend函数
					Extend(show_board, mine_board, ROW, COL, i, j);
			}
		}
	}
	else {
		show_board[x][y] = GetNum(mine_board, x, y);//若不需要展开，则为该位置赋值周围雷的个数
	}
}

int Judge(char show_board[][COL], int row, int col) //Judge函数，判定用户是否扫雷成功
{
	int i = 1;
	int j = 1;
	int count = 0;
	for (; i <= row - 2; i++) {
		for (j = 1; j <= col - 2; j++) {
			if (show_board[i][j] == '*') {
				count++;
			}//遍历棋盘元素，若该位置未被扫过，则记录下来。
			if (count > MINE_NUM) {
				return 0;
			}//若未被扫过的个数大于雷的个数，则游戏继续。
		}
	}
	return 1;//说明扫雷成功
}

void Game()
{
	srand((unsigned long)time(NULL));//种随机数种子用于布雷
	char show_board[ROW][COL];//定义显示给玩家的游戏面板
	char mine_board[ROW][COL];//定义显示雷分布的面板
	InitBoard(show_board, ROW, COL, '*');//把展示给玩家的游戏面板初始化全'*'
	InitBoard(mine_board, ROW, COL, '0'); //把布雷的面板初始化为全'0'(用'0'表示无雷，用'1'表示有雷)
	SetMine(mine_board, ROW, COL);//布雷
	do{
		system("cls");//刷新当前界面，使游戏体验更佳
		int x = 0;
		int y = 0;
		ShowBoard(show_board, ROW, COL);//将游戏面板展示给玩家
		printf("Please enter the location you want to sweep<x,y>: ");
		scanf("%d %d", &x, &y);
		if (x < 1 || x > 10 || y < 1 || y > 10){
			printf("Enter erorr!Please enter again!\n");//提示玩家输入的坐标有误
			Sleep(2000);//由于界面会刷新，则停顿2秒使玩家看到提示
			continue;
		}
		if (show_board[x][y] != '*'){
			printf("The position you entered has been swept!Please enter again!\n");
			Sleep(2000);//由于界面会刷新，则停顿2秒使玩家看到提示
			continue;//提示玩家此位置已经扫过了
		}
		if (mine_board[x][y] == '1'){
			printf("There is a mine in <%d,%d>!\n", x, y);
			printf("Sorry! You lost the game!\n");//扫雷失败
			ShowBoard(mine_board, ROW, COL);//失败之后向玩家展示布雷面板，让玩家输的心服口服
			break;
		}
		Extend(show_board, mine_board, ROW, COL, x, y);//没有踩到雷则判断是否需要展开
		if (1 == Judge(show_board, ROW, COL)){
			printf("Congratulations! You made it!\n");//扫雷成功
			ShowBoard(mine_board, ROW, COL);//扫雷成功之后也向玩家展示布雷面板
			break;
		}
	}while(1);

}