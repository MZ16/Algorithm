#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool chk[988]; //안되는 수를 모두 체크함

int N,st,b,ans;
int stCnt, bCnt;
string s1,s2;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s1 >> st >> b;
		for (int j = 123; j <= 987; j++) {
			s2 = to_string(j);
			//중복 숫자를 미리 처리해둠
			if (s2[0] == s2[1] || s2[0] == s2[2] || s2[1] == s2[2]) {
				chk[j] = true;
				continue;
			}
			//1~9까지임으로 0을 처리해줌
			if (s2[0] -'0'==0 || s2[1] - '0' == 0 || s2[2] - '0' == 0) {
				chk[j] = true;
				continue;
			}
			stCnt = 0;
			bCnt = 0;

			//입력된 st와 b가 되는경우를 제외하고 모두 처리함
			for (int x = 0; x < 3; x++) {
				for (int y = 0; y < 3; y++) {
					if (x == y && s1[x] == s2[y])stCnt++;
					if (x != y && s1[x] == s2[y])bCnt++;
				}
			}
			if (st != stCnt || b != bCnt) {
				chk[j] = true;
				continue;
			}
		}

	}
	for (int i = 123; i < 988; i++) {
		if (chk[i])continue;
		ans++;
	}
	cout << ans;

}