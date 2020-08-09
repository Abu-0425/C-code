#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include <windows.h>

//模拟实现strncat
char *my_strncat(char *dst, const char *src, int num)
{
	assert(dst);
	assert(src);
	assert(num > 0);
	char *ret = dst;
	while (*dst){
		dst++;
	}
	while(num){
		*dst = *src;
		dst++;
		src++;
		num--;
	}
	return ret;
}
//模拟实现atoi
int status = 0;

int my_atoi(const char *str)
{
	assert(str);
	int flag = 1;
	long long result = 0;
	int i = 0;
	while (isspace(str[i])){
		i++;
	}
	if (str[i] == '-'){
		flag = -flag;
		i++;
	}
	while (str[i]){
		if (isdigit(str[i])){
			result = result * 10 + flag*(str[i] - '0');
			if (result > INT_MAX || result < INT_MIN){
				status = 1;
				break;
			}
		}
		else{
			status = 2;
			break;
		}
		i++;
	}

	return (int)result;
}
//找单身狗
void FindTwoSingle(int a[], int num, int *x, int *y)
{
	assert(a);
	assert(num > 0);
	assert(x);
	assert(y);
	int result = a[0]; 
	for (int i = 1; i < num; i++){
		result ^= a[i];
	}
	int pos = 1;
	while (1)
	{
		if (result & pos){ 
			break;
		}
		pos <<= 1;
	}
	*x = 0;
	*y = 0;
	for (int i = 0; i < num; i++){
		if (a[i] & pos){
			*x ^= a[i];
		}
		else{
			*y ^= a[i];
		}
	}
}
int main()
{
	//模拟实现strncat
	const char *src = " world";
	char dst[16] = "hello";
	printf("%s\n", my_strncat(dst, src, strlen(src) + 1));
	//my_atoi
	//const char *str = "12345";
	//int ret = my_atoi(str);
	//printf("%d\n",ret);
	//找单身狗
	//int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	//int num = sizeof(a) / sizeof(a[0]);
	//int x = 0;
	//int y = 0;
	//FindTwoSingle(a, num, &x, &y); 
	//printf("X: %d, Y: %d\n", x, y);
	system("pause");
	return 0;
}