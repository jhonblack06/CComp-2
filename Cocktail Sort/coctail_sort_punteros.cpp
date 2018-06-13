#include <iostream>
using namespace std;

bool asc(int a, int b){
	if(a > b){return true;}
	else{return false;}
}

bool desc(int a, int b){
	if(a < b){return true;}
	else{return false;}
}


void CocktailSort(int a[], int n,bool (*fun)(int,int))
{
    bool swapped = true;
    int *start = a;
    int *end = start +(n - 1);
    while (swapped) {
        swapped = false;
        for (int *i=start; i < end; ++i) {
            if (fun(*i,*(i + 1))) {
                swap(*i, *(i + 1));
                swapped = true;
            }
        }
        if (!swapped){
            break;
        }
        swapped = false;
        end-=1;
        for (int *i = (end - 1); i >= start;i--) {
            if (fun(*i,*(i + 1))) {
                swap(*i, *(i + 1));
                swapped = true;
            }
        }
        ++start;
    }
}

void imprimir(int a[], int n)
{
    for (int *i = a; i < a+n; i++){
        cout << *i << " ";
    }
    cout << endl;
}

int main()
{
    int a[] = { 5, 1, 4, 2, 8, 0, 2 };
    int n = sizeof(a) / sizeof(a[0]);
    CocktailSort(a , n ,desc);
    cout << "Lista ordenada: " << endl;
    imprimir(a , n);
    return 0;
}

