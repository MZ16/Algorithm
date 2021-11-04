#include <iostream>
#include <cstring>
#include <queue>
#include <stdio.h>
#define MAX_SIZE 100001
using namespace std;

/* 0<= N,K <=100,000 ÀÎµ¥ OutOfBounds ³²*/
int visited[MAX_SIZE];
int N, K;

void bfs() {	
	queue <int> q;
	visited[N] = 1;
	q.push(N);
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (x == K)return;

		for (int i = 0; i < 3; i++) {
			int nx;
			if (i == 0)nx = x + 1;
			else if (i == 1)nx = x - 1;
			else if (i == 2) nx = x * 2;

			// if (!visited[nx] && nx >= 0 && nx < 100001) { OutOfBounds!!!!
				if(nx>=0 && nx<=100000 && !visited[nx]){
				visited[nx] = visited[x] + 1;
				q.push(nx);
			}
		}
	}
	
}

int main() {
	scanf("%d %d", &N, &K);
	bfs(); printf("%d", visited[K]-1);
	return 0;
}