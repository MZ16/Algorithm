#include <bits/stdc++.h>
using namespace std;

// custom operator가 핵심
// 이 문제에서 C의 범위가 10억이다.그래서 idx기반 카운팅배열 생성 시 
// Array와 vector는 탐색 시 O(n)의 시간이 걸리기 때문에 O(log n)인 map을 사용하는것이 적합하다
// map은 참조만 하여도 요소가 생김, 

/* 햇갈림
*	mp			- (first - 숫자), (second - 개수)		/	카운팅배열
* mp_first		- (first - 숫자), (second - 등장idx)	/	숫자 등장 순위
*	v			- (first - 개수), (second - 숫자)		/	custom operator 인자
* bool type
*/

// 우선순위 
// 1. 빈도 수
// 2. 먼저 입력된 값(빈도 수가 같을경우 포함)
typedef pair<int, int> pii;
vector<pii> v;
map<int, int> mp, mp_first;
int N, C;

bool cmp(pii a, pii b) {
	if (a.first == b.first) return mp_first[a.second] < mp_first[b.second]; // a의 숫자 등장 순위가 빠르면 true
	return a.first > b.first; // a의 빈도수가 크면 true
}

int main() {
	cin >> N >> C;
	for (int idx,i = 1; i <= N; i++) {
		cin >> idx;
		mp[idx]++;
		if (mp_first[idx] == 0)mp_first[idx] = i; // i를 0부터 하면 map의 특성상 참조만해도 요소가 생기는 것 떄문에 조건문 로직에 문제가 생김
	}
	
	for (auto i : mp) v.push_back({ i.second, i.first });

	sort(v.begin(), v.end(), cmp);

	for (auto i : v) 
		for (int j = 0; j < i.first; j++) cout << i.second << " ";
	
	return 0;
}
