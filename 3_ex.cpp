#include<bits/stdc++.h>
using namespace std;

// 주어진 N개의 수 중 mod 11을 했을 때 가장 큰 수의 합을 구하라

int ans,N;
int cnt;
vector<int> v;
const int mod = 11;

void go(int idx, int sum) {
	if (ans == 10)return; // 경우의 수를 제거하기 위함
	if (idx == N) {
		cnt++; // 연산횟수 디버깅을 위함
		ans = max(ans, sum % mod);
		return;
	}
	go(idx + 1, sum + v[idx]); // 포함
	go(idx + 1, sum); // 포함안함
}


int main() {
	cin >> N;
	for (int x, i = 0; i < N; i++) {
		cin >> x;
		v.push_back(x);
	}
	go(0,0);
	cout << cnt << "\n";
	cout << ans;
	return 0;
}
/* N=10이므로 2^10 = 1024만큼 동작함, 불필요한 탐색이 많다는것을 알 수 있음
* 11 mod를 하면 최댓값이 10이라는 것을 알 수 있음 이 것을 통해 경우의 수를 제거하는것이 백트레킹
* if(ans==10)return;로 경우의수를 제거하여 cnt는 0이 나오는 것을 알 수 있다.
*/