#include <bits/stdc++.h>
using namespace std;

// A,B,C는 각 각 21억까지의 수를 가질 수 있으므로 분할정복으로 잘개 쪼개 연산 한다.
// A^B%C


typedef long long ll;

ll power(ll A, ll B, ll C) {
	if (B == 0) return 1;		// 지수가 0일 때
	if (B == 1) return A % C;	// 지수가 1일 때

	ll ret = power(A, B / 2, C);// 분할
	ret = (ret * ret) % C;		// 분할 처리 2^10 = 2^5 * 2^5
	if (B % 2) ret = (ret * A) % C;	// 홀수일 경우
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll A, B, C;
	cin >> A >> B >> C;
	cout << power(A, B, C);


	return 0;
}