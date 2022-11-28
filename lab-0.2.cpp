#include <iostream>
using namespace std;

void Binary(unsigned int a)
{
    for (int i = 0; i < 32; i++)
    {
        if ((a<<1)>>1 == a)
        {
            cout << '0';
        }
        else
        {
            cout << '1';
        }
        a = a << 1;
    }
}
int main()
{
    unsigned int a = 0;
    cin >> a;
    Binary(a);
    cout << endl;
}
