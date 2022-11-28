#include <iostream>
using namespace std;

    int main()
    {
        unsigned int a = 0;
        cin >> a;
        int res[32] = {0};
        {
            for (int i = 0; i < 31 ; i++)
            {
                res[i] = a % 2;
                a /= 2;
            }
            for (int i  = 31; i >= 0; i--)
            {
                cout << res[i];
            }
        }
    }
