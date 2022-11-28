#include <iostream>
using namespace std;
int main()
{
    int n, sum = 0;
    cin >> n;
    int a[100];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        if (i%2 == 0)
        {
            sum += a[i];
        }
        else
        {
            sum -= a[i];
      }
    }
    cout << sum << " " ;
    return 0;
}



