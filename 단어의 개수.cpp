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
/*������ �� �о��
* �Է� - ������ �����ؼ� ������ ���� ����. ���� ���ڿ��� �հ� �ڿ��� ������ ���� ���� �ִ�.
* str[0]�� str[len]�� ���ܽ����ָ� ��
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