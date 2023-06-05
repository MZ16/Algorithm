#include <bits/stdc++.h>
using namespace std;

// 특정 조합이 아닌 모든 조합의 경우의 수
// 기존의 combi함수처럼 정해진 nCr이 아닌 nC1 ~ nCn까지
const int N = 4;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string arr[N] = { "사과","딸기","포도","배" };
    for (int i = 0; i < (1 << N); i++) {
        string ret = ""; // 경우의 수 저장
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) // 0~15까지 경우의 수 check
                ret += arr[j] + " ";
        }
        cout << ret << "\n";
    }

    return 0;
}
/*
0000
0001
0010
0011
0100
0101
0110
0111
1000 등 총 16가지의 경우의 수
*/