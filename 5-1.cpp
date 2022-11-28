#include <iostream>
using namespace std;

int main()
{
    int a, x = 0, y = 0, z = 0;
    cin >> a;
    while(a % 5 != 0)
    {
        z++;
        a= a - 1;
    }
    if(a % 10 == 0)
    {
        for(int i=0; i < a; i = i + 10)
        {
            x++;
        }
        cout << x << " ";
    }
    else
    {
        while(a%10 != 0)
        {
            y++;
            a=a-5;
        }
        if(a%10 == 0)
        {
            for(int i=0; i < a; i=i+10)
            {
                x++;
            }
            cout << x << " ";
        }
    }
    cout << y << " ";
    cout << z << " ";
}
