#include <bits/stdc++.h>
using namespace std;

// 소수 - 1과 자신으로만 나눌 수 있는 수
// 합성수 - 1과 자신이 아닌 수의 곱으로 나타낼 수 있는 수

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N,X,Y;
	int tc;
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		cin >> N;
		X = N * 9; // 9이하의 수의 곱은 Y가 소수인 경우가 있다.
		Y = X - N;
		cout << "#"<<i<<" "<<X << " " << Y<<"\n";
	}
	return 0;
}