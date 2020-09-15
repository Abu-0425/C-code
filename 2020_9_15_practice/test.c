#include <stdio.h>
#include <assert.h>
#include <windows.h>

void strCompress(char *str)
{
	assert(str);
	int len = strlen(str);
	int count = 1;
	int i = 0;
	for (; i < len; i++) {
		if (str[i] == str[i + 1]) {
			count++;
		}
		else {
			if (count == 1) {
				printf("%c", str[i]);
			}
			else {
				printf("%d%c", count, str[i]);
			}
			count = 1;
		}
	}
	printf("\n");
}

int fun(int x)
{
	int count = 0;
	while (x){
		count++;
		x = x &(x - 1);
	}
	return count;
}

int Func(int a)
{
	int b = 0;
	static int c = 3;
	a = c++, b++;
	return (a);
}

int main()
{
	int s = 0, n;
	for (n = 0; n<4; n++)
	{
		switch (n)
		{
		default:s += 4;
		case 1:s += 1;
		case 2:s += 2;
		case 3:s += 3;
		}
	} 
	printf("%d\n", s);
	//int a = 2, i, k;
	//for (i = 0; i < 2; i++){
	//	k = Func(a++);
	//} 
	//printf("%d\n", k);
	//printf("%d\n", fun(2019));
	//int arr[][3] = { 1, 2, 3, 4, 5, 6 };
	//char str[] = "xxxyyyyz"; 
	//strCompress(str);

	//int x = 4;
	//x += x *= x + x;
	//printf("%d\n", x);

	system("pause");
	return 0;
}