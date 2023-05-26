#include <bits/stdc++.h>
using namespace std;

vector<char> oper; // 연산자
vector<int> num; // 숫자
int ans = -987654321;
int N; string s;

int op(char ch, int a, int b) {
	if (ch == '+')return a + b;
	if (ch == '-')return a - b;
	if (ch == '*')return a * b;
}

void go(int h_idx, int h_num) {
	if (h_idx == num.size() - 1) {
		ans = max(ans, h_num);
		return;
	}
	go(h_idx + 1, op(oper[h_idx], h_num, num[h_idx + 1])); // 괄호X
	if (h_idx + 2 <= num.size() - 1) { // 괄호O, size check
		// idx0 operator (idx1 operator idx2)
		go(h_idx + 2, op(oper[h_idx], h_num, op(oper[h_idx + 1], num[h_idx + 1], num[h_idx + 2])));
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	cin >> s;
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0)num.push_back(s[i] - '0');
		else oper.push_back(s[i]);
	}
	go(0, num[0]);
	cout << ans;
	return 0;
}

/* 완전탐색
* 우선순위가 없는 연산자(+,-,*)이며 괄호를 추가하여(우선순위) 최댓값을 구하는 문제
* 괄호를 추가하지 않거나 추가하거나 2가지 재귀만 있으면 됨
* 추가하지 않을경우
*	현재값과 다음값을 연산하면됨
* 추가 할 경우
*	1. overflow방지 조건문
*	2. h_idx_num과 operator(h_idx_num+1, h_idx_num+2)의 값을 연산해주면 됨 (누적합)
* 
* //ans의 범위가 -2^31 ~ 2^31 이므로 ans에 최솟값을 저장함
*/