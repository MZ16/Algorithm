#include <bits/stdc++.h>
using namespace std;
// LSB - 최하위 비트, MSB - 최상위 비트
// a<<b = a * (2^b), a>>b = a / ((1/2)^b)
// and - &, or - |, xor - ^, not - ~
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int S = 18; // 10010
    int idx = 1; // 00010
    // idx번째 비트 끄기
    S &= ~(1 << idx);
    cout << S << '\n'; // 16

    // idx번째 비트에 XOR연산
    S = 18;
    idx = 1;
    S ^= (1 << idx);
    cout << S << '\n'; // 16

    // 최하위 켜져있는 비트 찾기 (켜져있는 LSB)
    // -S = ~S+1
    S = 18;
    idx = (S & -S);
    S ^= (1 << idx);
    cout << idx << '\n'; // 2

    // 크기가 n인 집합의 모든 비트를 켜기
    int n = 4;
    cout << (1 << n) - 1<<"\n"; // 15

    // idx번째 비트를 켜기
    S = 18;
    idx = 0;
    S |= (1 << idx);
    cout << S << '\n'; // 19

    // idx번째 비트가 켜져있는지 확인
    S = 18;
    idx = 1;
    if (S & (1 << idx))cout << idx << "번째 비트가 켜져있습니다.\n";
    else cout << idx << "번째 비트가 꺼져있습니다.\n";
    return 0;
    


}