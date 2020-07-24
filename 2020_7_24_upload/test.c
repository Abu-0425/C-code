#include <stdio.h>
#include <windows.h>
#include <math.h>
#pragma warning(disable:4996)

//�Լ�дһ��strlen������������ĿҪ�������ַ�������������
int MyStrlen(char *string)
{
	int i = 0;
	while (string[i] != '\0'){
		i++;
	}
	return i;
}
//��дһ������ʵ��n��k�η���ʹ�õݹ�ʵ�֡�
int Pow(int n,int k)
{
	if (k <= 0){
		return 1;
	}
	else{
		return n*Pow(n, k - 1);
	}
}
//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮��
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
//���룺1729�������19
int DigitSum(int n)
{
	if (n>9){
		return DigitSum(n / 10) + n % 10;
	}
	else{
		return n;
	}
}
//��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
//ʵ�֣��������ַ����е��ַ��������С�
//Ҫ�󣺲���ʹ��C�������е��ַ�������������

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
//�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲�������
//�ݹ鷽��
int Fib1(int x)
{
	if (x <= 2){
		return 1;
	}
	return Fib1(x - 1) + Fib1(x - 2);
}
//�ǵݹ鷽��
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
//�ݹ�ͷǵݹ�ֱ�ʵ��strlen
//�ݹ鷽��
int MyStrlen1(const char *str1)
{
	if (*str1 == '\0'){
		return 0;
	}
	return 1 + MyStrlen1(str1 + 1);
}
//�ǵݹ鷽��
int MyStrlen2(const char *str2)
{
	int i = 0;
	while (str2[i] != '\0'){
		i++;
	}
	return i;
}
//�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳ˣ���������������⣩
//�ݹ鷽��
int Fact1(int x)
{
	if (x == 1){
		return 1;
	}
	return x*Fact1(x - 1);
}
//�ǵݹ鷽��
int Fact2(int y)
{
	int fact = 1;
	for (; y > 0; y--){
		fact *= y;
	}
	return fact;
}
//�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
void ShowInt(int _x)
{
	if (_x > 9){
		ShowInt(_x / 10);
	}
		printf("%d ", _x % 10);
}
//ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ��
//�磺����9�����9 * 9�ھ�������12�����12 * 12�ĳ˷��ھ���
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

//��������������ֵ
void Swap(int *_x,int *_y)
{
	int temp = 0;
	temp = *_x;
	*_x = *_y;
	*_y = temp;
}
//�ж�year�Ƿ�Ϊ����
int IsLeapYear(int _year)
{
	if ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0){
		return 1;
	}
	return 0;
}
//�ж�һ�����Ƿ�Ϊ����
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
	//printf("��ֱ���������n��k: ");
	//scanf("%d %d", &n,&k);
	//int ret = Pow(n,k);
	//printf("result:%d\n", ret);
	//code10
	//int n = 0;
	//printf("������һ������: ");
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
	//printf("������ڼ���쳲���������������һ��������");
	//scanf("%d", &n);
	//int ret1 = Fib1(n);
	//printf("�ݹ鷽�������  %d\n", ret1);
	//int ret2 = Fib2(n);
	//printf("�ǵݹ鷽�������%d\n", ret2);
	//code7
	//char *str = "helloworld";
	//int ret1 = MyStrlen1(str);
	//printf("�ݹ鷽�������  %d\n", ret1);
	//int ret2 = MyStrlen2(str);
	//printf("�ǵݹ鷽�������%d\n", ret2);
	//code6
	//int n = 0;
	//printf("��������Ҫ��Ľ׳ˣ�");
	//scanf("%d", &n);
	//int ret1 = Fact1(n);
	//printf("�ݹ鷽�������  %d!=%d\n", n, ret1);
	//int ret2 = Fact2(n);
	//printf("�ǵݹ鷽�������%d!=%d\n", n, ret2);
	//code5
	//int x = 0;
	//printf("�����������ӡ��������");
	//scanf("%d", &x);
	//ShowInt(x);
	//code4
	//int x = 0;
	//printf("�������뿴���˼��ĳ˷��ھ���������һ��������");
	//scanf("%d", &x);
	//ShowMulTable(x);
	//code3
	//int x = 10;
	//int y = 20;
	//printf("����ǰ��%d,%d\n", x, y);
	//Swap(&x, &y);
	//printf("������%d,%d\n", x, y);
	//code2
	//int year = 0;
	//printf("��������Ҫ�жϵ���ݣ�");
	//scanf("%d", &year);
	//if (IsLeapYear(year)){
	//	printf("%d�������꣡\n",year);
	//}
	//else{
	//	printf("%d�겻�����꣡\n",year);
	//}
	//code1
	//int n = 0;
	//printf("������һ�����֣�");
	//scanf("%d", &n);
	//if (IsPrime(n)){
	//	printf("%d��������\n", n);
	//}
	//else{
	//	printf("%d����������\n", n);
	//}
	//printf("100��200֮����������£�\n");
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