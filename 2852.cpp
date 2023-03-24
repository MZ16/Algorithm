#include <bits/stdc++.h>
using namespace std;

// �ð� ���� ����
// 1. ù��° ��Ұ� �ƴҰ�� - Ascore>Bscore or Ascore<Bscore (prev)
// 2. ���� ���ھ� �� �ð� ����
// 3. ������ ����� ��� - max �ð��� 48�� ó��

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int N;
	int Atime=0, Btime=0;
	int Ascore=0, Bscore=0;
	int saveM, saveS;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int team, min, second;
		scanf("%d %2d:%2d", &team, &min, &second);
		if (i > 0) { // 1.
			if (Ascore > Bscore) Atime += ((min * 60) + second) - ((saveM * 60) + saveS);
			else if(Ascore < Bscore) Btime += ((min * 60) + second) - ((saveM * 60) + saveS);
		}

		// 2.
		if (team == 1)Ascore++;
		else Bscore++;
		saveM = min; saveS = second;
		
		if (i == N - 1) { // 3.
			if (Ascore > Bscore) Atime += ((48 * 60) - (saveM*60+saveS));
			else if (Ascore < Bscore) Btime += ((48 * 60) - (saveM * 60 + saveS));
		}
	}
	printf("%02d:%02d\n", Atime / 60, Atime % 60);
	printf("%02d:%02d\n", Btime / 60, Btime % 60);
	return 0;
} 

// �ش� �������� �¿�Ʋ - cin�� scanf�� ȥ���Ͽ� ���� ����ó���� �ȴ�