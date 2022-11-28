#include <iostream>
using std::cout;
using std::endl;
using std::cin;

char ouija[3][13]  = {
                {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'},
                {'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'},
                {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', '!', '?'}
        };

void message(int i_start, int j_start, int length)
{
    int i, j, l = length, i_sw, j_sw;
    i = i_start;
    j = j_start;
    char p[50] = {0};
    p[0] = ouija[i][j];
    for(int I = 1; I < l - 1; I++)
    {
        i_sw , j_sw = 0;
        cin >> i_sw >> j_sw;
        if(i+i_sw > 2 || j+j_sw > 13 || j+j_sw < 0 || i+i_sw < 0)
        {
            cout << "THE SPIRITS ARE RESTLESS" << " ";
            return;
        }
        else
        {
        i += i_sw;
        j += j_sw;
        p[I] = ouija[i][j];
        }
    }
    for (int I = 0; I < l; I++)
    {
        cout << p[I];
    }
}

int main()
{
        int i_swap_0, j_swap_0, i_swap_1, j_swap_1;
        cin >> i_swap_0 >> j_swap_0 >> i_swap_1 >> j_swap_1;
        char tmp = ouija[i_swap_0][j_swap_0];
        ouija[i_swap_0][j_swap_0] = ouija[i_swap_1][j_swap_1];
        ouija[i_swap_1][j_swap_1] = tmp;

        int i_start, j_start, length;
        cin >> i_start >> j_start >> length;
        message(i_start, j_start, length);

        return 0;
}
