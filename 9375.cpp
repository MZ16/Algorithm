#include <bits/stdc++.h>
using namespace std;

// 경우의수는 곱셈으로 구성되며 문제의 입력을 예시로 하면
	// headgear = hat + turban + NULL = 3 // eyewear = sunglasses + NULL = 2
	// headgear * eyewear -1(문제에서 아무것도 안입을경우는 제외) = 5 라는 공식이 성립한다.
// 
// 경우의 수는 값이 커질확률이 높음으로 출려값을 long long으로 설정하는것이 좋다.

int TC, N;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> TC;
	for (int i = 0; i < TC; i++) {
		map<string, int> mp;
		cin >> N;
		for (int j = 0; j < N; j++) {
			string a, b; // a는 종류, b는 key값
						// 해당 문제에서 종류의 갯수만 필요함으로 key에 수를 증가시켜줌
			cin >> a >> b;
			mp[b]++;
		}
		long long ret = 1; // 경우의 수
		for (auto a : mp) {
			ret *= (long long)a.second + 1;
		}

		cout << ret - 1<<"\n";
	}

	return 0;
}

/*
* 문제 조건
* 같은 이름을 가진 의상은 존재하지않음 // 종류 : cnt(갯수)
* 아무것도 입지않을 경우 제외 // -1
* 
* 여기까지 알수있는건 입력값 a는 실질적으로 사용되지 않으며
* 전체 경우의 수 -1 이 정답이다. 
* 전체 경우의 수에는 각 종류별로 입지 않는 경우까지 고려하여 NULL을 추가한다.
* 경우의 수는 매우 커질 수 있으므로 long long을 사용한다.

*/