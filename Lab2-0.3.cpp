#include <iostream>
#include <chrono>
#include <random>

int rand_uns(int min, int max) {
unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
static std::default_random_engine e(seed);
std::uniform_int_distribution<int> d(min, max);
return d(e);
}

using namespace std;
//функция обмена
void Swap(int *Mas, int i)
{
int temp;
temp=Mas[i];
Mas[i]=Mas[i-1];
Mas[i-1]=temp;
}
//функция шейкерной сортировки
void ShakerSort(int *Mas, int Start, int N)
{
int Left, Right, i;
Left=Start;
Right=N-1;
while (Left<=Right)
{
for (i=Right; i>=Left; i--)
if (Mas[i-1]>Mas[i]) Swap(Mas, i);
Left++;
for (i=Left; i<=Right; i++)
if (Mas[i-1]>Mas[i]) Swap(Mas, i);
Right--;
}
}
//главная функция
int main()
{
setlocale(LC_ALL,"Rus");
int n, k;
cout<<"Размер массива > "; cin>>n;
int *A=new int[n];
for (k=0; k<n; k++)
{ cout<<k+1<<" элемент > "; A[k] = rand_uns(100, 1000); }
ShakerSort(A, 1, n);
cout<<"Результирующий массив: ";
for (k=0; k<n; k++)cout<<" "<<A[k];
system("pause>>void");
}
