#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)


//不允许创建临时变量，交换两个整数的内容
void Swap(int *_x, int *_y)
{
	*_x = *_x^*_y;
	*_y = *_x^*_y;
	*_x = *_x^*_y;
}
//写一个函数返回参数二进制中 1 的个数。
//比如： 15    0000 1111    4 个 1
int CountOne(int _n)
{
	int count = 0;
	while (_n != 0){
		count++;
		_n &= _n - 1;
	}
	return count;
}
//获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列
void Print(int _n)
{
	printf("%d偶数位的二进制序列为：\n", _n);
	for (int i = 31; i >= 1; i -= 2)
	{
		printf("%d ", (_n >> i) & 1);
	}
	printf("\n");
	printf("%d奇数位的二进制序列为：\n", _n);
	for (int i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (_n >> i) & 1);
	}
	printf("\n");
}
//编程实现：两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？ 
int Compare(int _x, int _y, int _n)
{
	if (0 == _n){
		return 0;
	}
	if (_n % 2 == 1){
		_n >>= 1;
		return 1 + Compare(_x,_y,_n);
	}
	else{
		_n >>= 1;
		return 0 + Compare(_x, _y, _n);
	}
}
int main()
{
	//code4
	int x = 0;
	int y = 0;
	printf("请输入俩个整数：");
	scanf("%d %d", &x, &y);
	printf("Swap before: %d,%d\n", x, y);
	Swap(&x, &y);
	printf("Swap after : %d,%d\n", x, y);
	//code3
	//int n = 0;
	//printf("请输入一个整数：");
	//scanf("%d", &n);
	//int count = CountOne(n);
	//printf("1的个数为%d\n", count);
	//code2
	//int n = 0;
	//printf("请输入一个整数：");
	//scanf("%d", &n);
	//Print(n);
	//code1
	//int x = 0;
	//int y = 0;
	//int n = 0;
	//printf("请输入俩个整数：");
	//scanf("%d %d", &x, &y);
	//n = x^y;
	//int ret = Compare(x, y, n);
	//printf("result = %d\n", ret);

	system("pause");
	return 0;
}