#include <bits/stdc++.h>
using namespace std;



string removeLeadingZero(string num) {
	while (1) { 
		if (num.size() && num.front() == '0')num.erase(num.begin()); // 참조에러 방지를 위해 size도 같이
		else break;
	}
	if (num.empty())return "0";
	else return num;
}

bool cmp(string a, string b) {
	if (a.size() == b.size())return a < b;
	return a.size() < b.size();
}

int main() {
	vector <string> v;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s,tmp="";
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] >= '0' && s[j] <= '9') {
				tmp += s[j];
			}
			else if(!tmp.empty()){
				tmp = removeLeadingZero(tmp);
				v.push_back(tmp);
				tmp = "";
			}
		}
		if (!tmp.empty()) {
			tmp = removeLeadingZero(tmp);
			v.push_back(tmp);
			tmp = "";
		}
	}
	sort(v.begin(), v.end(), cmp);
	for (auto i : v)cout << i << "\n";
	
	
	return 0;
}

/*
해당 문제는 최대 10^99 자리의 수가 나올 수 있으므로 정수형태를 사용하면 안되는 문제이고
custom operator를 사용해야 한다.
tmp가 empty가 아닌상태로 반복문이 끝나는 경우를 고려해 한번더 체크, 반복문을 더 돌릴 경우 if문에서 out of bounds, out of range등의 오류가 생길 수 있음
*/