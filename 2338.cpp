#include <iostream>
#include <string>
using namespace std;

string removeLeadingZeros(string num);
string add(string a, string b);
string subtract(string a, string b);



int main() {
    string a, b;
    cin >> a >> b;
    cout << add(a, b) << endl;
    return 0;
}


string removeLeadingZeros(string num) {
    int i = 0;
    while (i < num.size() && num[i] == '0') {
        i++;
    }
    if (i == num.size()) {
        return "0";
    }
    return num.substr(i);
}


string add(string a, string b) {
    if (a[0] == '-') {
        return subtract(b, a.substr(1));
    }
    if (b[0] == '-') {
        return subtract(a, b.substr(1));
    }
    string res;
    int carry = 0;  // 올림
    int i = a.length() - 1, j = b.length() - 1;
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
    if (a[0] == '-') {
        return "-" + add(a.substr(1), b);
    }
    if (b[0] == '-') {
        return add(a, b.substr(1));
    }
    if (a < b) {
        return "-" + subtract(b, a);
    }
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

