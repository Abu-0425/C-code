#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#pragma warning(disable:4996)
union {
	short k;
	char i[2];
}*s, a;

//unsigned short *sum(unsigned char a, unsigned char b)
//{
//	unsigned short s = 0;
//	s = a + b;
//	return &s;
//}
void Test()
{
	char pcArray[10];
	strncpy(pcArray, "hello", 6);
	printf("%s\n", pcArray);
	return;
}

bool isPow(int m)
{
	if (m < 1) {
		return false;
	}
	int n = m & (m - 1);
	return n == 0;
}

int main()
{
	int m = 0;
	scanf("%d", &m);
	if (isPow(m)) {
		printf("Yes!\n");
	}
	else {
		printf("No!\n");
	}
	//int i, x, y;
	//i = x = y = 0;
	//do {
	//	++i;
	//	if (i % 2)
	//		x += i,
	//	    i++;
	//	y += i++;
	//} while (i <= 7);
	//printf("%d %d %d", i, x, y);//9,1,20
	//double c = (double)(10 / 4 * 4);
	//printf("%d\n", (double)(10 / 4 * 4));
	//char ch = -1;
	//printf("%d\n", ch);
	//int i = 6;
	//if (i <= 6)
	//	printf("hello\n");
	//else
	//	printf("bye-bye\n");
	//Test();
	//char str[4] = "abcd";
	//unsigned short *p = NULL;
	//unsigned char a = 1, b = 2;
	//p = sum(a, b);
	//printf("%u + %u", a, b);
	//printf(" = %u\n", *p);

	//char a = 128;
	//unsigned char b = 128;
	//short c = a + b;
	//short d = (unsigned char)a + b;
	//short e = a + (char)b;
	//int a;
	//char str[4] = "adcd";
	//printf("%d\n", strlen(str));
	//s = &a;
	//a.i[0] = 0x39;
	//a.i[1] = 0x38;
	//printf("%x\n", a.k);
	system("pause");
	return 0;
}