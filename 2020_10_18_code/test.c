#include <stdio.h>
#include <assert.h>
#include <windows.h>

#pragma warning(disable:4996)

void Reverse(char *str, int start, int end)
{
	while (start < end){
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++, end--;
	}
}
void LeftRotate(char *str, int len, int num)
{
	assert(str);
	assert(len > 0);
	assert(num >= 0);
	num %= len;//去重
	//逆置[0, num-1]
	Reverse(str, 0, num - 1);
	//逆置[num, len-1]
	Reverse(str, num, len - 1);
	//整体逆置[0, len-1]
	Reverse(str, 0, len - 1);
	//方法1
	//while (num){
	//	char temp = str1[0];
	//	int i = 0;
	//	for (; i < len - 1; i++){
	//		str1[i] = str1[i + 1];
	//	}
	//	str1[i] = temp;
	//	num--;
	//}
}
int main()
{
	char str[] = "abcd1234";
	int len = strlen(str);
	int num = 0;
	printf("请输入你想左旋的次数：");
	scanf("%d", &num);
	printf("before: %s\n", str);
	char *double_string = (char*)malloc(2 * len + 1);//申请一段动态内存空间以放置双倍串
	assert(double_string);//检验空间是否申请成功
	strcpy(double_string, str);//先将str拷贝给double_string
	strcat(double_string, str);//再将str拼接至double_string，即完成了双倍串的构建
	strncpy(str, double_string + num, len);//使用strncpy完成对应次数的左旋
	printf("after : %s\n", str);
	free(double_string);//释放之前申请的动态内存空间
	//int i = 0;
	//for (; i < len; i++){
	//	LeftRotate(str1, len, 1);
	//	if (strcmp(str1, str2) == 0){
	//		printf("Yes!\n");
	//		break;
	//	}
	//}
	//if (i == len){
	//	printf("No!\n");
	//}
	system("pause");
	return 0;
}