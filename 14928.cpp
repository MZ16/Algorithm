#include<bits/stdc++.h>
#define MOD 20000303
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string N;
	cin >> N;
	int res = 0;
	for (int i = 0; i < N.size(); i++) {
		res = ((res * 10)+(N[i]-'0')) % MOD;
	}
	cout << res;

	return 0;
}