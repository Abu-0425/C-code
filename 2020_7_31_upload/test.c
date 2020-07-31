#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

int Sn(int a)
{
	int sum = 0;
	int flag = 0;
	int i = 0;
	for (; i < 5; i++){
		flag = flag * 10 + a;
		sum += flag;
	}
	return sum;
}
void Reverse(char *str)
{
	if (NULL == str){
		return;
	}
	char *head = str;
	char *end = str + strlen(str) - 1;
	while (head < end){
		char temp = *head;
		*head = *end;
		*end = temp;
		head++, end--;
	}
}
int main()
{
	int a = 0;
	printf("Please enter your 'a': ");
	scanf("%d", &a);
	int ret = Sn(a);
	printf("result: %d\n", ret);
	//code1:×Ö·û´®ÄæÐò
	//char str[] = "helloworld";
	//printf("before: %s\n", str);
	//Reverse(str);
	//printf("after : %s\n", str);

	system("pause");
	return 0;
}