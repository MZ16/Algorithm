#include <bits/stdc++.h>
using namespace std;

// find - ���ڿ����� Ư�������� ��ġ�� ��������
// substr - ������ ������ ���ڿ��� ������, �������� ������ ��� ������ ������

string ptn, s, first, last;

int main() {
	int N;
	cin >> N;
	cin >> ptn;
	int pos = ptn.find('*');
	first = ptn.substr(0, pos);
	last = ptn.substr(pos + 1); // �� �������� ������

	for (int i = 0; i < N; i++) {
		cin >> s;
		if (s.size() < first.size() + last.size()) cout << "NE\n"; // ������ ���ڿ����� �� ���
		else {
			if (s.substr(0, first.size()) == first && s.substr(s.size() - last.size()) == last) cout << "DA\n";
			else cout << "NE\n";
		}
	}

	return 0;
}