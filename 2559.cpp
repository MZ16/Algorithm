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




