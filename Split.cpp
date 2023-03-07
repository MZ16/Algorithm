#include <bits/stdc++.h>
using namespace std;

// 문자열 split
vector<string> split(string input, string delimiter) {
	vector<string> ret;
	long long pos = 0;
	string token = "";
	while ((pos = input.find(delimiter)) != string::npos) {
		token = input.substr(0, pos);
		ret.push_back(token);
		input.erase(0, pos + delimiter.length());
	}
	ret.push_back(input);
	return ret;
}


vector<string> split_debug(string input, string delimiter) {
	vector<string> ret;
	long long pos = 0;
	string token = "";
	while ((pos = input.find(delimiter)) != string::npos) {
		long long pos = input.find(delimiter);
		cout << "POS : " << pos << "\n";
		if (pos == string::npos)break;

		token = input.substr(0, pos);
		ret.push_back(token);
		input.erase(0, pos + delimiter.length());
	}
	ret.push_back(input);
	return ret;
}


int main() {
	
	string s = "스플 릿 테스트를 위한 아무 말입니 다!";
	string d = " "; // 띄워쓰기 기반 스플릿
	vector<string> a = split(s, d);

	string s2 = "aaaa bbb cccc ee ddddd!";
	vector<string> c = split_debug(s2, d);

	for (auto b : a)cout << b << "\n";

	return 0;
}