#include <string>
#include <queue>
#include <iostream>
#include <cstdio>

using namespace std;

struct tile
{
	int x;
	int y;
	int d;
	int t;

	tile(int _x, int _y, int _d, int _t) {
		x = _x;
		y = _y;
		d = _d;
		t = _t;
	}
};

bool seen[51][51][4];
int M, N, tx, ty;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
bool obstacle[51][51];

bool is_valid(int x, int y)
{
	if(x <= 0 || y <= 0 || x >= M || y >= N) return false;
	if(obstacle[x][y] || obstacle[x-1][y] || obstacle[x][y-1] || obstacle[x-1][y-1]) return false;
	return true; 
}

int compute_time(int x, int y, int d)
{
	queue<tile>Q;
	if(is_valid(x, y)){
		seen[x][y][d] = true;
		Q.push(tile(x, y, d, 0));
	}

	while(!Q.empty()) {
		tile u = Q.front();
		Q.pop();

		if(u.x == tx && u.y == ty) return u.t;

		if(!seen[u.x][u.y][(u.d+1)%4]) {
			seen[u.x][u.y][(u.d+1)%4] = true;
			Q.push(tile(u.x, u.y, (u.d+1)%4, u.t+1));
		}

		if(!seen[u.x][u.y][(u.d+3)%4]) {
			seen[u.x][u.y][(u.d+3)%4] = true;
			Q.push(tile(u.x, u.y, (u.d+3)%4, u.t+1));
		}

		for(int i=1; i<4; i++) {
			int xx = u.x + dx[u.d]*i;
			int yy = u.y + dy[u.d]*i;

			if(is_valid(xx, yy)) {
				if(seen[xx][yy][u.d]) continue;
				seen[xx][yy][u.d] = true;
				Q.push(tile(xx, yy, u.d, u.t+1));
			}
			else break;
		}
	}
	return -1;

}

int main()
{
	int a, x, y, dir;
	char s[6];
	while(scanf("%d %d", &M, &N) == 2) {
		if(N == 0 || M == 0) break;
		for(int i = 0; i<M; i++)
			for(int j = 0; j<N; j++)
				fill(seen[i][j], seen[i][j]+4, false);
		for(int i=0; i<M; i++){
			for(int j=0; j<N; j++){
				scanf("%d",&a);
				obstacle[i][j]=a;
			}
		}

		scanf("%d %d %d %d %s", &x, &y, &tx, &ty, s);
		if(s[0]=='n') dir=0;
		else if(s[0]=='e') dir=1;
		else if(s[0]=='s') dir=2;
		else dir=3;

		printf("%d\n", compute_time(x, y, dir));
	}
	return 0;
}