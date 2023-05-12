#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	int len = 2 * N;
	int i = 1,flag=0;
	while (len--) {
		for (int j = 0; j < i; j++)cout << '*';		
		if (i == N)flag = 1;
		if (!flag)i++;
		else i--;
		cout << "\n";
	}

	return 0;
}