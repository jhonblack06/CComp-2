#include <iostream>
using namespace std;

bool comp(int a, int b,bool m){
    if(m){
        if(a > b){return true;}
        else{return false;}
    }
    else{
        if(a < b){return true;}
        else{return false;}
    }
}




void CocktailSort(int a[], int n,bool m)
{
    bool swapped = true;
    bool (*fun)(int,int,bool);
    fun=comp;
    int *start = a;
    int *end = start +(n - 1);
    while (swapped) {
        swapped = false;
        for (int *i=start; i < end; ++i) {
            if (fun(*i,*(i + 1),m)) {
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
            if (fun(*i,*(i + 1),m)) {
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
    bool asc = 0;
    CocktailSort(a , n ,asc);
    cout << "Lista ordenada: " << endl;
    imprimir(a , n);
    return 0;
}

