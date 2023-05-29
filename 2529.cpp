#include <bits/stdc++.h>
using namespace std;

int visited[11];
char inq[11];
int N;
string sMin="9999999999", sMax="0", s;

bool cmp(string a, string b) {
	if (a.size() > b.size())return 1;
	else if (a > b) return 1;
	else return 0;
}

void dfs(int prev,int idx) {

	if (s.size() == N+1) {
		if (cmp(s, sMax)) sMax = s;
		if(!cmp(s, sMin)) sMin = s;
		return;
	}
	if (inq[idx] == '>') {
		for (int i = 0; i < prev; i++) {			
			if (visited[i])continue;
			visited[i] = 1;
			s += to_string(i);
			dfs(i, idx+1);
			s.pop_back();
			visited[i] = 0;
		}
	}

	if (inq[idx] == '<') {
		for (int i = prev+1; i < 10; i++) {
			if (visited[i])continue;
			visited[i] = 1;
			s += to_string(i);
			dfs(i, idx + 1);
			s.pop_back();
			visited[i] = 0;
		}
	}
	return;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> inq[i];
	}
	
	for (int i = 0; i <= 9; i++) { // 가장 앞자리 처리
		visited[i] = 1;
		s += to_string(i);
		dfs(i, 0);
		s.pop_back();
		visited[i] = 0;
	}
	
	cout << sMax << "\n";
	cout << sMin;
	return 0;
}
/*
* cmp() - 최소, 최댓값을 구하기 위해 size와 ascii 값을 비교
* backtracking
*	부등호 '>'일 때 prev(이전 값)보다 작아야 함으로 i<prev까지 반복하며 백트레킹한다.
*	부등호 '<'일 때 ,prev(이전 값)보다 커야 함으로 i=prev+1; i<10까지 반복하며 백트레킹한다.
*	기저조건으로 저장된 문자열 사이즈가 N+1일 때 cmp함수를 통해 max min값을 구한다.
* main
*	dfs만으로 로직을 구성하면 가장 앞자리 처리에서 문제가 생긴다 
*		ex) 가장 앞자리가 0이고 부등호가 '>'라면 모든 조건이 성립하지 않음. 
*		부호와 비교값이 만족할 때 재귀와 원복이 이루어 져야하는데
*		위 처럼 모든 조건이 성립하지 않는 경우가 생김
*	이를 해결하기 위해 가장 앞자리 처리를 main에서의 백트레킹으로 처리해준다.
*/