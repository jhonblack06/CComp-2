#include <iostream>
using namespace std;
 
void cambio(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubblePuntero(int arr[], int n){
	int *p1;
	int *p2 = arr+n;
	int cont = 0;
	for(p1 = arr ; p2-p1 > 4 ; p1++ ){
		for(int *p3 = arr ; p2-(p1+cont) > 4; p3++){
			if(*p1>*p3){
				cambio(p1,p3);
			}
			cont++;
		}
	}
	
	return;
}
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++){
       for (j = 0; j < n-i-1; j++){
           if (arr[j] > arr[j+1])
              cambio(&arr[j], &arr[j+1]);
          }
      }
}
void imprimir(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int a[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(a)/sizeof(a[0]);
    
    bubbleSort(a, n);
    cout << "Lista ordenada: " << endl;
    imprimir(a, n);
    return 0;
}
