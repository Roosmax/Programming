#include <iostream>
#include <chrono>
using namespace std;

int main()
{
    long int n;
    cin >> n;

    long int last0, last1, next0, next1;
    last0 = 0;
    last1 = 0;
    next0 = 1;
    next1 = 1;
    for(int i = 0; i < n-1; i++)
    {
        last0=next0;
        last1=next1;

        next0=last0+last1;
        next1=last0;
        cout << next0+next1 << "\n" ;
    }
    return 0;
}
