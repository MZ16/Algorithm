#include <bits/stdc++.h>
using namespace std;

// Ư�� ������ �ƴ� ��� ������ ����� ��
// ������ combi�Լ�ó�� ������ nCr�� �ƴ� nC1 ~ nCn����
const int N = 4;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string arr[N] = { "���","����","����","��" };
    for (int i = 0; i < (1 << N); i++) {
        string ret = ""; // ����� �� ����
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) // 0~15���� ����� �� check
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
1000 �� �� 16������ ����� ��
*/