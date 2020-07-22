#include <stdio.h>
#include <Windows.h>
#pragma warning (disable:4996)

void Swap(int *_x, int *_y)
{
	int temp = *_x;
	*_x = *_y;
	*_y = temp;
}

int CountNine()
{
	int i = 1;
	int count = 0;
	for (; i < 101; i++){
		if (i % 10 == 9){
			count++;
		}
		if (i / 10 == 9){
			count++;
		}
	}
	return count;
}
int main()
{
	int num=CountNine();
	printf("%d\n", num);

	int x = 10;
	int y = 20;
	Swap(&x, &y);
	printf("%d,%d\n", x, y);

	system("pause");
	return 0;
}

