#include <bits/stdc++.h>
using namespace std;

// 단순 순회
// 1 <= N <= 15,000
// 1 <= M <= 10,000,000
// 고유 번호는 100,000 보다 작거나 같은 자연수
// 정렬 후 이중반복문 순회

int N,M;
int arr[15001];
int cnt = 0;

int main() {
	cin >> N;
	cin >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr+N);
	if (M > 200000) cout << 0<<"\n";// 고유 번호의 범위가 100,000 임으로 2개의 수를 더했을 때 20만을 초과할 수 없기 때문에 
									// 코드의 효율성을 위해 추가시켜줌, 해당 문제에선 없어도 맞음
	else {
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (arr[i] + arr[j] == M)cnt++;
			}
		}
		cout << cnt;
	}
	
	
	return 0;
}