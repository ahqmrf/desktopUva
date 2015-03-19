// next_permutation example
#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort
#include <cstdio>
#include<string>
#include<vector>

using namespace std;

int main () {

    int cases, case_no = 0;
    scanf("%d", &cases);
    string line;
    getline(cin, line);
    while(cases--){
        string mychars;
        cin >> mychars;
        int n = mychars.length();
        sort (mychars.begin(), mychars.end());

        vector<string>res;

        do {
            string str;
            for(int i = 0; i<n; i++)
                str += mychars[i];
            res.push_back(str);
        } while ( next_permutation(mychars.begin(), mychars.end()));

        sort(res.begin(), res.end());

        for(int i = 0; i < res.size(); ++i)
        {
            cout << res[i] << endl;
        }
        cout << endl;
    }
  return 0;
}




