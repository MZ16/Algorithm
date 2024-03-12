#include <bits/stdc++.h>
using namespace std;

int ans, N, K, words[51];

int count(int mask) {
	int cnt = 0;
	for (int word : words) {
		if (word && (word & mask) == word)cnt++;
	}
	return cnt;
}

int go(int index, int K, int mask) {
	if (K < 0)return 0;
	if (index == 26)return count(mask);
	int ans = go(index + 1, K - 1, mask | (1 << index));
	if ((index != ('a' - 'a')) && (index != ('t' - 'a')) && (index != ('i' - 'a')) && (index != ('c' - 'a')) && (index != ('n' - 'a'))) {
		ans = max(ans, go(index + 1, K, mask));
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		string word;
		cin >> word;
		for (char c : word) words[i] |= (1 << c - 'a');
	}

	cout << go(0, K, 0);
	return 0;
}