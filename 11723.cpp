#include <bits/stdc++.h>
using namespace std;

int N,num,ans;
string s;

void Solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		s.clear();
		cin >> s;
		if (s == "add") {
			cin >> num;
			ans |= (1<<num);
		}
		else if (s == "remove") {
			cin >> num;
			ans &= ~(1 << num);
		}
		else if (s == "check") {
			cin >> num;
			if (ans & (1<<num))cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (s == "toggle") {
			cin >> num;
			if (ans & (1<<num)) ans &= ~(1<<num);
			else ans |= (1<<num);
		}
		else if (s == "all") {
			ans = (1 << 21) - 1;
				
		}
		else if (s == "empty") {
			ans = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Solve();

	return 0;
}

/*
S의 범위가 1<=20으로 비트마스킹으로 문제를 해결해줌
toggle은 if ~ else 문을 빼고 xor연산으로도 처리 가능
*/