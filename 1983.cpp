#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

// 조교의 성적 매기기. 1983
/* 
   mid 35%, final 45%, assignment 20%
*/

int main() {
	int T;
	scanf("%d", &T);
	int student[100];
	int N, K;
	int mid, fin, ass;
	char grades[10][3] = { "A+","A0","A-","B+","B0","B-","C+","C0","C-","D0" };
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d %d", &N, &K);
		for (int i = 0; i < N; i++) {
			scanf("%d %d %d", &mid, &fin, &ass);
			student[i] = mid * 35 + fin * 45 + ass * 20;
		}
		int score = student[K - 1];
		int idx;
		sort(student, student + N);
		for (int i = 0; i < N; i++) {
			if (student[i] == score) {
				idx = N - 1 - i;
				break;
			}
		}
		printf("#%d %s\n", tc, grades[10 * idx / N]);
	}
}