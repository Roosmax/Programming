#include <iostream>
#include <fstream>
#include <chrono>
#include <random>

int rand_uns(int min, int max) {
unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
static std::default_random_engine e(seed);
std::uniform_int_distribution<int> d(min, max);
return d(e);
}

using namespace std;

void Sort(int* arr,int n)
{
	int counter=0;
	for(int i=1;i<n;i++){
		for(int j=i; j>0 && arr[j-1]>arr[j];j--){
			counter++;
			int tmp=arr[j-1];
			arr[j-1]=arr[j];
			arr[j]=tmp;
		}
	}
	cout<< counter <<endl;
}

int main()
{
setlocale(LC_ALL,"Rus");
int n, k;
cout<<"Размер массива > "; cin>>n;
int *A=new int[n];
for (k=0; k<n; k++)
{ cout<<k+1<<" элемент > "; A[k] = rand_uns(100, 1000); }
Sort(A, n);
cout<<"Результирующий массив: ";
for (k=0; k<n; k++)cout<<" "<<A[k];
system("pause>>void");
}
