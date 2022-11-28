#include <iostream>
using namespace std;
int main()
{
    int sm, av, n;
    cin >> n;
    int arr[10000];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i<n; i++)
        sm += arr[i];
        av = sm/n;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > av)
            cout<< arr[i] << " ";
    }
return 0;
}
