#include <stdio.h>
#pragma warning(disable:4996)

int main()
{
	int N;
	scanf("%d", &N);
	float h, s, z, t;
	scanf("%f %f %f %f", &h, &s, &z, &t);
	float money = 0;
	char type[10];
	int weight[10];
	for (int i = 0; i < N; i++) {
		scanf("%c", &type[i]);
		scanf("%d", &weight[i]);
	}
	int rweight = 0;
	int sumweight = 0;
	for (int i = 0; i < N; i++) {
		switch (type[i]) {
		case 'M':
			money += weight[i] / 100 * h;
			break;
		case 'V':
			money += weight[i] / 100 * s;
			break;
		case 'R':
			rweight += weight[i];
			break;
		case 'S':
			money += weight[i] / 100 * t;
			break;
		}
	}
	if (rweight > 200) {
		money += (rweight - 200) / 100 * z;
	}
	for (int i = 0; i < N; i++) {
		sumweight += weight[i];
	}
	int sy;
	scanf("%d", &sy);
	if (sy <= 1 / 20 * sumweight) {
		money *= 0.9;
	}
	printf("%.2f\n", money);
	return 0;
}


#if 0
void delArr(int *arr, int n)
{
	int flag = n - 1;
	for (int i = n - 1; i > 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			if (arr[i] == arr[j]) {
				for (int k = i; k < n - 1; k++) {
					arr[k] = arr[k + 1];
				}
				arr[flag] = 0;
				flag--;
				break;
			}
		}
	}
}

int main()
{
	int M;
	scanf("%d", &M);
	int N[100] = { 0 };
	for (int i = 0; i < M; i++) {
		scanf("%d", &N[i]);
	}
	int res[100][10000] = { 0 };
	for (int i = 0; i < M; i++) {
		int Narr[10000] = { 0 };
		for (int j = 0; j < N[i]; j++) {
			scanf("%d", &Narr[j]);
		}
		delArr(Narr, N[i]);
		for (int j = 0; j < N[i]; j++) {
			res[i][j] = Narr[j];
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N[i]; j++) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
	return 0;
}
#endif

#if 0
int main()
{
	int N;
	scanf("%d", &N);
	int arr[1000];
	int sum = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	for (int i = 0; i < N; i++) {
		if (arr[i] * arr[i] > sum) {
			printf("%d ", arr[i]);
		}
	}
	printf("\n");

	return 0;
}
#endif