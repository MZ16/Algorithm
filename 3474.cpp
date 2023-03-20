#include <bits/stdc++.h>
using namespace std;

// 주어진 factorial(N)의 0 개수
// 2와 5의 곱으로 만들어진 수에는 10이라는 약수가 반드시 포함된다.
//		ex) 100 = 10^2, 100 = (2*5)^2, 20 = 2^2*5
// 즉 10으로 나누어 떨어지는 수는 2와 5의 약수를 모두 갖고있다.

// 10은 2와 5로 만들 수 있으므로 N!의 0 개수는 2와 5의 개수 중 작은 값과 같다.

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T, N;
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		int ret2 = 0, ret5 = 0;		
		cin >> N;
		for (int j = 2; j <= N; j *= 2)
			ret2 += N / j;
		for (int j = 5; j <= N; j *= 5)
			ret5 += N / j;
		cout << min(ret2, ret5)<<"\n";
		
	}

	return 0;
}