#include <bits/stdc++.h>
using namespace std;
/* Ư�� index�� ������ ��� ����� ��
*/
const int N = 4;
string arr[N] = { "���","����","����","��" };
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
    int idx; // ������ index
    cin >> idx;
    for (int i = 1; i < N; i++) { // i=1�� ���� : 0�� or���� �غ��� ���Խ�ų idx���̴�.
        go(idx | (1 << i)); // �Ʒ� �ּ�
    }
    

    return 0;
}
/*
input = 3 / ���, ����
input   0011    /   output
OR      0001    /   0011    /   3   /   ���, ����
OR      0010    /   0011    /   3   /   ���, ����
OR      0100    /   0111    /   7   /   ���, ����, ����
OR      1000    /   1011    /   11  /   ���, ����, ��
*/