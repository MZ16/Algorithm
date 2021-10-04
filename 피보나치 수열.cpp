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
	int arr[2] = { 0,1 };
	int Nxt;
	int TC;
	scanf("%d", &TC);
	for (int i = 0; i < TC-1; i++) {
		Nxt = arr[0] + arr[1];
		arr[0] = arr[1];
		arr[1] = Nxt;
	}
	printf("%d", arr[1]);

	return 0;
}