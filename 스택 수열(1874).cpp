#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int seq[100001];
vector<int> v;
vector<char>str;

int main() {
	int n;
	int len = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &seq[i]);		
	}
	for (int i = 1; i <= n; i++) {
		v.push_back(i);
		str.push_back('+');
		while (!v.empty() && v.back() == seq[len]) {
			v.pop_back();
			str.push_back('-');
			len++;
		}
	}
	if (!v.empty())printf("NO");
	else {
		for (int i = 0; i < str.size(); i++)printf("%c\n", str[i]);
	}
	return 0;
}
/*
1부터 n까지의 수를 스택에 넣다가 임의의 수열값과 같다면 pop
위의 연산이 끝난후에 스택에 값이 남았다면 NO 출력
*/