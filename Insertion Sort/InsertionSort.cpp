#include <iostream>

void imprimir(int arra[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        std::cout << " " << arra[i];
    }
}

void InsertionSort( int arra[], int tam)
{
    int i;
    for(i = 2; i <= tam; i++)
    {
        int tmp = arra[i];
        int location = i -1;

        while (( location >= 0 ) && ( arra[location] > tmp ))
        {
            arra[location + 1] = arra[location];
            location = location - 1;
        }
        arra[ location + 1 ] = tmp;
    }

    return;
}

int main()
{
    int lista1[] = {9,8,7,6,5,2,0,1};        //8 elem.
    int lista2[] = {10,88,45,2,1,0,3,23};    //8 elem

    InsertionSort( lista2, 8);
    imprimir(lista2,8);


    return 0;
}

