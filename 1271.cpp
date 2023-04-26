#include <bits/stdc++.h>
using namespace std;

string removeLeadingZeros(string num);
string subtract(string a, string b);
string divide(string a, string b);


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string a, b;
    cin >> a >> b;
    cout << add(a, b) << "\n";
    cout << subtract(a, b) << "\n";
    cout << multiply(a, b) << "\n";
    return 0;
}


string removeLeadingZeros(string num) { // '0'제거
    int i = 0;
    while (i < num.size() && num[i] == '0') {
        i++;
    }
    if (i == num.size()) {
        return "0";
    }
    return num.substr(i);
}

string subtract(string a, string b) {
    string res;
    int borrow = 0; // 내림
    int i = a.length() - 1, j = b.length() - 1;
    while (i >= 0 || j >= 0) {
        int diff = borrow;
        if (i >= 0) diff += a[i--] - '0';
        if (j >= 0) diff -= b[j--] - '0';
        if (diff < 0) {
            diff += 10;
            borrow = -1;
        }
        else {
            borrow = 0;
        }
        res = to_string(diff) + res;
    }
    return removeLeadingZeros(res);
}

string divide(string a, string b) {

}

