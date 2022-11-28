#include <iostream>
using std::cout;
using std::endl;
using std::cin;
unsigned long long int primorial(int n)
{
    long long int a = 1, b = 0;
    for(int i = 1; i < n + 1 ; i++)
    {
        b = 0;
        for(int j = 1; j < i + 1; j++)
        {
            if( i % j == 0)
            {
                b++;
            }
        }
        if (b > 1 && b < 3)
        {
            a *= i;
        }
    }
    return a;
}
int main()
{
        int n;
        cin >> n;
        cout << primorial(n) << endl;
        return 0;
}
