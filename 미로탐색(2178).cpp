#include <stdio.h>
#include <queue>
using namespace std;
//dfs는 시간초과, 최단거리는 bfs로
int N, M;
int check[101][101]; // 시작점으로부터의 거리 표시
int visit[101][101]; // 방문표시
char map[101][101]; 
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs(int x, int y)
{
	visit[x][y] = 1; 

	queue<pair<int, int> > q; 
	q.push(make_pair(x, y)); 

	while (!q.empty()) 
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop(); 

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < N && 0 <= ny && ny < M) //범위
			{
				// 방문x
				if (map[nx][ny] == '1' && visit[nx][ny] == 0)
				{
					check[nx][ny] = check[x][y] + 1;
					visit[nx][ny] = 1;
					q.push(make_pair(nx, ny)); 
				}

			}

		}
	}

}

int main(void)
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", map[i]);
	}

	bfs(0, 0);
	printf("%d\n", check[N - 1][M - 1] + 1);
}