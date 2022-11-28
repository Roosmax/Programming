#include <iostream>
using namespace std;

int main()
{
    int sum, i, j, n, m, b, mx;
    cin >> n >> m;
    sum = 0;
    mx = 0;
    b = 0;
    int arr[100][100];
    for (int i=0; i < n; i++)
    {
        for (int j=0; j < m; j++)
        {cin >> arr[i][j];}
    }
    for (int i=0; i < n; i++)
    {
        b += arr[i][0];
    }
    for (int j = 0; j < m; j++)
    {
        for(int i = 0; i < n; i++)
        {
            sum += arr[i][j];
        }
        if (sum >= b)
        {
            b = sum;
            mx = j;
            sum = 0;
        }
    }
    cout<< mx;
}
