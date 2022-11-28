#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#define N 10000
#include <time.h>
#include <chrono>
#include <random>

int rand_uns(int min, int max) {
unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
static std::default_random_engine e(seed);
std::uniform_int_distribution<int> d(min, max);
return d(e);
}

using namespace std;
double get_time() {
    return std::chrono::duration_cast<std::chrono::microseconds>
        (std::chrono::steady_clock::now().time_since_epoch()).count()/1e6;
};

int main()
{
    int array[999999], i, q, j, temp;
    for(i=100; i < 100000; i *= 3)
    {for (q=0; q<i; q++)
        array[q] = rand_uns(1, 100);
    double a = get_time();
    for (q=0; q<i; q++)
        for (j=0; j<i-1; j++)
            if (array[j]>array[j+1]) {
                int tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
    double b = get_time();
    cout << i << " " << 1000*(b - a) << endl;
    }
    return 0;
}
