#include <stdio.h>
#include <windows.h>

void BubbleSort(int arr[], int num)
{
	int i = 0;
	for (; i < num - 1; i++){
		int j = 0;
		int flag = 1;
		for (; j < num - 1 - i; j++){
			if (arr[j] > arr[j + 1]){
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 0;
			}
		}
		if (1 == flag){
			break;
		}
	}
}

void Swap(int a[], int b[], int num)
{
	int i = 0;
	int j = 0;
	int temp = 0;
	for (; i < num; i++,j++){
		if (i == j){
			temp = a[i];
			a[i] = b[j];
			b[j] = temp;
		}
		printf("%d ", a[i]);
	}
	printf("\n");
	for (j = 0; j < num; j++){
		printf("%d ", b[j]);
	}
	printf("\n");

}
void Init(int *arr, int num)
{
	int i = 0;
	for (; i < 10; i++){
		arr[i] = 0;
		printf("%d ", arr[i]);
	}
	printf("\n");
	//memset(arr, 0, num*sizeof(arr[0]));
}
void Print(int arr[], int num)
{
	int i = 0;
	for (; i < num; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void Reverse(int arr[], int num)
{
	int i = 0;
	for (; i < num / 2; i++){
		int temp = arr[i];
		arr[i] = arr[num - 1 - i];
		arr[num - 1 - i] = temp;
	}
}

int main()
{
	//code3:������A�е����ݺ�����B�е����ݽ��н�����������һ����
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int b[] = { 11, 22, 33, 44, 55, 66, 77, 88, 99 };
	int num = sizeof(a) / sizeof(a[0]);
	Swap(a, b, num);
	//code2:������0����ӡ������
	//int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	//int num = sizeof(arr) / sizeof(arr[0]);
	//Print(arr, num);
	//Reverse(arr, num);
	//Print(arr, num);//���ú��ٴδ�ӡ
	//Init(arr, num);//��0
	//code1:ð������
	//int arr[] = { 12, 6, 25, 3, 18, 7, 66, 33, 42, 11,0,20 };
	//int num = sizeof(arr) / sizeof(arr[0]);
	//Show(arr,num);
	//BubbleSort(arr, num);
	//Show(arr, num);
	
	system("pause");
	return 0;
}