#include <bits/stdc++.h>
using namespace std;

int N;
deque<int> v;

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		v.push_back(i);
	}
}

void Solve() {
	int i = 1;
	while (!v.empty()) {
		cout << v.front() << " ";
		v.pop_front();
		if (v.empty()) return;
		int tmp = v.front();
		v.push_back(tmp);
		v.pop_front();		
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Input();
	Solve();

	return 0;
}