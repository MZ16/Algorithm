#include <bits/stdc++.h>
using namespace std;

// �ܼ� ��ȸ
// 1 <= N <= 15,000
// 1 <= M <= 10,000,000
// ���� �� ���߹ݺ��� ��ȸ

int N,M;
int arr[15001];
int cnt = 0;

int main() {
	cin >> N;
	cin >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr+N);

	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			if (arr[i] + arr[j] == M)cnt++;
		}
	}
	cout << cnt;
	return 0;
}