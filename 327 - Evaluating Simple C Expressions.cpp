#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

struct object
{
	char ch;
	int value;
	bool before;
	char op;
	
	object(char c, int v, bool b, char o)
	{
		ch = c;
		value = v;
		before = b;
		op = o;
	}
};

bool ifswap(object a, object b)
{
	return a.ch < b.ch;
}

char str[10010];

int space_clear(char *s)
{
	int len = strlen(str), k = -1;
	for(int i = 0; i < len; i++)
	{
		if(str[i] == ' ') continue;
		s[++k] = str[i];
	}
	return k;
}

int main()
{
	while(gets(str))
	{
		char s[10010];
		int len = space_clear(s);
		vector<object> variables;
		vector<char> operators;
		s[len+1] = '\0';
		puts(s);
		
		for(int i = 0; i <= len; i++)
		{
			if(s[i] <= 'z' && s[i] >= 'a')
			{
				if(s[i+1] == '+' && s[i+2] == '+')
				{
					variables.push_back(object(s[i], s[i]-95, false, '?'));
					i+=2;
				}

				else if(s[i+1] == '-' && s[i+2] == '-')
				{
					variables.push_back(object(s[i], s[i]-97, false, '?'));
					i+=2;
				}

				else variables.push_back(object(s[i], s[i]-96, false, '?'));
				
	
			}
			else 
			{
				if(s[i+1] == s[i])
				{
					if(s[i] == '+') variables.push_back(object(s[i+2], s[i+2]-95, true, '+'));
					else variables.push_back(object(s[i+2], s[i+2]-97, true, '-'));
					i+=2;

				}
				else operators.push_back(s[i]);
			}
			
		} 

		int ret = variables[0].value;
		for(int i = 1; i < variables.size(); i++)
		{
			int v = variables[i].value;
			if(variables[i].before )
			{
				if(variables[i].op == '+') v--;
				else if(variables[i].op == '-') v++;
			}
			if(operators[i-1] == '+') ret += v;
			else ret -= v;
		}

		printf("%d\n", ret);

		sort(variables.begin(), variables.end(), ifswap);
		for(int i = 0; i < variables.size(); i++)
		{
			printf("%c = %d\n", variables[i].ch, variables[i].value);
		}
	}
	return 0;
}