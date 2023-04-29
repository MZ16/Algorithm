#include <bits/stdc++.h>
using namespace std;

string removeLeadingZeros(string num);
string subtract(string a, string b);
void divide(string a, string b);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string N, M;
	cin >> N >> M;
	divide(N, M);
	
	return 0;
}


string removeLeadingZeros(string num) {
	int flag = 0, i = 0;
	if (num[0] == '-')flag = 1, num.erase(num.begin());
	while (i < num.size() && num[i] == '0') {
		i++;
	}
	if (num.size() == i) return "0";
	if (flag) return '-' + num.substr(i);
	else return num.substr(i);
}

string subtract(string a, string b) {
	if (a == b)return "0";
	string ans = "";
	int i = a.length() - 1, j = b.length() - 1;
	int borrow = 0;
	while (i >= 0 || j >= 0) {
		int diff = borrow;
		if (i >= 0) diff += a[i--] - '0';
		if (j >= 0) diff -= b[j--] - '0';

		if (diff < 0 && (i>=0 || j>=0)) {
			diff += 10;
			borrow = -1;
		}
		else {
			borrow = 0;
		}
		ans = to_string(diff) + ans;
	}
	return ans;
}
void divide(string a, string b) {
	bool share_flag = false; // �� ���� check 
	bool remainder_flag = false; // ������ ���� check
	
	if (a[0] == '-' && b[0] == '-') {
		remainder_flag = true;
		a.erase(a.begin()); b.erase(b.begin());
	}
	else if (a[0] == '-') {
		share_flag = true; remainder_flag = true;
		a.erase(a.begin());
	}
	else if(b[0]=='-') {
		share_flag = true;
		b.erase(b.begin());
	}
	a = "0" + a; b = "0" + b; // �ڸ� �� ���߱�
	string ans = "";
	string ret = "";

	int len = a.size() - b.size();
	for (int i = 0; i <= len; i++) {
		int share = 0;
		while (1) {
			bool flag = true; // ���� ���� check
			for (int j = 0; j < b.size(); j++) { // �ڸ����� �������� ������ ����������� false
				//if (a.size() < b.size()) { flag = false; break; } // overflow����
				if (a[i + j] > b[j])break;
				if (a[i + j] < b[j]) { flag = false; break; }
			}
			if (flag) {
				ret = subtract(a.substr(i,b.size()), b);
				a.replace(i, b.size(), ret);
				share++;
			}
			else {
				ans += share+'0';
				break;
			}
		}
	}
	// �������� a�� ����ϸ��
	if (share_flag) cout << '-' << removeLeadingZeros(ans) << "\n";
	else cout << removeLeadingZeros(ans) << "\n";
	if (remainder_flag) cout << '-' << removeLeadingZeros(a) << "\n";
	else cout << removeLeadingZeros(a) << "\n";
	
	return;
}