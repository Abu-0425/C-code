#include <stdio.h>
#include <Windows.h>
#pragma warning(disable:4996)

int main()
//��ӡ1-100��3�ı���
{
	int n = 1;
	for (; n <= 100; n++){
		if (0 == n % 3){
			printf("%d\n", n);
		}
	}
	////�������Ӵ�С���
	//int a, b, c, t;
	//printf("Please enter three data:\n");
	//scanf("%d %d %d", &a, &b, &c);
	//if (a<b) {
	//	t = a; a = b; b = t;
	//}
	//if (a<c) {
	//	t = a; a = c; c = t;
	//}
	//if (b<c) {
	//	t = b; b = c; c = t;
	//}
	//printf("%d,%d,%d", a, b, c);

	system("pause");
	return 0;
}


