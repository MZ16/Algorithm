#include <bits/stdc++.h>
using namespace std;

// ��ȣ �����̹Ƿ� �������·� ó���Ѵ�.

int main() {
	while (1) {
		string s;
		vector<char> v; // ��ȣ
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

// �����Ʈ
// 1. �ش� ��ġ���� empty()�� Ȯ���ϸ� vector�� ������� �� ')' , ']'�� �ԷµǸ� Ȯ���� �ֱ� ���� flag ���� �������� �ʴ´�.
// 2. ���� �ڵ�� v.back() && !v.empty() ���µ� �̷���� ������ӿ��� v.back()���� �����Ͽ� ���������� �߻���, back()�� empty()�� ������ �ٲ��ָ� �ذ�ȴ�.