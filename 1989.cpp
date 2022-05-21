#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// 초심자의 회문검사. 1989
/* 중간값 제외 앞 절반 뒤 절반 모두 같으면 1 아니면 0

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