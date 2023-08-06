#include <bits/stdc++.h>
using namespace std;

string base64_charSet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
						"abcdefghijklmnopqrstuvwxyz"
						"0123456789+/=";

string base64_encode(string& input) {
	string encode;
	int i=0, j=0;
	unsigned base64_array3[3], base64_array4[4];
	// 3byte, 8bit -> 6bit
	for (char c : input) {
		base64_array3[i++] = c;
		if (i == 3) {
			base64_array4[0] = (base64_array3[0] & 0xfc) >> 2; // [0] 상위 6bit
			base64_array4[1] = ((base64_array3[0] & 0x03) << 4) + ((base64_array3[1] & 0xf0) >> 4); // [0] 하위 2bit + [1] 상위 4bit
			base64_array4[2] = ((base64_array3[1] & 0x0f) << 2) + ((base64_array3[2] & 0xc0) >> 6); // [1] 하위 4bit + [2] 상위 2bit
			base64_array4[3] = (base64_array3[2] & 0x3f); // [2] 하위 6bit

			for (char ch : base64_array4)
				encode += base64_charSet[ch];
			i = 0;
		}		
	}

	// 문자열 길이가 3으로 나누어 떨어지지 않을 경우, 최대 16bit
	if (i > 0) {
		for (int j = i; j < 3; j++)
			base64_array3[j] = '\0'; // 남는 데이터 '\0'으로 초기화

		base64_array4[0] = (base64_array3[0] & 0xfc) >> 2; // [0] 상위 6bit
		base64_array4[1] = ((base64_array3[0] & 0x03) << 4) + ((base64_array3[1] & 0xf0) >> 4); // [0] 하위 2bit + [1] 상위 4bit
		base64_array4[2] = ((base64_array3[1] & 0x0f) << 2) + ((base64_array3[2] &  0xc0) >> 6); // [1] 하위 4bit + [2] 상위 2bit
		
		// 3의 배수가 아니기 때문에 i값에 맞춰서 encode에 값을 추가한다.
		for (int j = 0; j < i + 1; j++)
			encode += base64_charSet[base64_array4[j]];
		
		// 빈 공간 패딩 추가
		while (i++ < 3)
			encode += '=';
	}

	return encode;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string str;
	cin >> str;
	cout<<base64_encode(str);

	return 0;
}