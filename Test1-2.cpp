#include <iostream>
using namespace std;
int main()
{
    int n, sum = 0, A = 0, b;
    cin >> n;
    int a[120];
    for (int i = 0; i < n - 1;)
    {
        cin >> a[i];
        i++;
    }
    for (int i= 0; i < n + 1;)
    {
        sum += i;
        i++;
    }
    for (int i = 0; i < n - 1;)
    {
        A += a[i];
        i++;
    }
    b = sum - A;
    cout << b << " ";
}
