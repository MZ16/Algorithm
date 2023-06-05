#include <bits/stdc++.h>
using namespace std;
// LSB - ������ ��Ʈ, MSB - �ֻ��� ��Ʈ
// a<<b = a * (2^b), a>>b = a / ((1/2)^b)
// and - &, or - |, xor - ^, not - ~
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int S = 18; // 10010
    int idx = 1; // 00010
    // idx��° ��Ʈ ����
    S &= ~(1 << idx);
    cout << S << '\n'; // 16

    // idx��° ��Ʈ�� XOR����
    S = 18;
    idx = 1;
    S ^= (1 << idx);
    cout << S << '\n'; // 16

    // ������ �����ִ� ��Ʈ ã�� (�����ִ� LSB)
    // -S = ~S+1
    S = 18;
    idx = (S & -S);
    S ^= (1 << idx);
    cout << idx << '\n'; // 2

    // ũ�Ⱑ n�� ������ ��� ��Ʈ�� �ѱ�
    int n = 4;
    cout << (1 << n) - 1<<"\n"; // 15

    // idx��° ��Ʈ�� �ѱ�
    S = 18;
    idx = 0;
    S |= (1 << idx);
    cout << S << '\n'; // 19

    // idx��° ��Ʈ�� �����ִ��� Ȯ��
    S = 18;
    idx = 1;
    if (S & (1 << idx))cout << idx << "��° ��Ʈ�� �����ֽ��ϴ�.\n";
    else cout << idx << "��° ��Ʈ�� �����ֽ��ϴ�.\n";
    return 0;
    


}