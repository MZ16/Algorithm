#include <bits/stdc++.h>
using namespace std;

int psum[100001];
int ret = -10000001;

int main() {
	int N, K;
	cin >> N >> K;
	for (int i = 1,tmp; i <= N; i++) {
		cin >> tmp; 
		psum[i] = psum[i - 1] + tmp;
	}
	
	for (int i = K; i <= N; i++) 
		ret = max(psum[i] - psum[i - K], ret);
		
	cout << ret;
	

	return 0;

	
}
// 구간합은 0번째 배열을 비움




/* 
* N<=100,000 / K<N
* 최악의 경우 10만 * 10만
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, K;
	cin >> N >> K;
	int a[100001] = { 0, };
	int max = 0;
	for (int i = 0; i < N; i++)cin >> a[i];
	for (int i = 0; i <= N - K; i++) {
		int ans = 0;
		for (int j = i; j < i+K; j++) {
			ans += a[j];
		}
		if (max < ans)max = ans;
	}

	cout << max;

	return 0;
}
*/