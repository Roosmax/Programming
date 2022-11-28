#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
using namespace std;
#include <chrono>
double get_time() {
    return std::chrono::duration_cast<std::chrono::microseconds>
        (std::chrono::steady_clock::now().time_since_epoch()).count()/1e6;
};

void show_array (int * a)
{
     for (int i=0; i<N; i++)
        cout << a[i] << " ";
     putchar('\n');
}

int main() {
    int array[N], i, j, temp;
    double a = get_time();
    for (i=0; i<N; i++)
        cin >> array[i];
    show_array(array);
    double b = get_time();
    for (i=0; i<N; i++)
        for (j=0; j<N-1; j++)
            if (array[j]>array[j+1]) {
                int tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
    show_array(array);
    cout << b - a << " ";
    return 0;
}
