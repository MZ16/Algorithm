#include <bits/stdc++.h>
using namespace std;

string removeLeadingZeros(string num);
string add(string a, string b);
string subtract(string a, string b);


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string a, b;
    cin >> a >> b;
    cout << add(a, b) << "\n";

    return 0;
}


string removeLeadingZeros(string num) { // '0'제거
    int flag = 0;
    if (num[0] == '-')flag = 1, num.erase(num.begin());
    int i = 0;
    while (i < num.size() && num[i] == '0') {
        i++;
    }
    if (i == num.size()) {
        return "0";
    }
    if (flag)return "-" + num.substr(i);
    else return num.substr(i);
}


string add(string a, string b) {
    if (a[0] == '-' && b[0] == '-') {
        a.erase(a.begin()); b.erase(b.begin());
        return "-" + add(a, b);
    }
    else if (a[0] == '-') {
        a.erase(a.begin());
        return subtract(b, a);
    }
    else if (b[0] == '-') {
        b.erase(b.begin());
        return subtract(a, b);
    }
    string res;
    int carry = 0;  // 올림
    int i = a.length() - 1, j = b.length() - 1;
    if (i < j)swap(a, b), swap(i, j);
    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        carry = sum / 10;
        sum %= 10;
        res = to_string(sum) + res;
    }
    return removeLeadingZeros(res);
}


string subtract(string a, string b) {
    if (a[0] == '-' && b[0] == '-') {
        a.erase(a.begin()); b.erase(b.begin());
        return "-" + subtract(b, a);
    }
    else if (a[0] == '-') {
        a.erase(a.begin());
        return "-" + add(a, b);
    }
    else if (b[0] == '-') {
        b.erase(b.begin());
        return add(a, b);
    }

    if (a == b)return "0";

    string res;
    int borrow = 0; // 내림
    int flag = 0;
    int i = a.length() - 1, j = b.length() - 1;
    if (i < j) swap(a, b), swap(i, j), flag = 1;
    else if (i == j && a < b) swap(a, b), swap(i, j), flag = 1; // 길이가 같은경우
    while (i >= 0 || j >= 0) {
        int diff = borrow;
        if (i >= 0) diff += a[i--] - '0';
        if (j >= 0) diff -= b[j--] - '0';
        if (diff < 0 && (i >= 0 || j >= 0)) {
            diff += 10;
            borrow = -1;
        }
        else {
            borrow = 0;
        }
        res = to_string(diff) + res;
    }
    if (flag) res = "-" + res;
    return removeLeadingZeros(res);
}


// 999999999999999999999999999999999999999999999999999999999999 999999999999999999999999999999999999999999999999999999999999
// 123456789123456789123456789 987654321987654321987654321

// -123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789123456789
// -987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321987654321