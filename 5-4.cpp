#include <iostream>
using namespace std;

int search_rec(int x, int* array, int n)
{
    int m[100];
    for (int i = 0; i < n; i++)
        m[i]= *(array+i);
    int mid = n/2, l = 0, r = n;
    for( int i = 0; i < n; i++)
    {
        if (m[mid]==x)
            return mid;
        else if(m[mid]>x)
        {
            r = mid;
            mid = (mid - l)/2;
        }
        else if(m[mid]<x)
        {
            l = mid;
            mid = mid +(r-mid)/2;
        }
    }
        return -1;
}
int main()
{
    int n, a[100], x;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < 5; i++)
    {
        cin >> x;
        cout << search_rec(x, a, n) << " ";
    }
    cout << endl;
    return 0;
}
