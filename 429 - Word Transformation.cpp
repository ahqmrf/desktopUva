#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <cstring>
#define li long int

using namespace std;

string word_list[201];
map <string,li> word_indexes;
vector <int> adjacency_list[201];

void reset_vector()
{
    li i;

    for(i=0;i<201;i++)
    {
        adjacency_list[i].clear();
    }
}

void bfs(li source, li destination, string from, string to)
{
    li visited[201],steps[201],u,v,i;
    queue <int> q;

    visited[source]++;
    steps[source]=0;
    q.push(source);
    memset(visited,0,sizeof(visited));
    memset(steps,0,sizeof(steps));

    while(q.size())
    {
        u=q.front();
        q.pop();
        if(u==destination) break;
        for(i=0;i<adjacency_list[u].size();i++)
        {
            if(!visited[adjacency_list[u][i]])
            {
                q.push(adjacency_list[u][i]);
                visited[adjacency_list[u][i]]++;
                steps[adjacency_list[u][i]]=steps[u]+1;
            }
        }
    }
    cout<<from<<" "<<to<<" "<<steps[u]<<"\n";
}

int main()
{
    li n_case,index,i,j,k,count_mismatch,source,destination,c_case;
    string word,command,from,to;
    stringstream from_to;
    cin>>n_case;
    for(c_case=1;c_case<=n_case;c_case++)
    {
        index=0;
        while(1)
        {
            cin>>word;
            if(word=="*") break;
            word_list[index]=word;
            word_indexes[word]=index;
            index++;
        }
        if(c_case>1) cout<<"\n";
        reset_vector();
        for(i=0;i<index;i++)
        {
            for(j=0; j!=i && j<index ;j++)
            {
                if(word_list[i].size()==word_list[j].size())
                {
                    count_mismatch=0;
                    for(k=0;k<word_list[i].size();k++)
                    {
                        if(word_list[i][k]!=word_list[j][k])
                        {
                            count_mismatch++;
                        }
                    }
                    if(count_mismatch==1)
                    {
                        adjacency_list[i].push_back(j);
                        adjacency_list[j].push_back(i);
                    }
                }
            }
        }
        getline(cin,command);
        while(getline(cin,command))
        {
            if(command.size()==0) break;
            from_to.clear();
            from_to<<command;
            from_to>>from;
            from_to>>to;
            source=word_indexes[from];
            destination=word_indexes[to];
            bfs(source,destination,from,to);
        }
    }
    return 0;
}