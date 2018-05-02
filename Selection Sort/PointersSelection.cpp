#include <iostream>

void imprimir(int arra[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        std::cout << " " << arra[i];
    }
}

void selection_sort(int a[], int n) //n = tam
{
    int posicion,temp;
	int *r = a;
	for(int*p = a; p < a+n-1; p++)
    {
        posicion = p-a;
        int aux = posicion+1;
        for (int *q = &aux; *q < n; (*q)++)
        {
            if( *(r + *q) < *(r + posicion ) )
            {
                posicion = *q;
            }
        }
            if (posicion != p-a)
            {
                 temp = *(p);
                 *(p) = *(a+posicion);
                 *(a+posicion) = temp;

            }
    }
}

int main()
{
    int lista1[] = {9,8,7,6,5,2,0,1};        //8 elem.
    int lista2[] = {10,88,45,2,1,0,3,23};    //8 elem

    selection_sort(lista2,8);
    imprimir(lista2,8);


    return 0;
}
