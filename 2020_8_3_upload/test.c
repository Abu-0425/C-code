#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

int main()
{
	int line = 0;
	int i = 0;
	scanf("%d", &line);//7
	//1. 打印上半部分
	for (i = 0; i<line; i++)
	{
		//打印一行
		//1. 打印空格
		int j = 0;
		for (j = 0; j<line - 1 - i; j++)
		{
			printf(" ");
		}
		//2. 打印*
		for (j = 0; j<2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	//2. 打印下半部分
	for (i = 0; i<line - 1; i++)
	{
		//打印一行
		//1. 打印空格
		int j = 0;
		for (j = 0; j<i + 1; j++)
		{
			printf(" ");
		}
		//2. 打印*
		for (j = 0; j<2 * (line - 1 - i) - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	//char str[] = "             ";  //定义为空

	//int i = 0, j = 0;
	//for (i = (strlen(str) / 2), j = (strlen(str) / 2); i >= 0 && j <= strlen(str); i--, j++)
	//{
	//	str[i] = '*';
	//	str[j] = '*';
	//	printf("%s\n", str);
	//}
	//for (i = 0, j = (strlen(str) - 1); i<(strlen(str) / 2) && j >= (strlen(str) / 2); i++, j--)
	//{
	//	str[i] = ' ';
	//	str[j] = ' ';
	//	printf("%s\n", str);
	//}

	//int i = 0;
	//for (; i <= 100000; i++){
	//	int n = 1;
	//	int sum = 0;
	//	int tmp = i;
	//	while (tmp / 10){
	//		n++;
	//		tmp /= 10;
	//	}
	//	tmp = i;
	//	while (tmp){
	//		sum += pow(tmp % 10, n);
	//		tmp /= 10;
	//	}
	//	if (sum == i){
	//		printf("%d ", i);
	//	}
	//}
	//printf("\n");

	system("pause");
	return 0;
}