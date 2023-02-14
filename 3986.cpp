#include <bits/stdc++.h>
using namespace std;

// 같은 단어끼리 묶어 위로 아치형 곡선을 그려 교차하지 않는 단어가 좋은 단어 인 문제

// Ex) AABB, ABBA, ABBABB의 패턴이 좋은 단어라 볼 수있다.
// Stack을 활용하여 empty가 아닐경우
//		1. top과 현재 단어를 비교하여 같으면 pop
//		2. 단어가 다르다면 push
// empty일 경우 현재 단어 push
// 반복문이 끝나고 스택이 비었다면 좋은단어이며 카운트를 증가시킨다.

int main() {
	int N,cnt=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		vector <char> v; // 스택 대신
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