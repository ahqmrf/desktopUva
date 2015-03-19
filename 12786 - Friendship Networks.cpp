#include<bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    while(scanf("%d", &N) != EOF)
    {
        priority_queue<int>myQueue;
        for(int i=0; i<N; i++)
        {
            int degrees;
            scanf("%d", &degrees);
            myQueue.push(degrees);
        }
        bool can_form = true;
        while(!myQueue.empty())
        {
            int next = myQueue.top();
            myQueue.pop();
            if(myQueue.size() < next)
            {
                can_form = false;
                break;
            }
            vector<int> edges;
            for(int i=0; i<next; i++)
            {
                int edge = myQueue.top();
                myQueue.pop();
                edges.push_back(edge-1);
            }

            for(int i=0; i<next; i++)
            {
                if(edges[i]) myQueue.push(edges[i]);
            }
        }

        if(can_form) puts("1");
        else puts("0");
    }
    return 0;
}
