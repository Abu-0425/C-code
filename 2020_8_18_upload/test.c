#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <windows.h>

void ShowArr(int *arr, int num)
{
	int i = 0;
	for (; i < num; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void swap(char *x, char *y, int size)
{
	int i = 0;
	for (; i < size; i++){
		*(x + i) ^= *(y + i);
		*(y + i) ^= *(x + i);
		*(x + i) ^= *(y + i);
	}
}
void MySort(void *base, int num, int size, int(*comp)(const void *, const void *))
{
	assert(base);
	assert(comp);
	char *_base = (char *)base;
	int i = 0;
	for (; i < num - 1; i++){
		int flag = 0;
		int j = 0;
		for (; j < num - 1 - i; j++){
			if (comp(_base + size*j, _base + size*(j +  1)) > 0){
				flag = 1;
				swap(_base + size*j, _base + size*(j + 1), size);
			}
		}
		if (flag == 0){
			break;
		}
	}
}
int CompChar(const void *vx, const void *vy)
{
	char *x = (char *)vx;
	char *y = (char *)vy;
	if (*x > *y){
		return 1;
	}
	else if (*x < *y){
		return -1;
	}
	else{
		return 0;
	}
}
int CompDouble(const void *vx, const void *vy)
{
	double *x = (double *)vx;
	double *y = (double *)vy;
	if (*x > *y){
		return 1;
	}
	else if (*x < *y){
		return -1;
	}
	else{
		return 0;
	}
}
int CompFloat(const void *vx, const void *vy)
{
	float *x = (float *)vx;
	float *y = (float *)vy;
	if (*x > *y){
		return 1;
	}
	else if (*x < *y){
		return -1;
	}
	else{
		return 0;
	}
}
int CompInt(const void *vx, const void *vy)
{
	int *x = (int *)vx;
	int *y = (int *)vy;
	if (*x > *y){
		return 1;
	}
	else if(*x < *y){
		return - 1;
	}
	else{
		return 0;
	}
}
int main()
{
	int arr[] = { 6, 12, 3, 0, 25, 1, 7, 86, 33, 9, 53, 28 };
	//float arr[] = { 6.2f, 5.8f, 1.3f, 3.9f, 15.6f, 7.7f, 6.9f, 11.1f, 1.5f };
	//double arr[] = { 6.2, 5.8, 1.3, 3.9, 15.6, 7.7, 6.9, 11.1, 1.5 };
	//char arr[] = { 'c', 'f','a','z','q','n','l','e' };
	int num = sizeof(arr) / sizeof(arr[0]);
	ShowArr(arr, num);
	MySort(arr, num, sizeof(int), CompInt);
	ShowArr(arr, num);
	//qsort(arr, num, sizeof(int), CompInt);
	//qsort(arr, num, sizeof(float), CompFloat);
	//qsort(arr, num, sizeof(double), CompDouble);
	//qsort(arr, num, sizeof(char), CompChar);
	
	system("pause");
	return 0;
}