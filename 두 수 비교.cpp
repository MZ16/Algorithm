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
	int x, y;
	scanf("%d %d", &x, &y);
	if (x > y)printf(">");
	else if (x < y)printf("<");
	else printf("==");
	return 0;
}