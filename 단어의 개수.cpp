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
/*문제를 잘 읽어보자
* 입력 - 공백이 연속해서 나오는 경우는 없다. 또한 문자열의 앞과 뒤에는 공백이 있을 수도 있다.
* str[0]과 str[len]을 제외시켜주면 됨
*/
int main() {
	init();
	int len,cnt=0;
	char str[1000001];
	
	scanf("%[^\n]", str);
	//fgets(str, sizeof(str) / sizeof(char), stdin);
	len = strlen(str);
	//str[len] = 0;
	
	if (len == 1) {
		if (str[0] == ' ') {
			printf("%d", cnt);
			return 0;
		}		
	}
	for (int i = 1; i < len - 1; i++) {
		if (str[i] == ' ') cnt++;
	}
	
	printf("%d", cnt+1);
	return 0;
}