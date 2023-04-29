#include <iostream>
#include <string>
using namespace std;

int compare(string a, string b);
string divide(string a, string b);
string subtract(string a, string b);
string removeLeadingZeros(string a);
string mod(string a, string b);


int main() {
    string a, b;
    cin >> a >> b;
    cout << divide(a, b) << "\n";
    cout << mod(a, b);
    
    return 0;
}

string divide(string a, string b) {
    bool neg = false;
    if (a[0] == '-') {
        neg ^= true;
        a = a.substr(1);
    }
    if (b[0] == '-') {
        neg ^= true;
        b = b.substr(1);
    }
    string res;
    string cur;
    int pos = 0;
    while (pos < a.length()) {
        cur += a[pos++];
        int cnt = 0;
        while (compare(cur, b) >= 0) {
            cur = subtract(cur, b);
            cnt++;
        }
        res += to_string(cnt);
    }
    if (res.empty()) res = "0";
    if (neg && res != "0") res = "-" + res;
    return res;
}

int compare(string a, string b) {
    if (a.length() != b.length()) return a.length() < b.length() ? -1 : 1;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) return a[i] < b[i] ? -1 : 1;
    }
    return 0;
}

string subtract(string a, string b) {
    string res;
    int borrow = 0;
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

string removeLeadingZeros(string a) {
    int pos = 0;
    while (pos < a.length() && a[pos] == '0') pos++;
    if (pos == a.length()) a = "0";
    else a = a.substr(pos);
    return a;
}
string mod(string a, string b) {
    bool negA = false, negB = false;
    if (a[0] == '-') {
        negA = true;
        a = a.substr(1);
    }
    if (b[0] == '-') {
        negB = true;
        b = b.substr(1);
    }

    // b == 0인 경우 예외 처리
    if (b == "0") {
        return "ERROR: Division by zero";
    }

    // a < b인 경우 a가 나머지가 됨
    if (abs(a) < abs(b)) {
        return a;
    }

    // 몫을 구함
    string quotient = divide(a, b);

    // 원래의 두 수를 이용하여 나머지를 구함
    string remainder = subtract(a, multiply(quotient, b));

    if (negA) {
        remainder = "-" + remainder;
    }

    return remainder;
}
