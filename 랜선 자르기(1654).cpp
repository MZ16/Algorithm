#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<long long> v;
	int K, N;
	long long val;
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> val; v.push_back(val); 
	}
	long long max = *max_element(v.begin(), v.end());
	long long min = 1;
	long long mid;
	long long ans=0;
	while (min <= max) {
		long long cnt = 0;
		mid = (min + max) / 2;
		for (int i = 0; i < K; i++)
			cnt += v[i] / mid;
		if (cnt < N)max = mid - 1; // 랜선 갯수 미달
		else {// 랜선 갯수가 충족됬더라도 최대치를 저장하기 위함
			if (ans < mid)ans = mid;
			min = mid + 1;
		}
	}
	cout << ans;
	return 0;
}