#include <bits/stdc++.h>
using namespace std;
int obstacle[32][32];
int moves[32][32][32];
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int main() {
	int cases;
	int N, M, K;
	scanf("%d", &cases);
	while(cases--) {
		scanf("%d %d %d", &N, &M, &K);
		for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++)
				scanf("%d", &obstacle[i][j]);
		memset(moves, 63, sizeof moves);
		moves[0][0][0] = 0;
		queue<int> X, Y, S;
		int x, y, s, tx, ty, ts;
		X.push(0), Y.push(0), S.push(0);
		while(!X.empty()) {
			x = X.front(), X.pop();
			y = Y.front(), Y.pop();
			s = S.front(), S.pop();
			for(int i = 0; i < 4; i++) {
				tx = x + dx[i], ty = y + dy[i];
				if(tx < 0 || ty < 0 || tx >= N || ty >= M) continue;
				if(obstacle[tx][ty]) ts = s + 1;
				else ts = 0;

				if(ts > K) continue;
				if(moves[tx][ty][ts] > moves[x][y][s] + 1) {
					moves[tx][ty][ts] = moves[x][y][s] + 1;
					X.push(tx), Y.push(ty), S.push(ts);
				}
			}
		}

		int ret = 0x3f3f3f3f;
		for(int i = 0; i <= K; i++)
			ret = min(ret, moves[N-1][M-1][i]);
		printf("%d\n", ret == 0x3f3f3f3f ? -1 : ret);
	}
	return 0;
}