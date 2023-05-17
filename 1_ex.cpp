#include <bits/stdc++.h>
using namespace std;

// brute force
// 2400이 포함된 n번째 수를 찾는다.
const int INF = 1e6; // 100,000

int main() {
	int N,cnt=0;
	cin >> N;
	for (int i = 2400; i < INF; i++) {
		string ans = to_string(i);
		if (ans.find("2400") != string::npos) { // 2400이 포함된 문자열이 npos를 반환하지 않는다면(속한다면)
			cnt++;
		}
		if (cnt == N) {
			cout << ans;
			break;
		}
	}

	return 0;
}