#include<iostream>
#include<cstdio>
using namespace std;

int main (void)
{
    int counter, donation, current;
    string operation;
    scanf("%d", &counter);
    while(counter--){
        cin >> operation;
        if(operation == "donate"){
            scanf("%d", &donation);
            current = current + donation;
        }
        else if(operation == "report"){
            printf("%d\n", current);
        }
    }

    return 0;
}
