#include "chess.h"

void Menu()//��Ϸ�˵�
{
	printf("********************************************\n");
	printf("*********** ��ӭ������������Ϸ��************\n");
	printf("********************************************\n");
	printf("******1.Play!                  2.Exit!******\n");
	printf("********************************************\n");
	printf("Please enter your selection: ");
}

void InitBoard(char board[][COL], int row, int col)//�����Ϸ����
{
	int i = 0;
	for (; i < row; i++){
		int j = 0;
		for (; j < col; j++){
			board[i][j] = ' ';
		}
	}
}

void ShowBoard(char board[][COL], int row, int col)//��ʾ��Ϸ����
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

int PlayerMove(char board[][COL], int row, int col)//�������
{
	int x = 0;
	int y = 0;
	printf("Please enter your position<x,y>: ");
	scanf("%d %d", &x, &y);
	if (x >= 1 && x <= 3 && y >= 1 && y <= 3){
		if (board[x - 1][y - 1] != ' '){
			return 2;//�����������λ���ѱ�ռ��
		}
		board[x - 1][y - 1] = PLAYER_PIECE;
		return 0;//�����������
	}
	else{
		return 1;//���������������
	}
}

void ComputerMove(char board[][COL], int row, int col)//��������
{
	while (1){
		int i = rand() % row;
		int j = rand() % col;//ʹ���������̷�Χ���������
		if (board[i][j] == ' '){
			board[i][j] = COMPUTER_PIECE;
			break;
		}
	}
	Sleep(500);
	printf("Computer done!\n");//��ʾ��ҵ����������
}

char JudgeResult(char board[][COL], int row, int col)//�ж���Ϸ���
{
	int i = 0;
	for (; i < row; i++){
		if (board[i][0] != ' '&& board[i][0] == board[i][1] && board[i][1] == board[i][2]){
			return board[i][0];//�������Ƿ���������
		}
	}
	for (i = 0; i < col; i++){
		if (board[0][i] != ' '&& board[0][i] == board[1][i] && board[1][i] == board[2][i]){
			return board[0][i];//�������Ƿ���������
		}
	}
	if (board[0][0] != ' '&& board[0][0] == board[1][1] && board[1][1] == board[2][2]){
		return board[0][0];//���Խ���1�Ƿ���������
	}
	if (board[0][2] != ' '&& board[0][2] == board[1][1] && board[1][1] == board[2][0]){
		return board[0][2];//���Խ���2�Ƿ���������
	}
	for (i = 0; i < row; i++){
		int j = 0;
		for (; j < col; j++){
			if (board[i][j] ==' '){
				return 'N';//û�в�������������̻��п�λ�ã������
			}
		}
	}
	return 'E';//û�в���������������ѱ�ռ������Ϊƽ��
}

void Game()//��Ϸ����
{
	printf("Game begin!\n");
	char board[ROW][COL];//����һ���������е�����
	InitBoard(board,ROW,COL);
	int result = 'N';
	srand((unsigned long)time(NULL));//���������������������
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
			printf("Player done!\n");//����������
		}
		result = JudgeResult(board, ROW, COL);
		if (result != 'N'){
			break;//�������ֵ��Ϊ'N'(���Ѳ��������ƽ��),������ѭ��,���н���ж�
		}
		ComputerMove(board, ROW, COL);
		result = JudgeResult(board, ROW, COL);
		if (result != 'N'){
			break;//ͬ��
		}
	}
	ShowBoard(board, ROW, COL);//�������֮����ʾ������Ϸ���
	printf("Game end!\n");
	//�ж���Ϸ���:
	switch (result){
	case 'E':
		printf("You got a draw with the computer!\n");//ƽ��
		break;
	case PLAYER_PIECE://��������ʱ������������������һ�ʤ
		printf("Congratulations, you won!\n");
		break;
	case COMPUTER_PIECE://��������ʱ���ص��������������Ի�ʤ
		printf("Sorry,you lost the game!\n");
		break;
	default:
		break;
	}
	printf("Do you want to play again?\n");//��ʾ���Ҫ��Ҫ����һ��

}
