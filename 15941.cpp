#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N;
	int tc;
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		cin >> N;
		cout << "#" << i << " " << pow(N,2)<<"\n";
	}
	return 0;
}