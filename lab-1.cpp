#include <iostream>
using namespace std;

void Binary(unsigned int a)
{
    for (int i=0; i < 32; i++)
    {
        if((a<<1)>>1 == a)
        {
            cout << '0';
        }
        else
        {
            cout << '1';
        }
        a = a << 1;
    }
}
union fu
{
    unsigned int u;
    float f;
};
int main()
{
    fu a_lab_rat;
    cin >> a_lab_rat.f;
    Binary(a_lab_rat.u);
}
