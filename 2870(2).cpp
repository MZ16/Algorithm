#include <bits/stdc++.h>
using namespace std;



string removeLeadingZero(string num) {
	while (1) { 
		if (num.size() && num.front() == '0')num.erase(num.begin()); // �������� ������ ���� size�� ����
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
�ش� ������ �ִ� 10^99 �ڸ��� ���� ���� �� �����Ƿ� �������¸� ����ϸ� �ȵǴ� �����̰�
custom operator�� ����ؾ� �Ѵ�.
tmp�� empty�� �ƴѻ��·� �ݺ����� ������ ��츦 ����� �ѹ��� üũ, �ݺ����� �� ���� ��� if������ out of bounds, out of range���� ������ ���� �� ����
*/