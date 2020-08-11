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

void InitBoard(char show_board[][COL], int row, int col, char elem)//��ʼ�����
{
	int i = 0;
	for (; i < row; i++){
		int j = 0;
		for (; j < col; j++){
			show_board[i][j] = elem;//�ֱ𴫵ݲ�ͬ��ʵ�ο��Էֱ��ʼ����Ϸ���Ͳ������
		}
	}
}

void SetMine(char mine_board[][COL], int row, int col)//������׺���
{
	int n = MINE_NUM;
	while (n){//���ײ�����֮�����ѭ��
		int x = rand() % (row - 2) + 1;
		int y = rand() % (col - 2) + 1;//ʹ�������������ȷ�ķ�Χ��
		if (mine_board[x][y] == '1'){
			continue;//���һ��λ���Ѿ����ף���������һ��λ��
		}
		mine_board[x][y] = '1';//����
		n--;
	}
}

void ShowBoard(char show_board[][COL], int row, int col)//��ӡ��Ϸ���
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
char GetNum(char mine_board[][COL], int x, int y)//��ȡ��Χ����
{
	//����'1' - '0'= 1��֪�����������Χ�����������е��������֮���ټ�ȥ8*'0'
	//���ɵõ���Χ�׵�����(����)�����ټ�ȥ1��'0'���Ǹ����ֶ�Ӧ���ַ�����
	return mine_board[x - 1][y - 1] + mine_board[x - 1][y] + mine_board[x - 1][y + 1] + \
		   mine_board[x][y - 1] + mine_board[x][y + 1] + \
		   mine_board[x + 1][y - 1] + mine_board[x + 1][y] + mine_board[x + 1][y + 1] - 7 * '0';
}


void Extend(char show_board[][COL], char mine_board[][COL], int row, int col, int x, int y)
{
	if (GetNum(mine_board, x, y)=='0')//����GetNum������������Χ�׵ĸ�������Ϊ'0'������Ҫչ��
	{
		show_board[x][y] = ' ';
		int i = 0;
		int j = 0;
		for (i = x - 1; i <= x + 1; i++)
		{
			for (j = y - 1; j <= y + 1; j++)
			{
				if (show_board[i][j] == '*' &&\
					i >= 1 && i <= (row-2) && j >= 1 && j <= (col-2))//����λ��δ��ɨ���������̷�Χ��������ݹ����Extend����
					Extend(show_board, mine_board, ROW, COL, i, j);
			}
		}
	}
	else {
		show_board[x][y] = GetNum(mine_board, x, y);//������Ҫչ������Ϊ��λ�ø�ֵ��Χ�׵ĸ���
	}
}

int Judge(char show_board[][COL], int row, int col) //Judge�������ж��û��Ƿ�ɨ�׳ɹ�
{
	int i = 1;
	int j = 1;
	int count = 0;
	for (; i <= row - 2; i++) {
		for (j = 1; j <= col - 2; j++) {
			if (show_board[i][j] == '*') {
				count++;
			}//��������Ԫ�أ�����λ��δ��ɨ�������¼������
			if (count > MINE_NUM) {
				return 0;
			}//��δ��ɨ���ĸ��������׵ĸ���������Ϸ������
		}
	}
	return 1;//˵��ɨ�׳ɹ�
}

void Game()
{
	srand((unsigned long)time(NULL));//��������������ڲ���
	char show_board[ROW][COL];//������ʾ����ҵ���Ϸ���
	char mine_board[ROW][COL];//������ʾ�׷ֲ������
	InitBoard(show_board, ROW, COL, '*');//��չʾ����ҵ���Ϸ����ʼ��ȫ'*'
	InitBoard(mine_board, ROW, COL, '0'); //�Ѳ��׵�����ʼ��Ϊȫ'0'(��'0'��ʾ���ף���'1'��ʾ����)
	SetMine(mine_board, ROW, COL);//����
	do{
		system("cls");//ˢ�µ�ǰ���棬ʹ��Ϸ�������
		int x = 0;
		int y = 0;
		ShowBoard(show_board, ROW, COL);//����Ϸ���չʾ�����
		printf("Please enter the location you want to sweep<x,y>: ");
		scanf("%d %d", &x, &y);
		if (x < 1 || x > 10 || y < 1 || y > 10){
			printf("Enter erorr!Please enter again!\n");//��ʾ����������������
			Sleep(2000);//���ڽ����ˢ�£���ͣ��2��ʹ��ҿ�����ʾ
			continue;
		}
		if (show_board[x][y] != '*'){
			printf("The position you entered has been swept!Please enter again!\n");
			Sleep(2000);//���ڽ����ˢ�£���ͣ��2��ʹ��ҿ�����ʾ
			continue;//��ʾ��Ҵ�λ���Ѿ�ɨ����
		}
		if (mine_board[x][y] == '1'){
			printf("There is a mine in <%d,%d>!\n", x, y);
			printf("Sorry! You lost the game!\n");//ɨ��ʧ��
			ShowBoard(mine_board, ROW, COL);//ʧ��֮�������չʾ������壬���������ķ��ڷ�
			break;
		}
		Extend(show_board, mine_board, ROW, COL, x, y);//û�вȵ������ж��Ƿ���Ҫչ��
		if (1 == Judge(show_board, ROW, COL)){
			printf("Congratulations! You made it!\n");//ɨ�׳ɹ�
			ShowBoard(mine_board, ROW, COL);//ɨ�׳ɹ�֮��Ҳ�����չʾ�������
			break;
		}
	}while(1);

}