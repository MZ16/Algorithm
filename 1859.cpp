#include <iostream>
#include <algorithm>
using namespace std;

/*
1. max값을 구한다, 초기값은 마지막 index이며 뒤에서부터 순차적으로 구한다
2. max가 배열 인덱스보다 크거나 같을경우 ans에 더한다
	-같을경우도 포함시키는 이유는 아무 동작을 하지않는것과 같기때문, 포함시키지 않아도 괜찮다.
3. max가 배열 인덱스보다 작은경우 max를 갱신해준다.
*/
int arr[1000001];

int main() {
	int TC, N;
	cin >> TC;
	for (int i = 0; i < TC; i++) {
		cin >> N;
		for (int j = 0; j < N; j++) cin >> arr[j];
		int max = arr[N - 1]; // 마지막 idx로 초기화
		long long ans = 0;
		for (int j = N - 1; j >= 0; j--) {
			if (max >= arr[j]) ans = ans + (max - arr[j]);
			else max = arr[j]; // max값 갱신
		}
		cout << "#" << i+1 << " " << ans << "\n";
	}
	return 0;
}