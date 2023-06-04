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
        if (visited[depth % 2][K]) { // ¦��, Ȧ���� ��ġ�ϴ� depth���� �湮�� ���� ������ ���� �� ����
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
* N(����)�̴� 500,000�� �Ѿ �� ���� ������ �Ѿ �� ���� / �� ������ �Ѿ�� -1
* K(����)�� �� depth���� depth��ŭ �̵���
* N�� K�� ���� �湮�� ��� N�� K�� �� depth�� �Ѵ� Ȧ�� or ¦���� ��� ���� ���� �� ���� / N�� ���� �湮�� ��츸!
*   Ȧ¦ ������ ���� [2][MAX]ũ���� �迭�� ����� depth%2�� ���� Ȧ¦�� �����Ѵ�.
*   [0][value]�� [1][value]�� �� �� ����Ǿ� �Ʒ��� ���������� ������ �� �ִ�.
*	N_visited[depth(5) / 1] == K_visited[depth(7) / 1] �� ��� �� depth�� Ȧ���̹Ƿ�
*	N�� x-1, x+1 �� ���� �ι��� depth�� �����ϴ� ���� ���� �ڸ��� ������ �� �����Ƿ� ���� �� �ִ�
*   (�Ѵ� ¦���� ��������)
* depth%2, flag�� ���� �Ǵ� ����
*/

// �湮üũ�� ����������� bfs�� �ð����⵵�� ����ũ�Ⱑ �ȴ�. 3^x
// depth % 2�� ���� depth, (depth+1)%2�� ���� depth�̴�. / depth�� ũ��� flood fill Algorithm�� ����ϴٰ� �Ѵ�.

/* flood fill ��� ����
*   qSize�� depth�� �������� �ʰ� q�� ���� �ְ� �E ���
    dfs���·� Ž���Ͽ� ����ġ�� ���� ���� �ִܰŸ��� return���� �ʰ� 
    ���̿켱Ž������ �����ϴ� � ���� return�ؼ� �ٸ����� ���´�.
*/
