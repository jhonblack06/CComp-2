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
	for (int i = 0; i < n-1; i++)
	{
	    posicion = i; //posicion se establece en valor actual de la lista
		for (int j = i+1 ; j < n; j++)
		{
		if (a[j] < a[posicion])
                   posicion = j;
		}

	//intercambia valores
            if (posicion != i)
            {
                 temp = a[i];
                 a[i] = a[posicion];
                 a[posicion] = temp;
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
