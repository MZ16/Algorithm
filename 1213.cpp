#include <bits/stdc++.h>
using namespace std;

// 해당 문제는 전체 문자를 가지고 오름차순으로 팰린드롬이 될 수 있게 재배열하는 문제이다.
// 
//  오름차순으로 배치해야 함으로 역순으로 시작한다.
//  홀수의 경우 무조건 중앙배치를 요한다. 
//		1. mid를 찾아주고 중앙 배치할 값을 제외하기 위해 1개를 빼준다.
//		2. mid값을 뺴주었기 때문에 짝수가 되어 재배열이 가능해진다.
//  펠린드롬의 조건 중 홀수의 문자가 2개이상 있다면 펠린드롬의 형태가 불가능하다.
//	팰린드롬의 형태를 띄기위해 짝수갯수만큼 처리해준다.
//	펠린드롬 형태의 배치를 위해 ret = 문자 + ret; / ret+=문자 의 형태로 앞뒤로 배치되게 한다.
//	mid값을 중앙에 삽입해준다.

string s, ret;
int cnt[150],flag=0;
char mid;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> s;
	for (auto a : s) cnt[a]++; // 해당 문자열의 갯수를 파악하기 위함
	for (int i = 'Z'; i >= 'A'; i--) { // 오름차순 배치를 위해 역순
		// 홀수처리
		if (cnt[i] % 2 == 1) {
			flag++;
			mid = (char)i;
			cnt[i]--; // mid값을 빼주어 이후 짝수처리 때 한번에 처리하기 위함
		}

		if (flag == 2)break; // 홀수가 2개 이상이면 팰린드롬이 불가능

		for (int j = 0; j < cnt[i]; j += 2) {
			// 팰린드롬 형태의 배치를 위해 앞, 뒤로 더해줌
			ret = (char)i + ret; 
			ret += i;
		}
	}
	if (mid) ret.insert(ret.begin() + ret.size() / 2, mid);
			
	if (flag < 2) cout << ret;
	else cout << "I'm Sorry Hansoo";
	
	return 0;
}