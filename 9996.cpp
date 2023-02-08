#include <bits/stdc++.h>
using namespace std;

// find - 문자열에서 특정문자의 위치를 가르쳐줌
// substr - 지정된 범위의 문자열을 가져옴, 시작점만 지정할 경우 끝까지 가져옴

string ptn, s, first, last;

int main() {
	int N;
	cin >> N;
	cin >> ptn;
	int pos = ptn.find('*');
	first = ptn.substr(0, pos);
	last = ptn.substr(pos + 1); // 별 기점으로 끝까지

	for (int i = 0; i < N; i++) {
		cin >> s;
		if (s.size() < first.size() + last.size()) cout << "NE\n"; // 패턴이 문자열보다 길 경우
		else {
			if (s.substr(0, first.size()) == first && s.substr(s.size() - last.size()) == last) cout << "DA\n";
			else cout << "NE\n";
		}
	}

	return 0;
}