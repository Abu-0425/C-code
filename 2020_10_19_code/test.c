#include <stdio.h>
#include <assert.h>
#include <windows.h>

char *MyStrcpy(char *dest, const char *src)
{
	char *ret = dest;
	assert(src != NULL);
	assert(dest != NULL);
	while ((*dest++ = *src++)){
		;
	}
	return ret;
}
int MyStrlen(const char *str)
{
	if (*str == '\0'){
		return 0;
	}
	int i = 0;
	while (*str != '\0'){
		i++;
		str++;
	}
	return i;
}
int my_strcmp(char *dest, char *src)
{
	int ret = 0;
	assert(dest != NULL);
	assert(src != NULL);
	while (!(ret = *(unsigned char*)dest - *(unsigned char*)src) && dest&&src){
		dest++;
		src++;
	}
	if (ret < 0){
		ret = -1;
	}
	else if (ret > 0){
		ret = 1;
	}
	return ret;
}
int main()
{
	char *str = "helloword";
	char arr[32];
	MyStrcpy(arr, str);
	printf("%s\n", arr);
	const char *str = "helloworld";
	int ret = MyStrlen(str);
	printf("%d\n", ret);
	//char arr[32] = "abcd";
	//char arr1[32] = "abcc";
	//int ret = my_strcmp(arr, arr1);
	//printf("%d\n", ret);
	system("pause");
	return 0;
}

//char *MyStrcat(char *dest,const char *src)
//{
//	char *ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (*dest){
//		dest++;
//	}
//	while ((*dest++ = *src++)){
//		;
//	}
//	return ret;
//}
/*
int main()
{
	char arr[32] = "1234";
	char *str2 = "abcd";
	MyStrcat(arr, str2);
	printf("%s\n", arr);

	system("pause");
	return 0;
}
*/