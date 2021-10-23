#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
char arr[51][51];

int max(int v1, int v2) {
	if (v1 > v2)return v1;
	else return v2;
}
void Hswap(int i, int j) {//가로
	char tmp = arr[i][j];
	arr[i][j] = arr[i][j + 1];
	arr[i][j + 1] = tmp;
}
void Vswap(int i, int j) {//세로
	char tmp = arr[i][j];
	arr[i][j] = arr[i+1][j];
	arr[i+1][j] = tmp;
}

int numOfCandy() {
	int cnt = 0;
	for (int i = 0; i < N; i++)//가로
	{
		int tmp = 1;
		for (int j = 1; j < N; j++)
		{
			if (arr[i][j] == arr[i][j - 1])tmp++;
			else {
				cnt = max(cnt, tmp);
				tmp = 1;
			}
		}
		cnt = max(cnt, tmp);
	}

	for (int i = 0; i < N; i++)//세로
	{
		int tmp = 1;
		for (int j = 0; j < N-1; j++)
		{
			if (arr[j+1][i] == arr[j][i])tmp++;
			else {
				cnt = max(cnt, tmp);
				tmp = 1;
			}
		}
		cnt = max(cnt, tmp);
	}
	return cnt;
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
		{
			scanf(" %c",&arr[i][j]);
			
		}
	}
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N-1; j++)
		{
			Hswap(i, j);
			result = max(result, numOfCandy());
			Hswap(i, j);

			Vswap(j, i);
			result = max(result, numOfCandy());
			Vswap(j, i);

		}
	}
	printf("%d", result);
	return 0;
}