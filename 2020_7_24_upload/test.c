#include <stdio.h>
#include <windows.h>
#include <math.h>
#pragma warning(disable:4996)

//自己写一个strlen函数（由于题目要求不能用字符串操作函数）
int MyStrlen(char *string)
{
	int i = 0;
	while (string[i] != '\0'){
		i++;
	}
	return i;
}
//编写一个函数实现n的k次方，使用递归实现。
int Pow(int n,int k)
{
	if (k <= 0){
		return 1;
	}
	else{
		return n*Pow(n, k - 1);
	}
}
//写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
//输入：1729，输出：19
int DigitSum(int n)
{
	if (n>9){
		return DigitSum(n / 10) + n % 10;
	}
	else{
		return n;
	}
}
//编写一个函数 reverse_string(char * string)（递归实现）
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中的字符串操作函数。

void Reverse_string(char *string)
{
	char *start = string;
	char *end = string + MyStrlen(string) - 1;
	char temp = *start;
	*start = *end;
	*end = '\0';
	if (MyStrlen(string + 1) >= 2){
		Reverse_string(string + 1);
	}
	*end = temp;
	//if (*string == '\0'){
	//	return;
	//}
	//Reverse_string(string + 1);
	//printf("%c", *string);

}
//递归和非递归分别实现求第n个斐波那契数
//递归方案
int Fib1(int x)
{
	if (x <= 2){
		return 1;
	}
	return Fib1(x - 1) + Fib1(x - 2);
}
//非递归方案
int Fib2(int y)
{
	int first = 1;
	int second = 1;
	int third = 1;
	while (y > 2){
		third = first + second;
		first = second;
		second = third;
		y--;
	}
	return third;
}
//递归和非递归分别实现strlen
//递归方案
int MyStrlen1(const char *str1)
{
	if (*str1 == '\0'){
		return 0;
	}
	return 1 + MyStrlen1(str1 + 1);
}
//非递归方案
int MyStrlen2(const char *str2)
{
	int i = 0;
	while (str2[i] != '\0'){
		i++;
	}
	return i;
}
//递归和非递归分别实现求n的阶乘（不考虑溢出的问题）
//递归方案
int Fact1(int x)
{
	if (x == 1){
		return 1;
	}
	return x*Fact1(x - 1);
}
//非递归方案
int Fact2(int y)
{
	int fact = 1;
	for (; y > 0; y--){
		fact *= y;
	}
	return fact;
}
//递归方式实现打印一个整数的每一位
void ShowInt(int _x)
{
	if (_x > 9){
		ShowInt(_x / 10);
	}
		printf("%d ", _x % 10);
}
//实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定
//如：输入9，输出9 * 9口诀表，输入12，输出12 * 12的乘法口诀表。
void ShowMulTable(int _x)
{
	int i = 1;
	for (; i <= _x; i++){
		int j = 1;
		for (; j <= i; j++){
			printf("%d*%d=%d\t", j, i, i*j);
			if (i == j){
				printf("\n");
			}
		}
	}
}

//交换俩个整数的值
void Swap(int *_x,int *_y)
{
	int temp = 0;
	temp = *_x;
	*_x = *_y;
	*_y = temp;
}
//判断year是否为闰年
int IsLeapYear(int _year)
{
	if ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0){
		return 1;
	}
	return 0;
}
//判断一个数是否为素数
int IsPrime(int x)
{
	int i = 2;
	int top = (int)sqrt(x);
	for (; i <= top; i++){
		if (x % i == 0){
			break;
		}
	}
	if (i <=top){
		return 0;
	}
	return 1;
}
int main()
{
	//code11
	//int n = 2;
	//int k = 3;
	//printf("请分别输入整数n和k: ");
	//scanf("%d %d", &n,&k);
	//int ret = Pow(n,k);
	//printf("result:%d\n", ret);
	//code10
	//int n = 0;
	//printf("请输入一个整数: ");
	//scanf("%d", &n);
	//int ret = DigitSum(n);
	//printf("result:%d\n", ret);
	//code9
	char str[] = "ABCD1234";
	printf("before:%s\n", str);
	Reverse_string(str);
	printf("after :%s\n", str);
	//code8
	//int n = 0;
	//printf("你想求第几个斐波那契数？请输入一个整数：");
	//scanf("%d", &n);
	//int ret1 = Fib1(n);
	//printf("递归方案输出：  %d\n", ret1);
	//int ret2 = Fib2(n);
	//printf("非递归方案输出：%d\n", ret2);
	//code7
	//char *str = "helloworld";
	//int ret1 = MyStrlen1(str);
	//printf("递归方案输出：  %d\n", ret1);
	//int ret2 = MyStrlen2(str);
	//printf("非递归方案输出：%d\n", ret2);
	//code6
	//int n = 0;
	//printf("请输入你要求的阶乘：");
	//scanf("%d", &n);
	//int ret1 = Fact1(n);
	//printf("递归方案输出：  %d!=%d\n", n, ret1);
	//int ret2 = Fact2(n);
	//printf("非递归方案输出：%d!=%d\n", n, ret2);
	//code5
	//int x = 0;
	//printf("请输入你想打印的整数：");
	//scanf("%d", &x);
	//ShowInt(x);
	//code4
	//int x = 0;
	//printf("请问你想看几乘几的乘法口诀表？请输入一个整数：");
	//scanf("%d", &x);
	//ShowMulTable(x);
	//code3
	//int x = 10;
	//int y = 20;
	//printf("交换前：%d,%d\n", x, y);
	//Swap(&x, &y);
	//printf("交换后：%d,%d\n", x, y);
	//code2
	//int year = 0;
	//printf("请输入你要判断的年份：");
	//scanf("%d", &year);
	//if (IsLeapYear(year)){
	//	printf("%d年是闰年！\n",year);
	//}
	//else{
	//	printf("%d年不是闰年！\n",year);
	//}
	//code1
	//int n = 0;
	//printf("请输入一个数字：");
	//scanf("%d", &n);
	//if (IsPrime(n)){
	//	printf("%d是素数！\n", n);
	//}
	//else{
	//	printf("%d不是素数！\n", n);
	//}
	//printf("100到200之间的素数如下：\n");
	//int a = 100;
	//for (a; a <= 200; a++){
	//	if (IsPrime(a)){
	//		printf("%d ", a);
	//	}
	//}
	//printf("\n");
	
	system("pause");
	return 0;
}