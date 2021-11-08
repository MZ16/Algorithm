#include<iostream>
#include <string>
using namespace std;
/*O(N^2) x, O(N) o*/
int N, M,ans;
string s;
int main() {
	cin >> N >> M;
	cin >> s;
	for (int i = 0; i < M; i++) {
		int cnt = 0;
		if (s[i] == 'O')continue;
		else {			
			while (s[i + 1] == 'O' && s[i + 2] == 'I') {
				cnt++;
				if (cnt == N) {
					cnt--; // 중복 방지
					ans++;
				}				
				i += 2;
			}
			cnt = 0;
		}		
	}
	cout << ans;
	return 0;
}