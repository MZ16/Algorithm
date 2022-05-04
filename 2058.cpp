#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	string N;
	int sum = 0;
	cin >> N;
	for (int i = 0; i < N.size(); i++) {
		sum += (int)N[i]-'0';
	}
	printf("%d", sum);
}