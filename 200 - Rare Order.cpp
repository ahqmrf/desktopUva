#include <bits/stdc++.h>

using namespace std;

bool seen[26];
vector <int> adj[26];
vector <int> sequence;
bool exists[26];

void dfs(int u)
{
	seen[u] = true;
	int len = adj[u].size();
	for(int i = 0; i < len; i++)
	{
		if(!seen[adj[u][i]])
		{
			seen[adj[u][i]] = true;
			dfs(adj[u][i]);
		}
	}
	sequence.push_back(u);
}

int main()
{
	string s;
	vector <string> strings;
	while(cin >> s)
	{
		if(s == "#") break;
		strings.push_back(s);
	}

	int length = strings.size();
	for(int i = 0; i < length-1; i++)
	{
		int len = min(strings[i].length(), strings[i+1].length());
		for(int j = 0; j < len; j++)
		{
			if(strings[i][j] != strings[i+1][j])
			{
				exists[strings[i][j]-65] = true;
				exists[strings[i+1][j]-65] = true;
				adj[strings[i][j]-65].push_back(strings[i+1][j]-65);
				break;
			}
		}
	}
	for(int i = 0; i < 26; i++)
	{
		if(!seen[i] && exists[i])
		{
			dfs(i);
		}
	}
	length = sequence.size();
	for(int i = length-1; i >= 0; i--)
		printf("%c", sequence[i]+'A');
	puts("");
	return 0;
}