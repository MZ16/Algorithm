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

/*
int Factorial(int val) {
	if (val == 1)return 1;
	return val * Factorial(val - 1);
}*/



int main() {
	init();
	int N, sum = 1;
	scanf("%d", &N);
	for (int i = N; i > 1; i--) {
		sum *= i;
	}
	printf("%d", sum);
	
	return 0;
}