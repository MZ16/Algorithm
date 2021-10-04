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
	int TC;
	scanf("%d", &TC);
	
	for (int i = 1; i <= TC; i++) {
		for (int j = 0; j < TC-i; j++) {
			printf(" ");
		}
		for (int j = 0; j < i; j++) {
			printf("*");
		}printf("\n");
	}
	
}