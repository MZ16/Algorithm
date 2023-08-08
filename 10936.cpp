#include <bits/stdc++.h>
using namespace std;

string base64_charSet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"	// 0~25
						"abcdefghijklmnopqrstuvwxyz"	// 26~51
						"0123456789+/";				// 52~61,62,63,padding

string base64_decode(string &input) {
	string decode;
	int i = 0;
	unsigned base64_array3[3], base64_array4[4];
	for (char c : input) {
		//if (c == '=') break;
		if (c >= 'A' && c <= 'Z') { // 0 ~ 25
			base64_array4[i++] = c - 'A';
		}
		else if (c >= 'a' && c <= 'z') { // 26 ~ 51
			base64_array4[i++] = c - 'a' + 26;
		}
		else if (c >= '0' && c <= '9') { // 52 ~ 61
			base64_array4[i++] = c -'0' + 52;
		}
		else if (c == '+') base64_array4[i++] = 62;
		else if (c == '/') base64_array4[i++] = 63;
		
		if (i == 4) {
			/*
				<< 2+ 30 >>4 / 0,1
				0f <<4 + 3c >>2 1,2
				03<<6 + >>2(안해도될듯) / 2,3
			*/
			base64_array3[0] = (base64_array4[0] << 2) + ((base64_array4[1] & 0x30) >> 4);
			base64_array3[1] = ((base64_array4[1] & 0x0f) << 4) + ((base64_array4[2] & 0x3c) >> 2);
			base64_array3[2] = ((base64_array4[2] & 0x03) << 6) + base64_array4[3];
			for (int i = 0; i < 3; i++) {
				decode += base64_array3[i];
			}
			i = 0;
		}
	}
	// 남은값 처리, 최대 6*3 = 18bit, 8bit의 최소값인 24bit로 처리해준다.
	if (i) {
		base64_array3[0] = (base64_array4[0] << 2) + ((base64_array4[1] & 0x30) >> 4);
		base64_array3[1] = ((base64_array4[1] & 0x0f) << 4) + ((base64_array4[2] & 0x3c) >> 2);
		base64_array3[2] = ((base64_array4[2] & 0x03) << 6) + base64_array4[3];
		for (int j = 0; j < i-1; j++) {
			decode += base64_array3[j];
		}
	}
	return decode;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string str;
	cin >> str;
	cout << base64_decode(str)<<"\n";

	return 0;
}