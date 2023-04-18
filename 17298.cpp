#include <bits/stdc++.h>
using namespace std;

int arr[1000001];
int ans[1000001];
vector<int> s; // index 저장
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	memset(ans, -1, sizeof(ans)); // 초기값 -1
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		while (s.size() && arr[s.back()] < arr[i]) {
			ans[s.back()] = arr[i]; s.pop_back();
		}
		s.push_back(i);
	}

	for (int i = 0; i < N; i++)cout << ans[i] << " ";
	return 0;
}

/*
- 보통 brute force의 경우 1억, 천만이하의 연산은 괜찮지만 해당 문제는 100만 * 100만으로 안된다.
- 스택을 통해 해결하여 시간복잡도를 줄인다.
- stack, vector등을 사용할 때 size()를 우선 확인하지 않으면 메모리참조 에러가 발생함을 유의한다.

1.	오큰수(오른쪽에 큰 수) 가 등장하기 전까지 stack에 입력받은 idx값을 넣어둔다.
2.	idx를 넣어 두었으므로 배열의 idx를 s.top으로 접근하여 오큰수가 등장하였다면 // arr[s.top()] == arr[idx]
	해당 idx(s.top)를 ans배열의 idx에 오큰수를 저장한다. // ans[s.top()]=arr[i]
*/