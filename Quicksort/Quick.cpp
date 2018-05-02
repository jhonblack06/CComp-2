#include <iostream>

void cambio(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quickSort( int *a, int izq, int der)
{
    int tmp;
    int m = izq;
    int n = der;
    int *pivot = a + ((izq+der)/2);

    int *q = a;

    while( m <= n)
    {
        while( *(q + m) <  *pivot )
        {
            m++;
        }
        while( *(q+n) > *pivot )
        {
            n--;
        }
        if(m <= n)
        {
            tmp = *( (q + m) );
            *(q+m) = *(q+n);
            *(q+n) = tmp;
            m++;
            n--;
        }
    }
    if (izq < n)
        quickSort(a, izq, n);
    if (m < der)
        quickSort(a, m, der);

}

void imprimir(int *arra, int tam)
{
    for (int *p = arra; p < arra + tam; p++)
    {
        std::cout << " " << *p;
    }
}

int main()
{
    int arr[] = {0,2,7,4,5,2,4,1,9,0};

    quickSort(arr,0,10);
    imprimir(arr,10);


    return 0;
}
