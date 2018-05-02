#include <iostream>

void imprimir(int arra[], int tam)
{
    for (int *i = arra; i <arra+tam; i++)
    {
        std::cout << " " << *i;
    }
}

void InsertionSort( int arra[], int tam)
{
    for(int *i = (arra+2); i <=(arra+tam); i++)
    {
        int tmp = *i;
        int *location = i;
        location-=1;
        while (( location >= arra ) && ( *location > tmp ))
        {
            *(location + 1) = *location;
            location -=1;
        }
        *(location + 1 ) = tmp;
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
