#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main() {
	char A[51],B[51];
	scanf("%s %s", A, B);
	int Alen = strlen(A);
	int Blen = strlen(B);
	int result = 50;
	int cnt = 0;
	for (int i = 0; i <= Blen - Alen; i++) {
		for (int j = 0; j < Alen; j++) 
			if (A[j] != B[i + j])cnt++;
		
		result = min(cnt, result);
		cnt = 0;
	}
	printf("%d", result);
	return 0;
}