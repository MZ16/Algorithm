#include <bits/stdc++.h>
using namespace std;

// 문자열셋
string base64_charSet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz"
"0123456789+/";

string base64_encode(const char* data, unsigned int length) {
    string encode_string;
    unsigned int char_array3[3];
    unsigned int char_array4[4];
    int i = 0, j = 0;

    while (length--) {
        char_array3[i++] = *(data++);
        if (i == 3) { // 3byte씩 처리
            char_array4[0] = (char_array3[0] & 0xfc) >> 2;
            char_array4[1] = ((char_array3[0] & 0x03) << 4) + ((char_array3[1] & 0xf0) >> 4);
            char_array4[2] = ((char_array3[1] & 0x0f) << 2) + ((char_array3[2] & 0xc0) >> 6);
            char_array4[3] = char_array3[2] & 0x3f;

            for (i = 0; i < 4; i++)
                encode_string += base64_charSet[char_array4[i]];
            i = 0;
        }
    }

    if (i) { // 3byte이하의 나머지 문자열 처리
        for (j = i; j < 3; j++) // 패딩추가
            char_array3[j] = '\0';

        char_array4[0] = (char_array3[0] & 0xfc) >> 2;
        char_array4[1] = ((char_array3[0] & 0x03) << 4) + ((char_array3[1] & 0xf0) >> 4);
        char_array4[2] = ((char_array3[1] & 0x0f) << 2) + ((char_array3[2] & 0xc0) >> 6);
        char_array4[3] = char_array3[2] & 0x3f;

        for (j = 0; j < i + 1; j++)
            encode_string += base64_charSet[char_array4[j]];

        while ((i++ < 3))
            encode_string += '=';
    }

    return encode_string;
}

string base64_decode(const char* data, unsigned int length) {
    string decode_string;
    unsigned int char_array4[4];
    unsigned int char_array3[3];
    int i = 0, j = 0;

    while (length-- && data[j] != '=') { // 패딩 문자 제외

        if (data[j] >= 'A' && data[j] <= 'Z')
            char_array4[i++] = data[j++] - 'A';
        else if (data[j] >= 'a' && data[j] <= 'z')
            char_array4[i++] = data[j++] - 'a' + 26;
        else if (data[j] >= '0' && data[j] <= '9')
            char_array4[i++] = data[j++] - '0' + 52;
        else if (data[j] == '+')
            char_array4[i++] = 62;
        else if (data[j] == '/')
            char_array4[i++] = 63;

        if (i == 4) {
            char_array3[0] = (char_array4[0] << 2) + ((char_array4[1] & 0x30) >> 4);
            char_array3[1] = ((char_array4[1] & 0xf) << 4) + ((char_array4[2] & 0x3c) >> 2);
            char_array3[2] = ((char_array4[2] & 0x3) << 6) + char_array4[3];

            for (i = 0; i < 3; i++) {
                decode_string += char_array3[i];
            }
            i = 0;
        }
    }

    if (i) {
        char_array3[0] = (char_array4[0] << 2) + ((char_array4[1] & 0x30) >> 4);
        char_array3[1] = ((char_array4[1] & 0xf) << 4) + ((char_array4[2] & 0x3c) >> 2);
        char_array3[2] = ((char_array4[2] & 0x3) << 6) + char_array4[3];

        for (j = 0; j < i - 1; j++) {
            decode_string += char_array3[j];
        }
    }


    return decode_string;
}

// TmF2aXM= TmF2a2luZ2RvbQ==

int main() {
    while (1) {
        char mode; string str;
        cout << "> Input mode (E : Encode , D : Decode , Q : Quit)" << "\n";
        cin >> mode; if (mode == 'Q')exit(0);
        cin >> str;
        const char* data = str.c_str();
        unsigned int length = str.length();
        if (mode == 'E') {
            string encoded_str = base64_encode(data, length);
            cout << "> Result : " << encoded_str << "\n";
        }
        else if (mode == 'D') {
            string decoded_str = base64_decode(data, length);
            cout << "> Result : " << decoded_str << "\n";
        }
        cout << "\n\n";
    }

    return 0;
}


// 0xfc - 8bit 중 상위 6비트 추출 (11111100)
// 0x03 - 8bit 중 하위 2비트 추출 (00000011)
// 0xf0 - 8bit 중 상위 4비트 추출 (11110000)
// 0x0f - 8bit 중 하위 4비트 추출 (00001111)
// 0xc0 - 8bit 중 상위 2비트 추출 (11000000)
// 0x3f - 8bit 중 하위 6비트 추출 (00111111)
