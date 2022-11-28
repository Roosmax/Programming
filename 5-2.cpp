#include <iostream>
using namespace std;

int main()
{
    int n, arr[1000], x;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - i - 1;j++)
        {
            if(arr[j+1]<arr[j])
            {
                int t = arr[j+1];
                arr[j+1]=arr[j];
                arr[j] = t;
            }
        }
    }
    cin >> x;
    int s = 0, r = 0;
    for (int i = n-1; i >= 0; i--)
    {
        if(r + arr[i] <= x)
        {
            r += arr[i];
            s++;
        }
        if(r >= x)
        {
            break;
        }
    }
        if(r == x)
        {
            cout << s;
        }
        else
        {
         cout << -1;
        }
    return 0;
}
