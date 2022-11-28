#include <iostream>
using namespace std;

int main()
{
    int n, arr[1000], sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i = -1; i < n - 2;)
    {
        if(arr[i+1]<=arr[i+2])
        {
            sum = sum + arr[i+1];
            i++;
        }
        else
        {
            sum = sum + arr[i+2];
            i+=2;
        }
    }
    cout << sum;
    return 0;
}
