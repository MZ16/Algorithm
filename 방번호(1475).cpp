#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main() {
	char N[8];
	int arr[8];
	int cnt[11] = { 0, };
	int MAX = 0;
	scanf("%s", N);
	int len = strlen(N) / sizeof(char);
	
	for (int i = 0; i < len; i++) {
		arr[i] = (N[i] - '0');
		cnt[arr[i]]++;
	}

	cnt[6] = ((cnt[6] + cnt[9]) / 2) + ((cnt[6] + cnt[9]) % 2);
	cnt[9] = 0;


	for (int i = 0; i < 10; i++) {
		if (cnt[i] > MAX)MAX = cnt[i];
	}
	printf("%d", MAX);

	


	return 0;
}