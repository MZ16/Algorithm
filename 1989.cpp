#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// �ʽ����� ȸ���˻�. 1989
/* �߰��� ���� �� ���� �� ���� ��� ������ 1 �ƴϸ� 0

*/
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		bool chk = true;
		int left = 0, right = s.size()-1;
		int mid = s.size() / 2;
		// left
		for (int i = 0; i < mid; i++) {
			if (s[left] != s[right]) {
				chk = false;
				break;
			}left++, right--;
		}
		if (chk) printf("#%d 1\n", i);
		else printf("#%d 0\n", i);
			
		
	}

	return 0;
}