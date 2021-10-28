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
		if (cnt < N)max = mid - 1; // ���� ���� �̴�
		else {// ���� ������ ��������� �ִ�ġ�� �����ϱ� ����
			if (ans < mid)ans = mid;
			min = mid + 1;
		}
	}
	cout << ans;
	return 0;
}