#include<iostream>
#include<algorithm>
#include<list>
#pragma warning(disable:4996)
using namespace std;

list<char>lt;
string str;
int N;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> str;
	cin >> N;
	for (int i = 0; i < str.size(); i++) {
		lt.push_back(str[i]);
	}
	list<char>::iterator cusor = lt.end();
	while (N--) {
		char ch, add;
		cin >> ch;
		if (ch == 'L') {
			if (cusor == lt.begin())
				continue;
			else cusor--;
		}
		else if (ch == 'D') {
			if (cusor == lt.end())
				continue;
			else cusor++;
		}
		else if (ch == 'B') {
			if (cusor == lt.begin())
				continue;
			else
				cusor = lt.erase(--cusor);
		}
		else if (ch == 'P') {
			cin >> add;
			lt.insert(cusor, add);
		}
	}
	for (auto i = lt.begin(); i != lt.end(); i++)
		cout << *i;
}
