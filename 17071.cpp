#include <bits/stdc++.h>
using namespace std;

int depth = 1;
int flag;
int visited[2][500002];
int N, K;

void bfs() {
    queue<int>q;
    visited[0][N] = 1;
    q.push(N);
    while (!q.empty()) {
        K += depth;
        if (K > 500000)return;
        if (visited[depth % 2][K]) { // 짝수, 홀수가 일치하는 depth에서 방문한 적이 있으면 만날 수 있음
            flag = 1;
            return;
        }
        int qSize = q.size();
        for (int i = 0; i < qSize; i++) {
            int now = q.front(); q.pop();
            for (int next : {now - 1, now + 1, now * 2}) {
                if (next < 0 || next>500000 || visited[depth % 2][next])continue;
                visited[depth % 2][next] = visited[(depth + 1) % 2][now] + 1;
                if (next == K) { flag = 1; return; }
                q.push(next);
            }
        }
        depth++;        
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> K;
    if (N == K) {
        cout << 0;
        return 0;
    }
    bfs();
    if (flag)cout << depth;
    else cout << -1;

    return 0;
}
/* 0 <= N,K <= 500,000
* N(수빈)이는 500,000을 넘어갈 수 없고 동생은 넘어갈 수 있음 / 즉 동생이 넘어가면 -1
* K(동생)은 매 depth마다 depth만큼 이동함
* N이 K에 먼저 방문한 경우 N과 K는 각 depth가 둘다 홀수 or 짝수일 경우 서로 만날 수 있음 / N이 먼저 방문한 경우만!
*   홀짝 구분을 위해 [2][MAX]크기의 배열을 만들고 depth%2를 통해 홀짝을 구분한다.
*   [0][value]와 [1][value]가 각 각 저장되어 아래의 기저조건이 성립할 수 있다.
*	N_visited[depth(5) / 1] == K_visited[depth(7) / 1] 인 경우 두 depth는 홀수이므로
*	N이 x-1, x+1 을 통해 두번의 depth가 증가하는 동안 같은 자리를 유지할 수 있으므로 만날 수 있다
*   (둘다 짝수도 마찬가지)
* depth%2, flag를 통해 판단 가능
*/

// 방문체크를 하지않을경우 bfs의 시간복잡도는 지수크기가 된다. 3^x
// depth % 2는 다음 depth, (depth+1)%2는 이전 depth이다. / depth의 크기는 flood fill Algorithm과 비슷하다고 한다.

/* flood fill 사용 이유
*   qSize로 depth를 구분하지 않고 q에 값을 넣고 뺼 경우
    dfs형태로 탐색하여 가중치가 가장 낮은 최단거리를 return하지 않고 
    깊이우선탐색으로 만족하는 어떤 값을 return해서 다른값이 나온다.
*/
