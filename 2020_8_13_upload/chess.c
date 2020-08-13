#include "chess.h"

void Menu()//游戏菜单
{
	printf("********************************************\n");
	printf("*********** 欢迎来到三子棋游戏！************\n");
	printf("********************************************\n");
	printf("******1.Play!                  2.Exit!******\n");
	printf("********************************************\n");
	printf("Please enter your selection: ");
}

void InitBoard(char board[][COL], int row, int col)//清空游戏棋盘
{
	int i = 0;
	for (; i < row; i++){
		int j = 0;
		for (; j < col; j++){
			board[i][j] = ' ';
		}
	}
}

void ShowBoard(char board[][COL], int row, int col)//显示游戏棋盘
{
	printf("----------------\n");
	printf("   | 1 | 2 | 3 |\n");
	int i = 0;
	for (; i < row; i++){
		printf("----------------\n");
		printf(" %d | %c | %c | %c |\n", i + 1, board[i][0], board[i][1], board[i][2]);
	}
	printf("----------------\n");
}

int PlayerMove(char board[][COL], int row, int col)//玩家落子
{
	int x = 0;
	int y = 0;
	printf("Please enter your position<x,y>: ");
	scanf("%d %d", &x, &y);
	if (x >= 1 && x <= 3 && y >= 1 && y <= 3){
		if (board[x - 1][y - 1] != ' '){
			return 2;//玩家输入坐标位置已被占用
		}
		board[x - 1][y - 1] = PLAYER_PIECE;
		return 0;//玩家正常落子
	}
	else{
		return 1;//玩家输入坐标有误
	}
}

void ComputerMove(char board[][COL], int row, int col)//电脑落子
{
	while (1){
		int i = rand() % row;
		int j = rand() % col;//使电脑在棋盘范围内随机落子
		if (board[i][j] == ' '){
			board[i][j] = COMPUTER_PIECE;
			break;
		}
	}
	Sleep(500);
	printf("Computer done!\n");//提示玩家电脑落子完毕
}

char JudgeResult(char board[][COL], int row, int col)//判断游戏结果
{
	int i = 0;
	for (; i < row; i++){
		if (board[i][0] != ' '&& board[i][0] == board[i][1] && board[i][1] == board[i][2]){
			return board[i][0];//检查各行是否三子连珠
		}
	}
	for (i = 0; i < col; i++){
		if (board[0][i] != ' '&& board[0][i] == board[1][i] && board[1][i] == board[2][i]){
			return board[0][i];//检查各列是否三子连珠
		}
	}
	if (board[0][0] != ' '&& board[0][0] == board[1][1] && board[1][1] == board[2][2]){
		return board[0][0];//检查对角线1是否三子连珠
	}
	if (board[0][2] != ' '&& board[0][2] == board[1][1] && board[1][1] == board[2][0]){
		return board[0][2];//检查对角线2是否三子连珠
	}
	for (i = 0; i < row; i++){
		int j = 0;
		for (; j < col; j++){
			if (board[i][j] ==' '){
				return 'N';//没有产生结果并且棋盘还有空位置，则继续
			}
		}
	}
	return 'E';//没有产生结果并且棋盘已被占满，则为平局
}

void Game()//游戏函数
{
	printf("Game begin!\n");
	char board[ROW][COL];//定义一个三行三列的数组
	InitBoard(board,ROW,COL);
	int result = 'N';
	srand((unsigned long)time(NULL));//产生随机数，供电脑落子
	while (1){
		ShowBoard(board, ROW, COL);
		int ret = PlayerMove(board, ROW, COL);
		if (1 == ret){
			printf("Enter erorr!Please enter again<x,y>:\n");
			continue;
		}
		else if (2 == ret){
			printf("The position you entered are occupied!Please enter again!\n");
			continue;
		}
		else{
			printf("Player done!\n");//玩家落子完毕
		}
		result = JudgeResult(board, ROW, COL);
		if (result != 'N'){
			break;//如果返回值不为'N'(即已产生结果或平局),则跳出循环,进行结果判断
		}
		ComputerMove(board, ROW, COL);
		result = JudgeResult(board, ROW, COL);
		if (result != 'N'){
			break;//同上
		}
	}
	ShowBoard(board, ROW, COL);//产生结果之后显示最终游戏面板
	printf("Game end!\n");
	//判定游戏结果:
	switch (result){
	case 'E':
		printf("You got a draw with the computer!\n");//平局
		break;
	case PLAYER_PIECE://三子连珠时返回玩家旗子则代表玩家获胜
		printf("Congratulations, you won!\n");
		break;
	case COMPUTER_PIECE://三子连珠时返回电脑旗子则代表电脑获胜
		printf("Sorry,you lost the game!\n");
		break;
	default:
		break;
	}
	printf("Do you want to play again?\n");//提示玩家要不要再来一局

}
