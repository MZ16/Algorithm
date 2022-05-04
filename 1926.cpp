#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
// 숫자를 문자로 to_string();
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		string s = to_string(i);
		int cnt = 0;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '3' || s[j] == '6' || s[j] == '9') {
				cnt++;
			}
		}
		if (cnt) {
			for (int j = 0; j < cnt; j++) {
				printf("-");
			}printf(" ");
		}else printf("%d ", i); 

	}

	return 0;
}