#include <stdio.h>
#include <assert.h>
#include <windows.h>

#pragma warning(disable:4996)

void strSwitch(char *str1, char *str2)
{
	assert(str1);
	assert(str2);
	while (*str1 != '\0') {
		if (*str1 != ' ') {
			*str2 = *str1;
			str2++;
		}
		else {
			strcpy(str2, "%20");
			str2 += 3;
		}
		str1++;
	}
	*str2 = '\0';
}

int fib(int n)
{
	int first = 1;
	int second = 1;
	int third = 1;
	while (n > 2) {
		third = first + second;
		first = second;
		second = third;
		n--;
	}
	return third;
}
enum ENUM_A {
	X1,
	Y1,
	Z1 = 5,
	A1,
	B1
};
enum ENUM_A enumA = Y1;
enum ENUM_A enumB = B1;

int fun(int x, int y)
{
	static int m = 0;
	static int i = 2;
	i += m + 1;
	m = i + x + y;
	return m;
}

int countOne(int x)
{
	int count = 0;
	int i = 0;
	while (i < 32) {
		if ((x & (0x1 << i)) != 0) {
			count++;
			i++;
		}
		else {
			i++;
		}
	}
	return count;
}

int Change(int *pX)
{
	int y = 8;
	y = y - *pX;
	pX = &y;
	printf("%d\n", *pX);//5
	return 0;
}

int fun1(int x)
{
	int count = 0;
	while (x){
		count++;
		x = x & (x - 1);
	} 
	return count;
}
//#pragma pack(4)
//#define F(X,Y) ((X)+(Y))
#define CIR(r) r*r
int main()
{
	//int a = 1;
	//int b = 2;
	//int t;
	//t = CIR(a + b);
	//printf("%d\n", t);//5
	printf("fun(2019)=%d\n", fun1(2019));//8
	//char arr[2][4];
	//strcpy((char*)arr, "you");
	//strcpy(arr[1], "me");
	//arr[0][3] = '&';
	//printf("%s\n", arr);
	//int xx = 3;
	//int *pY = &xx;
	//Change(pY);
	//printf("%d\n", *pY);//3
	//unsigned int x = 0;
	//scanf("%d", &x);
	//printf("%d\n", countOne(x));
	//int j = 4;
	//int m = 1;
	//int k;
	//k = fun(j, m);
	//printf("%d,", k);
	//k = fun(j, m);
	//printf("%d\n", k);
	//printf("%d\n", X1);
	//printf("%d\n", enumA);
	//printf("%d\n", B1);
	//printf("%d\n", enumB);
	//printf("%d\n", sizeof(long));
	//printf("%d\n", sizeof(double));
	//printf("%d\n", sizeof(long long));
	//struct tagTest1
	//{
	//	short a;
	//	char d;
	//	long b;
	//	long c;
	//};
	//struct tagTest2
	//{
	//	long b;
	//	short c;
	//	char d;
	//	long a;
	//};
	//struct tagTest3
	//{
	//	short c;
	//	long b;
	//	char d;
	//	long a;
	//};
	//struct tagTest1 stT1;
	//struct tagTest2 stT2;
	//struct tagTest3 stT3;
	//printf("%d %d %d", sizeof(stT1), sizeof(stT2), sizeof(stT3));
	//int a = 3, b = 4;
	//printf("%d\n", F(a++, b++));
	//char a[20];
	//char *p1 = (char *)a;
	//char *p2 = (char*)(a + 5);
	//int n = p2 - p1;
	//int n = 0;
	//scanf("%d", &n);
	//int ret = fib(n);
	//printf("%d\n", ret);
	//char acHello[] = "hello\0world"; 
	//char acNew[15] = { 0 }; 
	//strcpy(acNew, acHello);
	//printf("%d\n", strlen(acNew));
	//printf("%d\n", sizeof(acHello));
	//int a = 5;
	//if (a = 0) {
	//	printf("%d\n", a - 10);
	//}
	//else {
	//	printf("%d\n", a++);
	//}
	//char str1[] = "abc defgx yz";
	//char str2[32];
	//strSwitch(str1,str2);
	//printf("%s\n", str2);
	system("pause");
	return 0;
}