#include <bits/stdc++.h>
using namespace std;
// N - 100,000
// K - 100,000

int psum[100001]; // prefix sum, ���� ���� �迭 1���� ����
int ret_max = -100001; // �ִ��� ���ϱ� ���� ���� �� �ּڰ��� ����

int main() {
	int N, K;
	cin >> N >> K;
	for (int i = 1, tmp; i <= N; i++) {
		cin >> tmp;
		psum[i] = psum[i - 1] + tmp;
	}

	for (int i = K; i <= N; i++) 
		ret_max = max(ret_max, psum[i] - psum[i - K]);
	
	cout << ret_max;


	return 0;
}