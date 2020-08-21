#include <stdio.h>
#include <windows.h>

void Game()
{
	int a = 1;
	for (; a <= 5; a++){
		int b = 1;
		for (; b <= 5; b++){
			int c = 1;
			for (; c <= 5; c++){
				int d = 1;
				for (; d <= 5; d++){
					int e = 1;
					for (; e <= 5; e++){
						if (((b == 2) + (a == 3)) == 1 && \
							((b == 2) + (e == 4)) == 1 && \
							((c == 1) + (d == 2)) == 1 && \
							((c == 5) + (d == 3)) == 1 && \
							((e == 4) + (a == 1)) == 1){
							unsigned char flag = 0; 
							flag |= (1 << (a - 1));
							flag |= (1 << (b - 1));
							flag |= (1 << (c - 1));
							flag |= (1 << (d - 1));
							flag |= (1 << (e - 1));
							if (flag == 0x1F){
								printf("a: %d, b: %d, c: %d, d: %d, e: %d\n", a, b, c, d, e);
							}
						}
					}
				}
			}
		}
	}
}

void FindKiller(){
	char killer = 'A';
	for (; killer <= 'D'; killer++){
		if (((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D')) == 3){
			printf("The killer is %c!\n", killer);
		}
	}
}

void ShowYang()
{
	int arr[10][10];
	int i = 0;
	int j = 0;

	for (; i < 10; i++){
		for (j = 0; j <= i; j++){
			arr[i][j] = 1;
		}
	}

	for (i = 2; i < 10; i++){
		for (j = 1; j < i; j++){
			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
		}
	}


	for (i = 0; i < 10; i++){
		for (j = 0; j <= i; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	//ShowYang();
	//FindKiller();
	Game();

	system("pause");
	return 0;
}