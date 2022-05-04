#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	string N;
	cin >> N;
	for (int i = 0; i < N.size(); i++) {
		printf("%d ", N[i]-'A'+1);
	}
	
}