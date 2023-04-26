#include <bits/stdc++.h>
using namespace std;

string removeLeadingZeros(string num);
string add(string a, string b);
string subtract(string a, string b);
string multiply(string a, string b);
//string divide(string a, string b);


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string a, b;
    cin >> a >> b;
    cout << add(a, b) << "\n";
    cout << subtract(a, b) << "\n";
    cout << multiply(a, b) << "\n";
    //cout << divide(a, b) << "\n";
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
        return subtract(b, a);
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

string multiply(string a, string b) {
    int j = a.length() - 1, i = b.length() - 1, flag = 0;

    if ((i == 1 && b == "0") || (j == 1 && a == "0"))return "0";

    if ((a[0] == '-') && (b[0] == '-') || (a[0] != '-') && (b[0] != '-'))flag = 1;
    if (a[0] == '-')a.erase(a.begin());
    if (b[0] == '-')b.erase(b.begin());

    string res = "0";
    for (int i = b.length() - 1; i >= 0; i--) {
        string temp;
        int carry = 0;
        for (int j = a.length() - 1; j >= 0; j--) {
            int product = (b[i] - '0') * (a[j] - '0') + carry;
            carry = product / 10;
            product %= 10;
            temp = to_string(product) + temp;
        }
        if (carry > 0) {
            temp = to_string(carry) + temp;
        }
        for (int j = i; j < b.length() - 1; j++) { // 자릿수 맞추기
            temp += '0';
        }
        res = add(res, temp);
    }
    if (!flag) {
        res = "-" + res;
    }
    return removeLeadingZeros(res);
}