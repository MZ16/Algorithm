#include <bits/stdc++.h>
using namespace std;

// ���� �ܾ�� ���� ���� ��ġ�� ��� �׷� �������� �ʴ� �ܾ ���� �ܾ� �� ����

// Ex) AABB, ABBA, ABBABB�� ������ ���� �ܾ�� �� ���ִ�.
// Stack�� Ȱ���Ͽ� empty�� �ƴҰ��
//		1. top�� ���� �ܾ ���Ͽ� ������ pop
//		2. �ܾ �ٸ��ٸ� push
// empty�� ��� ���� �ܾ� push
// �ݺ����� ������ ������ ����ٸ� �����ܾ��̸� ī��Ʈ�� ������Ų��.

int main() {
	int N,cnt=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		vector <char> v; // ���� ���
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			
			
			if(!v.empty()) { 
				if (v.back() == s[j])v.pop_back();
				else v.push_back(s[j]);
			}
			else v.push_back(s[j]); 			
			
		}
		if (v.empty())cnt++;
	}
	cout << cnt;
	return 0;
}