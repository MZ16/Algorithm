#include <bits/stdc++.h>
using namespace std;


bool isVowel(int idx) { // ���� �ǵ�
	return ((idx == 'a') || (idx == 'e') || (idx == 'i') || (idx == 'o') || (idx == 'u'));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	while (1) {
		string s;
		cin >> s;
		if (s == "end")break;
		int idx = 0; // ���� ����
		// ���� or ������ ���� 3�����°��� üũ�ϱ� ����		
		int Vcnt = 0; int Lcnt = 0; // ����, ���� cnt		 
		

		int is_Include_V = 0;// ���� ���� �Ǻ�
		int prev = 0; // ������ ���� ���� �Ǻ� (ee, oo�� ���)

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