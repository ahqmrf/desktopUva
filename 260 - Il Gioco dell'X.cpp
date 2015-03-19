#include <bits/stdc++.h>

using namespace std;

struct cell
{
	int x;
	int y;
	char c;
	cell(int _x, int _y, char _c)
	{
		x = _x;
		y = _y;
		c = _c;
	}
};

bool visited[201][201];
int N;
const int dx[] = {-1, 0, 1, -1, 0, 1};
const int dy[] = {-1, -1, 0, 0, 1, 1};
char board[201][201];

int main()
{
	int caseno = 1;
	while(scanf("%d", &N) == 1 && N)
	{
		for(int i = 0; i < N; i++)
			scanf("%s", board[i]);
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				visited[i][j] = false;
		queue <cell> S;
		for(int i = 0; i < N; i++)
		{
			if(board[0][i] == 'b')
			{
				S.push(cell(0, i, 'b'));
				visited[0][i] = true;
			}
		}

		for(int i = 0; i < N; i++)
		{
			if(board[i][0] == 'w')
			{
				S.push(cell(i, 0, 'w'));
				visited[i][0] = true;
			}
		}

		while(!S.empty())
		{
			cell u = S.front();
			S.pop();

			for(int i = 0; i < 6; i++)
			{
				int x = u.x + dx[i], y = u.y + dy[i];
				if(x < 0 || x >= N || y < 0 || y >= N) continue;
				if(board[x][y] == u.c && !visited[x][y])
				{
					S.push(cell(x, y, u.c));
					visited[x][y] = true;
				}
			}
		}
		bool blackwon = false;
		for(int i = 0; i < N; i++)
			if(board[N-1][i] == 'b' && visited[N-1][i])
			{
				blackwon = true;
				break;
			}
		printf("%d ", caseno++);
		blackwon? puts("B") : puts("W");
	}

	return 0;
}