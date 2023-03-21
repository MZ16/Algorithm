#include <bits/stdc++.h>
#include <string>
using namespace std;

// 최대 100글자, 즉 10^99.. 정수로 접근하면 풀 수 없다.
// bigInt or string으로 접근 (string 사용)
// 앞자리의 0은 생략가능, 단 '0' 또는 0으로만 이루어진 수는 0을 표기해야함
// 문자열의 오름차순은 각 자리의 아스키값을 기반으로 비교하기 떄문에 custom operator를 정의해줘야 한다.

int N;
vector<string> v;
string s, ret = "";

bool cmp(string a, string b) { // custom operator
	if (a.size() == b.size()) return a < b; // 2. size가 같다면 아스키값으로 처리
	return a.size() < b.size(); // 1. size 비교
}

void func() { // zero erase
	while (1) { // 앞자리 '0' 삭제
		if (ret.size() && ret.front() == '0')ret.erase(ret.begin()); // 참조에러 방지를 위해 size도 같이
		else break;
	}
	// 0으로만 구성된 경우 
	if (ret.empty())ret = "0";
	v.push_back(ret);
	ret = "";
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	
	for (int i = 0; i < N; i++) {		
		cin >> s;
		ret = "";
		for (int j = 0; j < s.size(); j++) {
			if (s[j]>='0' && s[j]<='9')ret += s[j];
			else if(!ret.empty())func();
		}
		if (!ret.empty())func();
	}
	sort(v.begin(), v.end(),cmp);
	for (auto i : v)cout << i << "\n";

	return 0;
}