#include <bits/stdc++.h>
using namespace std;

string add(string a, string b) {
	int carry = 0;
	string res = "";
	int i = a.length() - 1; int j = b.length() - 1;
	while (i >= 0 || j >= 0 || carry > 0) {
		int sum = carry;
		if (i >= 0) sum += (a[i--] - '0');
		if (j >= 0) sum += (b[j--] - '0');
		carry = sum / 10;
		sum %= 10;
		res = to_string(sum) + res;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N;
	string first = "0", second = "1", res;
	cin >> N;
	if (N == 0) { cout << "0"; return 0; }
	if (N == 1) { cout << "1"; return 0; }
	for (int i = 1; i < N; i++) {
		res=add(first, second);
		first = second;
		second = res;
	}
	cout << res;
	return 0;
}