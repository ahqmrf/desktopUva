#include<iostream>
#include<vector>

using namespace std;

int main ()
{
    int n;
    while(cin >> n)
    {
        if(!n) break;
        vector<int> cards, throwed;
        for(int i = 1; i <=n; ++i)
        {
            cards.push_back(i);
        }

        while(1)
        {
            if(cards.size() == 1) break;
            int card = cards[0];
            cards.erase(cards.begin());

            throwed.push_back(card);
            card = cards[0];
            cards.erase(cards.begin());
            cards.push_back(card);
        }

        cout << "Discarded cards: ";
        for(int i = 0; i < throwed.size();++i)
        {
            if(i == throwed.size()-1) cout << throwed[i] << endl;
            else cout << throwed[i] << ", ";
        }

        cout<< "Remaining card: " << cards[0] << endl;
    }

    return 0;
}
