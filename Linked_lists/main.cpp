#include "LinkedLists.hpp"

typedef bool (*FF)(int);
//Function
bool IsEven(int a)
{
    if(a%2==0)
        return true;
    return false;
}
bool IsOdd(int a)
{
    if(a%2==0)
        return false;
    return true;
}

template <typename C>
void ParityLists(LinearList<C>& A, LinearList<C>& B, LinearList<C>& D,FF a)
{
    Node<C>* tempPointer = A.First;
    while(tempPointer !=NULL)
    {
        if( a(tempPointer->value) == true )
        {
            B.CreateNode(tempPointer->value);
        }
        else
        {
            D.CreateNode(tempPointer->value);
        }
        tempPointer = tempPointer->next;
    }
    return;
}

//Pointer to Function
template <typename C>
void (*Function)(LinearList<C>&,LinearList<C>&,LinearList<C>&,FF a) = &ParityLists;

//Functors
template<typename C>
class FR
{
    public:
    C opc;
    void Metodo(C opcx);
    void operator()(LinearList<C> &A,LinearList<C> &B, LinearList<C> &D, FF a)
    {
        (*Function<C>)(A,B,D,IsOdd);
    }
};


// MAIN
int main()
{
    CircularList<int> lista;
    int tam = 14;
	for(int i=0;i<=tam;i++){
		lista.CreateNode(i);
	}
	//lista.PrintList();
	lista.josephus(tam,8);
	std::cout << "\n Fin de Lista\n";

	return 0;
}

