#include <bits/stdc++.h>
using namespace std;

// 괄호 문제이므로 스택형태로 처리한다.

int main() {
	while (1) {
		string s;
		vector<char> v; // 괄호
		int flag = 0;
		getline(cin, s);
		if (s[0] == '.')break;
		for (int i = 0; i < s.length(); i++) {			
			if (s[i] == '(' || s[i] == '[')v.push_back(s[i]);
			else if (s[i] == ')') { // 1.
				if (!v.empty() && v.back() == '(')v.pop_back(); // 2.
				else flag = 1;
			}
			else if (s[i] == ']') {
				if (!v.empty() && v.back() == '[')v.pop_back();
				else flag = 1;
			}
		}
		if (flag||!v.empty())cout << "no\n";
		else cout << "yes\n";				
	}

	return 0;
}

// 오답노트
// 1. 해당 위치에서 empty()를 확인하면 vector가 비어있을 때 ')' , ']'가 입력되면 확인해 주기 위한 flag 까지 동작하지 않는다.
// 2. 기존 코드는 v.back() && !v.empty() 였는데 이럴경우 빈공간임에도 v.back()부터 참조하여 참조에러가 발생함, back()과 empty()의 순서를 바꿔주면 해결된다.