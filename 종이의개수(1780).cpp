#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 2188

int N;
int map[MAX_LEN][MAX_LEN];
bool visited[MAX_LEN][MAX_LEN];
int cntZero, cntOne,cntMin;

void dfs(int y, int x, int size) {
	visited[y][x] = true;
	bool Zero=true, One=true,Min=true;
	for (int i = y; i < y+size; i++) {
		for (int j = x; j < x+size; j++) {
			if (map[i][j] == -1) {
				Zero = false;
				One = false;
				
			}if (map[i][j] == 0) {
				Min = false;
				One = false;
			}
			if (map[i][j] == 1) {
				Min = false;
				Zero = false;
			}
			
				
		}
	}
	if (One) { cntOne++; return; }
	if (Zero) { cntZero++; return; }
	if (Min) { cntMin++; return; }
	/*범위 3^n, 9분할 해야됨 */
	int div = size / 3;
	dfs(y, x, div);
	dfs(y, x+div, div);
	dfs(y, x + 2*div, div);

	dfs(y+div, x, div);
	dfs(y+div, x + div, div);
	dfs(y+div, x + 2 * div, div);

	dfs(y + 2*div, x, div);
	dfs(y + 2*div, x + div, div);
	dfs(y + 2*div, x + 2 * div, div);
	
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			scanf("%d", &map[i][j]);

	dfs(0, 0,N);
	printf("%d\n", cntMin);
	printf("%d\n", cntZero);
	printf("%d\n", cntOne);

	return 0;
}
