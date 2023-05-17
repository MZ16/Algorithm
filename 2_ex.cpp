#include <bits/stdc++.h>
using namespace std;

// �־��� N���� �� �� ���� �Ҽ��� ����� ���� ���϶�.
/* input
10
24 35 38 40 49 59 60 67 83 98
output
176
*/

vector<int> v;
int N;

bool chk(int val) { // �Ҽ� check
	if (val <= 1)return 0;
	if (val == 2)return 1;
	if (val % 2 == 0)return 0;
	for (int i = 2; i * i <= val; i++) {
		if (val % i == 0)return 0;
	}
	return 1;
}

int go(int idx, int sum) { 
	if (idx == N) {
		return chk(sum);
	}
	return go(idx + 1, sum + v[idx]) + go(idx + 1, sum); // �����ϰų� ������������
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int val;
		cin >> val;
		v.push_back(val);
	}
	cout << go(0, 0);
	return 0;
}