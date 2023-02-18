#include <bits/stdc++.h>
using namespace std;

// (a+b) % n = (a%n) + (b%n)
// 1로 이루어진 N의 배수를 찾는 문제, N<=10,000 , 모듈러 연산을 해야 overflow가 생기지 않음
// 111 = (1 * 10) + 1 -> (11*10) + 1
// 매 순간 자릿값은 증가하고 cnt = (cnt*10)+1 이라는 공식이 성립됨을 알 수 있다.
// 모듈러 연산 중 0이 되면 배수이므로 그 때 종료한다.

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	while (cin >> N) {
		int cnt = 1, ret = 1;
		for(;;) {
			if (cnt%N==0) { // !cnt, cnt==0의 조건은 틀렷습니다 나옴, else문에서 cnt %= N을 통해 0이 되지 않나..?
				cout << ret << "\n";
				break;
			}
			else {
				ret++;
				cnt = (cnt * 10) + 1;
				cnt %= N;				
			}
		}
	}
	return 0;
}