#include<stdio.h>
#include<windows.h>

int main()
{

	int i = 0;
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (i = 0; i <= 12; i++)
	{
		arr[i] = 0;
		printf("hello bit\n");
	}
	//int money = 20;
	//int total = money;
	//int empty = money;
	//while (empty >= 2)
	//{
	//	total += empty / 2;
	//	empty = empty / 2 + empty % 2;
	//}
	//printf("总共可以喝%d瓶汽水\n", total);
	system("pause");
	return 0;
}
/*
#include <stdio.h>
#include <assert.h>
#include <windows.h>

#define SIZE 32


void SwitchArr(int *arr, int num)
{
	int start = 0;
	int end = num - 1;
	while (start < end){
		while ((start < end) && (arr[start] % 2 != 0)){
			start++;
		}
		while ((start < end) && (arr[end] % 2 == 0)){
			end--;
		}
		if (start < end){
			int temp = arr[start];
			arr[start] = arr[end];
			arr[end] = temp;
		}
	}
	int i = 0;
	for (; i < num; i++){
		printf("%d ", arr[i]);//打印调整位置后的数组
	}
	printf("\n");
	
}
char *MyStrcpy(char *dest, const char *src)
{
	char *ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest++ = *src++){
		;
	}
	return ret;
}
//递归方案
int MyStrlen1(const char *str1)
{
	assert(str1 != NULL);
	if (*str1 == '\0'){
		return 0;
	}
	return 1 + MyStrlen1(str1 + 1);
}
//非递归方案
int MyStrlen2(const char *str2)
{
	assert(str2 != NULL);
	int i = 0;
	while (str2[i] != '\0'){
		i++;
	}
	return i;
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int num = sizeof(arr) / sizeof(arr[0]);
	SwitchArr(arr, num);
	//char arr[SIZE] = { 0 };
	//const char *str = "helloworld";
	//char *ret = MyStrcpy(arr, str);
	//printf("%s\n", ret);
	//const char *str = "helloworld";
	//int ret1 = MyStrlen1(str);
	//printf("递归方案输出:  %d\n", ret1);
	//int ret2 = MyStrlen2(str);
	//printf("非递归方案输出: %d\n", ret2);

	system("pause");
	return 0;
}
*/
