#include <bits/stdc++.h>
using namespace std;

/* N <= 10^12 /
* int64_t / –9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807
*/

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int tc;
	cin >> tc;

	for (int i = 1; i <= tc; i++) {
		int64_t N,ans=0;
		cin >> N;
		for (int64_t j = sqrt(N); j > 0; j--) {
			if (N % j == 0) {
				ans = j + N / j - 2;
				break;
			}
		}
		cout << "#" << i << " " << ans << "\n";
	}	

	/*약수 구하기
	for (int i = 1; i <= sqrt(N); i++) { // 루트N
		if (N % i == 0) {
			v.push_back(i);
			if (i == N / i) v.push_back(N / i);
		}
	}*/

	return 0;
}