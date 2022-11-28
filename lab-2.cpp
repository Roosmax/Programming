#include <iostream>
using namespace std;


int main()
{
    cout << fixed;
    cout.precision (2);
    fu a_lab_rat;
    float f = 1.0;
    for (int i = 0; i < 100; i++)
    {
        a_lab_rat.f = f;
        Binary(a_lab_rat.u);
        cout << endl;
        cout << f << endl;
        f *= 10;
    }
}
