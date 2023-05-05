#include <bits/stdc++.h>
using namespace std;



string removeLeadingZero(string num) {
	int i = 0;	
	while (i < num.size() && num[i] == '0') {
		i++;
	}
	if (num.size() == i) return "0";
	return num.substr(i);
}

int main() {
	vector <int> v;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s,tmp;
		cin >> s;
		int len = s.size();
		for (int j = 0; j <= len; j++) {
			if (s[j] >= '0' && s[j] <= '9') {
				tmp += s[j];
			}
			else if(!tmp.empty()){
				tmp = removeLeadingZero(tmp);
				v.push_back(stoi(tmp));
				tmp = "";
			}
		}
	}
	sort(v.begin(), v.end());
	for (auto i : v)cout << i << "\n";
	
	
	return 0;
}

/*
�ش� ������ �ִ� 10^99 �ڸ��� ���� ���� �� �����Ƿ� �������¸� ����ϸ� �ȵǴ� �����̰�
custom operator�� ����ؾ� �Ѵ�. �����ڵ�� 2870.cpp
*/