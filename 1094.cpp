#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int X,cnt=0;
	cin >> X;
	for (int i = 0; i < 7; i++) {
		if (X & (1 << i)) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}