#include <stdio.h>
#include <assert.h>
#include <windows.h>

#pragma warning(disable:4996)

void Reverse(char *str, int start, int end)
{
	while (start < end){
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++, end--;
	}
}
void LeftRotate(char *str, int len, int num)
{
	assert(str);
	assert(len > 0);
	assert(num >= 0);
	num %= len;//ȥ��
	//����[0, num-1]
	Reverse(str, 0, num - 1);
	//����[num, len-1]
	Reverse(str, num, len - 1);
	//��������[0, len-1]
	Reverse(str, 0, len - 1);
	//����1
	//while (num){
	//	char temp = str1[0];
	//	int i = 0;
	//	for (; i < len - 1; i++){
	//		str1[i] = str1[i + 1];
	//	}
	//	str1[i] = temp;
	//	num--;
	//}
}
int main()
{
	char str[] = "abcd1234";
	int len = strlen(str);
	int num = 0;
	printf("���������������Ĵ�����");
	scanf("%d", &num);
	printf("before: %s\n", str);
	char *double_string = (char*)malloc(2 * len + 1);//����һ�ζ�̬�ڴ�ռ��Է���˫����
	assert(double_string);//����ռ��Ƿ�����ɹ�
	strcpy(double_string, str);//�Ƚ�str������double_string
	strcat(double_string, str);//�ٽ�strƴ����double_string���������˫�����Ĺ���
	strncpy(str, double_string + num, len);//ʹ��strncpy��ɶ�Ӧ����������
	printf("after : %s\n", str);
	free(double_string);//�ͷ�֮ǰ����Ķ�̬�ڴ�ռ�
	//int i = 0;
	//for (; i < len; i++){
	//	LeftRotate(str1, len, 1);
	//	if (strcmp(str1, str2) == 0){
	//		printf("Yes!\n");
	//		break;
	//	}
	//}
	//if (i == len){
	//	printf("No!\n");
	//}
	system("pause");
	return 0;
}