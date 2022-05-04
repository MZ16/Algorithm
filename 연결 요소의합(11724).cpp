#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;


int N, M;
vector <int> arr[1002];
bool visited[1002];
int cnt=0;

void dfs(int val) {
	visited[val] = true;
	//for (int i = 0; i < sizeof(arr[val]) / sizeof(int); i++) {
	for (int i = 0; i < arr[val].size(); i++) {
		int nxt = arr[val][i];
		if (!visited[nxt]) dfs(nxt);
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int v1,v2,i = 0; i < M; i++) {
		scanf("%d %d", &v1, &v2);
		arr[v1].push_back(v2);
		arr[v2].push_back(v1);
	}

	for (int i = 1; i <= N; i++) {
		if(visited[i]) continue;
		dfs(i);
		cnt++;
	}
	printf("%d", cnt);
	return 0;
}

/*
1 <= N <= 1,000
0 <= M <= N*(N-1)/2  // 50만까지 가능
배열로 관리하기엔 범위가 너무 크다. 백터 사용
*/