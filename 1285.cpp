#include<bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int ans = INF;
int N;
int col[42]; // T=1, H=0

void func(int depth) {
	if (depth == N + 1) // 마지막 depth라면
	{
		int sum = 0;
		for (int i = 1; i <= (1 << N-1); i *= 2) { // row binary
			int cnt=0;
			for (int j = 1; j <= N; j++) {
				if (col[j] & i)cnt++; // row 'T' check				
			}	
			sum += min(cnt, N - cnt); // row의 최적해
		}
		ans = min(ans, sum);
		return;
	}

	// col
	func(depth + 1);	//안뒤집기
	col[depth] = ~col[depth];
	func(depth + 1);	//뒤집기
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		string s;
		int value = 1;
		cin >> s;
		for (int j = 0; j < N; j++) { // 각 행에대한 비트마스킹
			if (s[j] == 'T')col[i] |= value;
			value *= 2;
		}
	}

	func(1);
	cout << ans;

	return 0;
}

/*
* N <= 40, O(2^40)
* 연산 불가능한 시간복잡도이므로 단축시킨다. / 열과 행이 아닌 행에 대해서만 연산을 진행 - O(2^20)
* 행만 뒤집고 나면 열의 최적해는 정해져 있다.
* 동전을 뒤집는것은 '~'연산자를 통해 뒤집고 필요한 비트만 검사한다.
*	반전비트는 pc의 bit수만큼 일어나지만 범위를 지정하여 필요한 부분만 검사한다.
* 
* 초기화
* 행에대한 비트마스킹 값을 담을 배열을 만든다.
* 'T'에대한 값을 'OR' 연산자로 해당 index에 저장한다. / T=1, H=0
*		ex)	for(int j = 0; j < s.size(); j++){
				if(s[j] == 'T')a[i] |= value; 
				value *= 2;
			}
* if(here==n+1) / 모든 경우의 수는 마지막 depth에 조합이 완성됨을 인지.
*/