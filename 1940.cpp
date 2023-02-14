#include <bits/stdc++.h>
using namespace std;

// 단순 순회
// 1 <= N <= 15,000
// 1 <= M <= 10,000,000
// 정렬 후 이중반복문 순회

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