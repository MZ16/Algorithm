#include <bits/stdc++.h>
using namespace std;

string remove(const string& num);
string add(const string& num1, const string& num2);
string subtract(const string& num1, const string& num2);
string multiply(const string& num1, const string& num2);
pair<string, string> divide(const string& dividend, const string& divisor);

int main() {
    string num1, num2;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    string sum = add(num1, num2);
    cout << "Sum: " << sum << endl;

    string difference = subtract(num1, num2);
    cout << "Difference: " << difference << endl;

    string product = multiply(num1, num2);
    cout << "Product: " << product << endl;

    pair<string, string> result = divide(num1, num2);
    cout << result.first << endl;
    cout << result.second << endl;

    return 0;
}

string remove(const string& num) {
    int len = num.length();
    int Z_Idx = 0;

    while (Z_Idx < len && num[Z_Idx] == '0') {
        Z_Idx++;
    }

    if (Z_Idx == len) {
        return "0";
    }

    return num.substr(Z_Idx);
}

string add(const string& num1, const string& num2) {
    bool negative = false;
    string n1 = num1, n2 = num2;

    if (n1[0] == '-') {
        negative = !negative;
        n1 = n1.substr(1);
    }
    if (n2[0] == '-') {
        negative = !negative;
        n2 = n2.substr(1);
    }

    string result;
    int len1 = n1.length();
    int len2 = n2.length();
    int carry = 0;

    int i = len1 - 1;
    int j = len2 - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = (i >= 0) ? n1[i] - '0' : 0;
        int digit2 = (j >= 0) ? n2[j] - '0' : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result += to_string(sum % 10);

        i--;
        j--;
    }

    reverse(result.begin(), result.end());

    if (negative)
        result = '-' + result;

    return remove(result);
}

string subtract(const string& num1, const string& num2) {
    bool negative = false;
    string n1 = num1, n2 = num2;

    if (n1[0] == '-') {
        negative = !negative;
        n1 = n1.substr(1);
    }
    if (n2[0] == '-') {
        negative = !negative;
        n2 = n2.substr(1);
    }

    string result;
    int len1 = n1.length();
    int len2 = n2.length();
    int borrow = 0;

    int i = len1 - 1;
    int j = len2 - 1;

    while (i >= 0 || j >= 0) {
        int digit1 = (i >= 0) ? n1[i] - '0' : 0;
        int digit2 = (j >= 0) ? n2[j] - '0' : 0;

        int diff = digit1 - digit2 - borrow;

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        }
        else {
            borrow = 0;
        }

        result += to_string(diff);
        i--;
        j--;
    }

    reverse(result.begin(), result.end());

    if (negative && result != "0")
        result = '-' + result;

    return remove(result);
}

string multiply(const string& num1, const string& num2) {
    bool negative = false;
    string n1 = num1, n2 = num2;

    if (n1[0] == '-') {
        negative = !negative;
        n1 = n1.substr(1);
    }
    if (n2[0] == '-') {
        negative = !negative;
        n2 = n2.substr(1);
    }

    int len1 = n1.length();
    int len2 = n2.length();
    vector<int> result(len1 + len2, 0);

    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int digit1 = n1[i] - '0';
            int digit2 = n2[j] - '0';

            int product = digit1 * digit2;

            int pos1 = i + j;
            int pos2 = i + j + 1;

            int sum = product + result[pos2];

            result[pos1] += sum / 10;
            result[pos2] = sum % 10;
        }
    }

    string finalResult;
    for (int digit : result) {
        if (!(finalResult.empty() && digit == 0)) {
            finalResult += to_string(digit);
        }
    }

    if (finalResult.empty()) {
        finalResult = "0";
    }

    if (negative && finalResult != "0")
        finalResult = '-' + finalResult;

    return remove(finalResult);
}

pair<string, string> divide(const string& dividend, const string& divisor) {
    bool negative = false;
    string n1 = dividend, n2 = divisor;

    if (n1[0] == '-') {
        negative = !negative;
        n1 = n1.substr(1);
    }
    if (n2[0] == '-') {
        negative = !negative;
        n2 = n2.substr(1);
    }

    string quotient;
    string remainder;

    int len = n1.length();
    int pos = 0;
    int carry = 0;
    bool isLeadingZero = true;

    while (pos < len) {
        int currDigit = n1[pos] - '0';

        if (carry < int(n2.length())) {
            carry = carry * 10 + currDigit;
        }
        else {
            int q = carry / stoi(n2);
            if (q > 0 || !isLeadingZero) {
                quotient += to_string(q);
                isLeadingZero = false;
            }
            carry = carry % stoi(n2);
            carry = carry * 10 + currDigit;
        }

        pos++;
    }

    int q = carry / stoi(n2);
    if (q > 0 || !isLeadingZero) {
        quotient += to_string(q);
    }
    carry = carry % stoi(n2);
    remainder = to_string(carry);

    if (negative && quotient != "0")
        quotient = '-' + quotient;

    if (negative && remainder != "0")
        remainder = '-' + remainder;

    return make_pair(remove(quotient), remove(remainder));
}