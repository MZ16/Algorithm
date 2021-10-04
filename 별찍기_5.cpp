#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int main() {
	init();
	int TC;
	scanf("%d", &TC);
	int len = TC-1;
	for (int i = 1; i <= TC; i++) {
		for (int j = i; j <= len; j++) {
			printf(" ");
		}
		for (int j = 0; j < i; j++) {
			printf("*");
		}
		if (i >= 2) {
			for (int j = 0; j < i - 1; j++) {
				printf("*");
			}
		}printf("\n");
	}


	return 0;
}