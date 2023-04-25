#include <bits/stdc++.h>
using namespace std;

int dp[100];

void init() {
	for (int i = 1; i < 45; i++)
		dp[i] = dp[i - 1] + i;
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	init();
	int T;
	cin >> T;
	while (T--) {
		int K, flag = 0;
		cin >> K;
		for(int i=1; i<45; i++)
			for (int j = 1; j < 45; j++)
				for (int k = 1; k < 45; k++) 
					if ((dp[i] + dp[j] + dp[k]) == K) 
						flag = 1;
					
				
		cout << flag<<"\n";
	}

	return 0;
}