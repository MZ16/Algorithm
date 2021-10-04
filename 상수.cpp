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
	char str1[4];
	char str2[4];
	
	scanf("%s %s", str1, str2);
	
	
	char swap = str1[2];
	str1[2] = str1[0];
	str1[0] = swap;


	swap = str2[2];
	str2[2] = str2[0];
	str2[0] = swap;
	
	printf("%d", (atoi(str1) > atoi(str2)) ? atoi(str1) : atoi(str2));
	
	return 0;
}