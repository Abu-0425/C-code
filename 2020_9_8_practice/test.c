#include <stdio.h>
#include <assert.h>
#include <windows.h>

int fun(int *arr, int num)
{
	assert(arr);
	assert(num > 0);
	int max = 0;
	int temp = 0;
	for (int i = 0; i < num; i++) {
		if (temp <= 0) {
			temp = arr[i];
		}
		else {
			temp += arr[i];
		}
		if (max < temp) {
			max = temp;
		}
	}
	return max;
}

//char *myString()
//{
//	char buffer[6] = { 0 };
//	char *s = "Hello World!";
//	for (int i = 0; i < sizeof(buffer)-1; i++)
//	{
//		buffer[i] = *(s + i);
//	} 
//	return buffer;
//}

int fun1(char *s)
{
	char *p = s;
	while (*p != '\0'){
		p++;
	} 
	return(p - s);
}
//char* fun2()
//{
//	char str[] = "hello world";
//	return str;
//}

char findFirstRepeat(const char *str, int n)
{
	char temp[16];
	temp[0] = *str;
	int i = 1;
	for (; i < n; i++) {
		int j = 0;
		for (; j < i; j++) {
			if (*(str + i) == temp[j]) {
				return *(str + i);
			}
			else {
				temp[i] = *(str + i);
			}
		}
	}
	return '\0';//表示没有重复项
}

int f(int x, int y)
{
	return (x&y) + ((x^y) >> 1);
}
int main()
{
	int result = f(2, 4);
	printf("%d\n", result);
	//const char *str = "qywyer23tdd";
	//int n = strlen(str);
	//printf("%c\n",findFirstRepeat(str, n));
	//const int i = 0;
	//int *j = (int *)&i;
	//*j = 1;
	//printf("%d,%d", i, *j);
	//1010 0101
	//0101 1010
	//0000 0101
	//0000 0001
	//unsigned char a = 0xA5;
	//printf("%d\n", ~a);
	//unsigned char b = ~a >> 4 + 1;
	//printf("%d\n", b);
	
	//int arr1[4] = { 0 };
	//int arr2[4] = { 1 };
	//printf("%s\n", fun2());
	//printf("%d\n", fun1("goodbye!"));
	//char a[1000];
	//int i;
	//for (i = 0; i<1000; i++)
	//{
	//	a[i] = (char)(-1 - i);
	//} 
	//printf("%d\n", strlen(a));
	//int i = 1;
	//printf("%d,%d\n", sizeof(i++), i);
	//printf("%d\n", sizeof(i + 1));
	//printf("%s\n", myString());
	//int arr[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	//int num = sizeof(arr) / sizeof(arr[0]);
	//printf("%d\n", fun(arr, num));
	system("pause");
	return 0;
}