#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	long long int N, M,result=0;
	cin >> N >> M;
	result = N - M;
	if (result < 0)result *= -1;
	cout << result;

	return 0;
}