#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<pair<int, int>> stk;

void init() {	
		ios_base::sync_with_stdio(0);
		cin.tie(0);	
}


int main() {
	init();
	int TC,val;
	scanf("%d", &TC);
	for (int i = 1; i <= TC; i++) {
		scanf("%d", &val);
		while (!stk.empty()) {
			if (stk.back().second > val) {
				printf("%d ", stk.back().first);
				break;
			}
			stk.pop_back();
		}

		if (stk.empty())printf("0 ");
		stk.push_back(make_pair(i, val));
	}
	return 0;
}





/*모르겠다 STL사용..*/
/* STL stack or vector 사용
* pair 사용시 push는 make_pair()로 값을 넣어줌

*/