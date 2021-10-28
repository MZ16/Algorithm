#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int solve(int N) {
	string s;
	int val = 666;
	int cnt = 0;
	while (1) {
		s = to_string(val);
		for (int i = 0; i < s.length() - 2; i++) {
			if (s[i] == '6' && s[i + 1] == '6' && s[i + 2] == '6') {
				cnt++;
				if (cnt == N) {
					return val;					
				}break;
			}		
		}val++;
	}
}

int main() {
	int N; 
	cin >> N;

	printf("%d", solve(N));

	return 0;
}