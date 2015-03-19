#include <bits/stdc++.h>

using namespace std;

map <char, bool> seen;
stringstream ss;
vector < vector <char> > related;
vector < char > elements;
int length;

bool isvalid(char ch)
{
	int len = related[ch].size();
	for(int i = 0; i < len; i++)
	{
		if(seen[related[ch][i]]) return false;
	}
	return true;
}

void generate(string s)
{
	if(s.length() == length)
		cout << s << endl;
	for(int i = 0; i < length; i++)
	{
		if(!seen[elements[i]])
		{
			seen[elements[i]] = true;
			if(isvalid(elements[i])) generate(s + elements[i]);
			seen[elements[i]] = false;
		}
	}
}

int main()
{
	string line;
	bool blank = false;
	while(getline(cin, line))
	{
		ss.clear();
		related.clear();
		related.resize(256);
		seen.clear();
		elements.clear();
		ss.str(line);
		char x, y;
		while(ss >> x)
		{
			elements.push_back(x);
		}
		length = elements.size();
		sort(elements.begin(), elements.end());
		ss.clear();
		getline(cin, line);
		ss.str(line);
		while(ss >> x >> y)
		{
			related[x].push_back(y);
		}
		if(blank) puts("");
		blank = true;
		generate("");

	}
	return 0;
}

