#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// ������� ����. 1986
/* ¦�� '-' Ȧ�� '+'

*/
int main() {
	int TC,N;
	cin >> TC;
	for (int i = 1; i <= TC; i++) {
		cin >> N;
		int sum = 0;
		for (int j = 1; j <= N; j++) {
			if (j % 2 != 0)sum += j;
			else sum -= j;
		}printf("#%d %d\n", i, sum);
	}
	return 0;
}