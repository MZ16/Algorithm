#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// �ݺ��Ǵ� ����(���ڿ�)�� ���̸� ���ϴ� ����
// STL - substr(start idx, ����) / �κ� ���ڿ� ����

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		string s, tmp="";
		int cnt = 0;
		cin >> s;
		for (int j = 1; j < s.size(); j++) {
			if (s[cnt] == s[j])cnt++; // ù���� ���� ���� ������ ���� ���´ٸ� ��� ������
			else cnt = 0;
		}
		printf("#%d %d\n", i, (int)s.size() - cnt);
	}

}