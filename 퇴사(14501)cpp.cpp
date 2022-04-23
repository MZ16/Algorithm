#include <stdio.h>

int max = 0,n;
int a[15], b[15];
void solve(int idx, int pf) {
	if (idx > n) return;
	if (pf > max) max = pf;
	if (idx == n) return;
	solve(idx + a[idx], pf + b[idx]);
	solve(idx + 1, pf);

}

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i], &b[i]);
	}
	int idx = 0, pf = 0;
	solve(0, 0);
	printf("%d", max);
	return 0;
}