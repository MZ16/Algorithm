#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

char WB[9][9] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW", 
	"WBWBWBWB",
	"BWBWBWBW", 
	"WBWBWBWB",
	"BWBWBWBW"};

char BW[9][9] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"};

char arr[51][51];

int WB_Cnt(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) 
		for (int j = 0; j < 8; j++) 
			if (arr[i + x][j + y] != WB[i][j])cnt++;
		
	return cnt;
}

int BW_Cnt(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (arr[i + x][j + y] != BW[i][j])cnt++;

	return cnt;
}


int main() {
	int N, M;
	int result=999999;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%s", arr[i]);
	
	for (int i = 0; i + 7 < N; i++)
		for (int j = 0; j + 7 < M; j++) {
			int tmp= min(BW_Cnt(i, j), WB_Cnt(i, j));
			result = min(tmp, result);
		}
	printf("%d", result);
	return 0;
}
