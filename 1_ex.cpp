#include <bits/stdc++.h>
using namespace std;

// brute force
// 2400�� ���Ե� n��° ���� ã�´�.
const int INF = 1e6; // 100,000

int main() {
	int N,cnt=0;
	cin >> N;
	for (int i = 2400; i < INF; i++) {
		string ans = to_string(i);
		if (ans.find("2400") != string::npos) { // 2400�� ���Ե� ���ڿ��� npos�� ��ȯ���� �ʴ´ٸ�(���Ѵٸ�)
			cnt++;
		}
		if (cnt == N) {
			cout << ans;
			break;
		}
	}

	return 0;
}