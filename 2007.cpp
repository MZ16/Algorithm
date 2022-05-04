#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// 반복되는 마디(문자열)의 길이를 구하는 문제
// STL - substr(start idx, 갯수) / 부분 문자열 추출

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		string s, tmp="";
		int cnt = 0;
		cin >> s;
		for (int j = 1; j < s.size(); j++) {
			if (s[cnt] == s[j])cnt++; // 첫번쨰 마디 이후 동일한 마디가 나온다면 계속 증가함
			else cnt = 0;
		}
		printf("#%d %d\n", i, (int)s.size() - cnt);
	}

}