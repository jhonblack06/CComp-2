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
    LinearList<int> Empty_01;
	LinearList<int> Empty_02;
    LinearList<int> lista(12);
	lista.PrintList();
	std::cout << "\n Fin de Lista\n";
	//ParityLists(lista,Empty_01,Empty_02,IsOdd);
	//(*Function<int>)(lista,Empty_01,Empty_02,IsEven);
	FR<int> CLASS;
	CLASS(lista,Empty_01,Empty_02,IsEven);
    LinearList<int> c(21);
	Empty_01.PrintList();
	std::cout << "\n Fin de Lista\n";
	Empty_02.PrintList();
	std::cout << "\n Fin de Lista\n";
    std::cout << "Merge \n";

	return 0;
}

