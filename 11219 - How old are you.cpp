#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main (void)
{
    int cases, case_no = 0;
    cin >> cases;
    string line;
    getline(cin, line);

    while(cases--)
    {
        char a;
        getline(cin, line);


        int born[3], present[3];

        cin >> present[0] >> a >> present[1] >> a >> present[2];
        cin >> born[0] >> a >> born[1] >> a >> born[2];
        if(born[0] > present[0]) present[1]--;
        if(born[1] > present[1]) present[2]--;

        cout << "Case #" << ++case_no << ": ";

        if(present[2] - born[2] > 130) cout << "Check birth date" << endl;
        else if (present[2] - born[2] < 0) cout << "Invalid birth date" << endl;
        else cout << present[2] - born[2] << endl;
    }

    return 0;
}
