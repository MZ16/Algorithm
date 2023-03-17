#include <bits/stdc++.h>
using namespace std;


bool isVowel(int idx) { // 모음 판독
	return ((idx == 'a') || (idx == 'e') || (idx == 'i') || (idx == 'o') || (idx == 'u'));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	while (1) {
		string s;
		cin >> s;
		if (s == "end")break;
		int idx = 0; // 현재 문자
		// 모음 or 자음이 연속 3번오는것을 체크하기 위함		
		int Vcnt = 0; int Lcnt = 0; // 모음, 자음 cnt		 
		

		int is_Include_V = 0;// 자음 포함 판별
		int prev = 0; // 동일한 문자 연속 판별 (ee, oo는 허용)

		int flag = 0;

		for (int i = 0; i < s.size(); i++) {
			idx = s[i];
			//cout << (char)idx << " " << (char)prev<<"\n";
			if (isVowel(idx)) { Vcnt++; Lcnt = 0; is_Include_V = 1; if (Vcnt == 3)flag = 1;	} 
			else { Lcnt++; Vcnt = 0; if (Lcnt == 3)flag = 1; }
			
			if ((i > 0 && idx == prev) && (idx != 'e' && prev != 'e') && (idx != 'o' && prev != 'o')) { flag = 1; }
			prev = idx;
		}
		if (!is_Include_V)cout << "<" << s << ">" << " is not acceptable.\n";
		else if(flag)cout << "<" << s << ">" << " is not acceptable.\n";
		else cout << "<" << s << ">" << " is acceptable.\n";
	}
	

	return 0;
} 