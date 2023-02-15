#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
ll A, B, C;

ll go(ll A, ll B) {
	if (B == 1)return A % C;
	ll ret = go(A, B / 2);	// 분할 정복
	ret = (ret * ret) % C;	
	if (B % 2)ret = ret * A % C;	// 홀수 처리
	return ret;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> A >> B >> C;
	cout << go(A, B)%C;

	return 0;
}