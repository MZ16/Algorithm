#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <iostream>
using namespace std;

// -�����ڸ� ���� �ķδ� ���� ���ָ� ��(��ȣ�� ������ ����)

int main() {
	int sum = 0, tmp=0,len;
	char str[51];
	bool flag = false;
	scanf("%s", &str);
	len = strlen(str);
	for (int i = 0; i <= len; i++) {
		if (str[i] == '-' || str[i] == '+' || i == len) {
			if (!flag) { // '-'�� ������ ��
				sum += tmp;
				tmp = 0;
			}
			else {
				sum -= tmp;
				tmp = 0;
			}
			if (str[i] == '-')flag = true;
		}
		else {
			tmp *= 10;
			tmp += str[i] - '0';
		}
	}
	printf("%d", sum);
}