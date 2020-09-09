#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <windows.h>

#pragma warning(disable:4996)

#define sum(a,b,c) a+b+c

int f(int n)
{
	static int i = 1;
	if (n >= 5)
		return n;
	n = n + i;
	i++;
	return f(n);
}

int func()
{
	int i, j, k = 0;
	for (i = 0, j = -1; j = 0; i++, j++){
		k++;
	}
	return k;
}

void DeleteStr(char *str1, char *str2)
{
	assert(str1 && str2);
	char *fast = str1;
	char *slow = str2;
	int arr[256] = { 0 };
	int  n = strlen(str2);
	int i = 0;
	for (; i < n; i++) {
		arr[str2[i]] = 1;
	}
	while (*fast) {
		if (arr[*fast] == 0) {
			*slow = *fast;
			slow++;
		}
		fast++;
	}
	*slow = '\0';
}

void isHui(int num)
{
	int n, tmp, sum = 0;
	for (n = num; n != 0; n /= 10) {
		tmp = n % 10;
		sum = sum * 10 + tmp;
	}
	if (sum == num) {
		printf("%d是回文数!\n", num);
	}
	else {
		printf("%d不是回文数!\n", num);
	}
}
void isHui(int num)
{
	int n, tmp, sum = 0;
	for (n = num; n != 0; n /= 10) {
		tmp = n % 10;
		sum = sum * 10 + tmp;
	}
	if (sum == num) {
		printf("%d是回文数!\n", num);
	}
	else {
		printf("%d不是回文数!\n", num);
	}
}
int main()
{
	int x = 1, y = 012;
	printf("%d", y*x++);
	//int x = 012;
	//printf("%d\n", x);
	//int j = 4;
	//int i = j;
	//for (; i <= 2 * j; i++)
	//{
	//	switch (i / j)
	//	{
	//	case 0:
	//	case 1:
	//		printf("*");
	//		break;
	//	case 2:
	//		printf("#");
	//	}
	//}

	//unsigned int a = 0xFFFFFFF7;
	//unsigned char i = (unsigned char)a;
	//char *b = (char *)&a;
	//printf("%08x,%08x", i, *b);
	//char str[] = "ABCDEFG";
	//char *p1, *p2;
	//p1 = "abcd"; p2 = "efgh";
	//strcpy(str + 1, p2 + 1);
	//strcpy(str + 3, p1 + 3);
	//printf("%s\n", str);
	//char a[] = "123456789", *p = a;
	//int i = 0;
	//while (*p)
	//{
	//	if (i % 2 == 0) *p = '!';
	//	i++; p++;
	//}
	//puts(a);
	//int num = 0;
	//scanf("%d", &num);
	//isHui(num);
	//int arr[] = { 6, 7, 8, 9, 10 };
	//int *ptr = arr;
	//*(ptr++) += 123;
	//printf("%d,%d", *ptr, *(++ptr));
	//int k, j, s;
	//for (k = 2; k<6; k++, k++)
	//{
	//	s = 1;
	//	for (j = k; j<6; j++)
	//		s += j;
	//} 
	//printf("%d\n", s);
	//int a = 2, *p1, **p2;
	//p2 = &p1;
	//p1 = &a;
	//a++;
	//printf("%d,%d,%d\n", a, *p1, **p2);
	//int a = 10;
	//int *p = &a;
	//int *q;
	//q = p;
	//int c[] = { 1, 3, 5 }; 
	//int *k = c + 1; 
	//printf("%d", *++k);
	//char str1[] = "They are students.";
	//char str2[] = "aeiou";
	////int  n = strlen(str2);
	//DeleteStr(str1, str2);
	//printf("%s\n", str2);
	//printf("%d\n", (func()));
	//printf("%d\n", f(1));
	//int i = 3;
	//int j = 2;
	//printf("%d\n", i*sum(i, (i + j), j));

	system("pause");
	return 0;
}