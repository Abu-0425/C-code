#include <stdio.h>
#include <string.h>

#pragma warning(disable:4996)


//×Ö·û´®×ª»» : A<->z, B<->y,...,Z<->a,´ýÍê³É...
int main()
{
	char str[10000] = { 0 };
	scanf("%s", &str);
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (issupper(str[i])) {
			str[i] = tolower(str[i]);
		}
		else {
			str[i] = tosupper(str[i]);
		}
	}
	printf("%s\n", str);
	return 0;

}

#if 0
int main()
{
	int N;
	scanf("%d", &N);
	int arr[10000] = { 0 };
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	int K;
	scanf("%d", &K);
	while (K > 0) {
		char c;
		int i, j, m;
		scanf("%c %d %d %d",&c, &i, &j, &m);
		if (c == '+') {
			for (int n = i - 1; n < j; n++) {
				arr[n] += m;
			}
		}
		else if (c == '-') {
			for (int n = i - 1; n < j; n++) {
				arr[n] -= m;
			}
		}
		else {
			for (int n = i - 1; n < j; n++) {
				arr[n] = m;
			}
		}
		K--;
	}
	for (int i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
#endif


#if 0
int judgeNumber(int number, int k){
	while (number != 0){
		if (number % 10 == k)
			return 0;
		number /= 10;
	}
	return 1;
}

int main()
{
	int M,N,K;
	int sum = 0;
	scanf("%d %d %d",&M,&N,&K);
	if(K < 0 || K > 9)
		return 0;

	for(int i = M;i<=N;i++) {
		if(judgeNumber(i,K))
			sum += i;

	}
	printf("%d\n",sum);
	return 0;
} 
#endif


#if 0
int main()
{
	int N;
	scanf("%d", &N);
	while (N--) {
		int A, B, C;
		scanf("%d %d %d", &A, &B, &C);
		if ((A + B == C) || (A - B == C) || (A * B == C) \
			|| (A / B == C) || (A % B == C)) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}
#endif


