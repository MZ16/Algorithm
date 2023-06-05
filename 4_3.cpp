#include <bits/stdc++.h>
using namespace std;
/* 특정 index를 포함한 모든 경우의 수
*/
const int N = 4;
string arr[N] = { "사과","딸기","포도","배" };
void go(int num) {
    string ret = "";
    for (int i = 0; i < N; i++) {
        if (num & (1 << i))ret += arr[i]+" ";
    }
    cout << ret << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int idx; // 포함할 index
    cin >> idx;
    for (int i = 1; i < N; i++) { // i=1인 이유 : 0은 or연산 해봐야 포함시킬 idx값이다.
        go(idx | (1 << i)); // 아래 주석
    }
    

    return 0;
}
/*
input = 3 / 사과, 딸기
input   0011    /   output
OR      0001    /   0011    /   3   /   사과, 딸기
OR      0010    /   0011    /   3   /   사과, 딸기
OR      0100    /   0111    /   7   /   사과, 딸기, 포도
OR      1000    /   1011    /   11  /   사과, 딸기, 배
*/