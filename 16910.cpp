#include <bits/stdc++.h>
using namespace std;

// x^2 + y^2 = N^2

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T,num=1;
	cin >> T;
	while (T--) {
		int N,cnt=0;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (pow(N, 2) >= pow(i, 2) + pow(j, 2))cnt++;
			}
		}
		cnt *= 4;
		cnt = cnt+1+(N*4); // 가로, 세로 격자점 + 원의 중심
		cout << "#"<<num++<<" "<< cnt << "\n";
	}

	return 0;
}