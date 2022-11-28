#include <iostream>
using namespace std;
void decr(int *px)
{
    int x;
    x = *px - 1;
}
int main()
{
    int x = 10;
    decr(&x);
    cout << x << endl;
    return 0;
}
