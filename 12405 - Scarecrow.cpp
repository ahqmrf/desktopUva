    #include <iostream>
    #include <algorithm>
    #include <cmath>
    #include <cstdio>
    #include <vector>
    #include <iterator>
    #include <cstdlib>
    #include <cstring>
    #include <string>
    #include <cctype>
    #include <cstdlib>
    #include <stack>
    #include <list>
    #include <queue>

    using namespace std;

    int main (void)
    {
        int cases, case_no = 0;
        scanf("%d", &cases);
        while(cases--){
            string field;
            int num;
            scanf("%d", &num);
            cin >> field;
            int count = 0;
            for (unsigned int i = 0; i < num; i += 1)
            {
                if(field[i] == '.')
                {
                    count++;
                    i+=2;
                }
            }
            printf("Case %d: %d\n", ++case_no, count);
        }

        return 0;
    }


