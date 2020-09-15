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

char *delBlank(char *str)
{
	assert(str);
	char *p = str;
	int flag = 0;//标志位
	int i = 0;
	while (str[i]) {
		if (!flag && str[i] == ' ') {
			i++;
		}
		else if (!flag && str[i] != ' ') {
			flag = 1;
			*p++ = str[i++];
		}
		else if (flag && str[i] != ' ') {
			flag = 1;
			*p++ = str[i++];
		}
		else { //相当于(flag && str[i] == ' ')
			flag = 0;
			*p++ = str[i++];
		}
	}
	if (*(p - 1) == ' ') {
		*(p - 1) = '\0';
	}
	else {
		*p = '\0';
	}
	//printf("%d\n", strlen(str));
	return str;
}


int main()
{
	char str[] = "   hello   world!      ";
	//"hello world!"
	char *p = delBlank(str);
	printf("%s\n", p);

	//int s = 0, n;
	//for (n = 0; n<4; n++)
	//{
	//	switch (n)
	//	{
	//	default:s += 4;
	//	case 1:s += 1;
	//	case 2:s += 2;
	//	case 3:s += 3;
	//	}
	//} 
	//printf("%d\n", s);//24
	//int a = 2, i, k;
	//for (i = 0; i < 2; i++){
	//	k = Func(a++);
	//} 
	//printf("%d\n", k);//4
	//printf("%d\n", fun(2019));//8(计算该数字二进制中1的个数)
	//int arr[][3] = { 1, 2, 3, 4, 5, 6 };
	//char str[] = "xxxyyyyz"; 
	//strCompress(str);

	//int x = 4;
	//x += x *= x + x;
	//printf("%d\n", x);

	system("pause");
	return 0;
}