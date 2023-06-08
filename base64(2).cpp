#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
string base64_encode(const string& input) {
    const string base64_chars =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";

    string encoded_str;
    unsigned int val = 0;
    int bits = -6;

    for (const unsigned char& c : input) {
        val = (val << 8) + c;
        bits += 8;

        while (bits >= 0) {
            encoded_str.push_back(base64_chars[(val >> bits) & 0x3F]);
            bits -= 6;
        }
    }

    if (bits > -6) {
        encoded_str.push_back(base64_chars[((val << 8) >> (bits + 8)) & 0x3F]);
    }

    while (encoded_str.size() % 4 != 0) {
        encoded_str.push_back('=');
    }

    return encoded_str;
}

string base64_decode(const string& input) {
    const string base64_chars =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";

    unordered_map<char, int> base64_rev_chars;
    for (int i = 0; i < base64_chars.size(); ++i) {
        base64_rev_chars[base64_chars[i]] = i;
    }

    string decoded_str;
    unsigned int val = 0;
    int bits = -8;

    for (const unsigned char& c : input) {
        if (base64_rev_chars.find(c) == base64_rev_chars.end()) {
            break;
        }

        val = (val << 6) + base64_rev_chars[c];
        bits += 6;

        if (bits >= 0) {
            decoded_str.push_back((val >> bits) & 0xFF);
            bits -= 8;
        }
    }

    return decoded_str;
}

int main() {
    while (true) {
        char mode;
        string str;
        cout << "> Input mode (E: Encode, D: Decode, Q: Quit)\n";
        cin >> mode;
        if (mode == 'Q') {
            break;
        }

        cin >> str;

        if (mode == 'E') {
            string encoded_str = base64_encode(str);
            cout << "> Result: " << encoded_str << "\n";
        }
        else if (mode == 'D') {
            string decoded_str = base64_decode(str);
            cout << "> Result: " << decoded_str << "\n";
        }

        cout << "\n";
    }

    return 0;
}
// TmF2aXM= TmF2a2luZ2RvbQ==
