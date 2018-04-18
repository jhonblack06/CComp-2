#include <iostream>

void imprimir(int arra[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        std::cout << " " << arra[i];
    }
}

//QUICKSORT
void quickSort(int a[], int izq, int der)
{

      int i = izq, j = der;
      int tmp;
      int pivot = a[(izq + der) / 2];
      /* partition */
      while (i <= j)
        {
            while (a[i] < pivot)
                  {i++;}
            while (a[j] > pivot)
                {j--;}
            if (i <= j)
            {
                  tmp = a[i];
                  a[i] = a[j];
                  a[j] = tmp;
                  i++;
                  j--;
            }
      }
      /* recursion */
      if (izq < j)
            quickSort(a, izq, j);
      if (i < der)
            quickSort(a, i, der);

}

int main()
{
    int lista1[] = {9,8,7,6,5,2,0,1};        //8 elem.
    int lista2[] = {10,88,45,2,1,0,3,23};    //8 elem

    quickSort(lista1,0,8);
    imprimir(lista1,8);


    return 0;
}



