#include <stdio.h>
#include <Windows.h>
#pragma warning (disable:4996)

int main()
{

	//4.����Ļ�����9*9�˷��ھ���
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= i; j++) {
			printf("%d*%d=%d\t", j, i, i*j);
			if (j == i) {
				printf("\n");
			}
		}
	}

	//3.��10 �������е����ֵ
	//int a[10];
	//int i = 0;
	//int max = 0;
	//printf("������ʮ��������");
	//for (; i < 10; i++){
	//	scanf("%d", &a[i]);
	//	max = a[0];
	//}
	//for (i=0; i < 10; i++){
	//	if (a[i]>max){
	//		max = a[i];
	//	}
	//}
	//printf("������Ϊ��%d\n", max);


	//2.����1/1-1/2+1/3-1/4+1/5 ���� + 1/99 - 1/100 ��ֵ����ӡ�����
	//int i = 1;
	//int sign = 1;
	//float sum = 0;
	//for (; i < 101; i++){
	//	sum += sign * 1.0 / i;
	//	sign = -sign;
	//}
	//printf("%f\n", sum);


	//1.��һ�� 1�� 100 �����������г��ֶ��ٸ�����9
	//int i = 0;
	//int k = 0;
	//for (i = 1; i < 100; i++)
	//{
	//	if (i % 10 == 9)
	//	{
	//		k++;
	//	}
	//	if (i / 10 == 9)
	//	{
	//		k++;
	//	}
	//}
	//printf("%d\n", k);

	system("pause");
	return 0;
}