#include <bits/stdc++.h>
#include <string>
using namespace std;

// �ִ� 100����, �� 10^99.. ������ �����ϸ� Ǯ �� ����.
// bigInt or string���� ���� (string ���)
// ���ڸ��� 0�� ��������, �� '0' �Ǵ� 0���θ� �̷���� ���� 0�� ǥ���ؾ���
// ���ڿ��� ���������� �� �ڸ��� �ƽ�Ű���� ������� ���ϱ� ������ custom operator�� ��������� �Ѵ�.

int N;
vector<string> v;
string s, ret = "";

bool cmp(string a, string b) { // custom operator
	if (a.size() == b.size()) return a < b; // 2. size�� ���ٸ� �ƽ�Ű������ ó��
	return a.size() < b.size(); // 1. size ��
}

void func() { // zero erase
	while (1) { // ���ڸ� '0' ����
		if (ret.size() && ret.front() == '0')ret.erase(ret.begin()); // �������� ������ ���� size�� ����
		else break;
	}
	// 0���θ� ������ ��� 
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