#include"Node.hpp"

template <typename T>
class LinearList        //List with elements in the heap, with beginning and end
{
public:
    Node<T>* First = NULL;          //Beginning node
    Node<T>* pointer = NULL;           //Pointer to the current node
/*
    void Next();                 //Sets the pointer to the next node
    void Previous();            //Sets the pointer to the previous node
    void SetNext();             //Sets the next node
    void SetPrevious();         //Sets the previous node
*/
    void CreateNode(T val)      //This will add a new node to the list
    {
        Node<T> *ptrToNew = new Node<T>;
        ptrToNew -> value = val;
        ptrToNew -> next = NULL;

        if(First == NULL)
        {
            First = ptrToNew;
            ptrToNew = NULL;
            return;
        }
        else
        {
            pointer = First;
            Node<T>* PrevNode = new Node<T>;
            //
            while(pointer != NULL)
            {
                //Returns if the element already exists
                if(pointer->value == val)
                {
                    delete ptrToNew;
                    return;
                }
                //
                if(val < (First->value) )
                {
                    First = ptrToNew;
                    ptrToNew -> next = pointer;
                    ptrToNew = NULL;
                    return;
                }
                //
                else if( (PrevNode->value < val) && (val < (pointer->value) ) )
                {
                    PrevNode->next = ptrToNew;
                    ptrToNew->next = pointer;
                    ptrToNew = NULL;
                    return;
                }

                PrevNode = pointer;
                pointer = pointer ->next;
            }
            //Create the node at the end of the list
            PrevNode->next = ptrToNew;
            ptrToNew = NULL;
            return;

        }

        /*
        if(pointer->next == NULL) //Verifies if the list is empty
            {
                pointer->next = ptrToNew;
                ptrToNew->value = val;
            }
        else
            {
                ptrToNew->next = pointer;
                ptrToNew->value = val;
            }
        */
    }

    void RemoveNode(T val)           //Delete the node with the val
    {
        Node<T>* tmp = new Node<T>;
        tmp = First;
        pointer = First;

        while(pointer != NULL)
        {
            if(pointer->value == val)
            {
                if(pointer == First)
                    First = First->next;
                tmp->next = pointer->next;
                return;
            }
            tmp = pointer;
            pointer = pointer->next;
        }
        std::cout << "No element with value "<<val<<" in the list\n";
        /*
        if(Search(val) == true)
        {
            tmp = pointer;
            pointer = pointer ->next;
            delete tmp;
        }*/
        return;
    }

    void RemoveAll()            //Delete all  nodes
    {
        Node<T> * tmp = new Node<T>;
        tmp = First;
        pointer = First->next;
        while(pointer != NULL)
        {
            delete tmp;
            tmp = pointer;
            pointer = tmp->next;
        }
        First = NULL;
        std::cout << "List Cleaned\n";
    }

    bool Search(T val)               //Search an item in the list and place the pointer into it
    {
        pointer = First;
        while(pointer != NULL)
        {
            if(pointer->value == val)
                {
                    std::cout << "Element found in memory location "<< pointer << "\n";
                    return true;
                }
            pointer = pointer -> next;
        }
        return false;
    }

    void SearchAndAddt(T val)         //Search an item in the list and add the item if it do not exist.
    {
        pointer = First;
        while(pointer)
        {
            if(pointer->value == val)
                return;
            pointer = pointer -> next;
        }

    }

    void PrintList()            //Prints the list
    {
        pointer = First;
        while(pointer != NULL)
        {
            std::cout << "Value: " << pointer->value << " Address: " << pointer << std::endl;
            pointer = pointer -> next;
        }
    }

    LinearList(){               //Create an "empty" Linear List
        First = NULL;
        pointer = First;
    }

    LinearList(int e)           //Create a Linear List with sorted elements until e
    {
        for(int i=0;i<=e;i++){
		CreateNode(i);
	}
    }
    ~LinearList()               //Destructor
    {
        RemoveAll();
    }
};

template <typename T>
class CircularList              //List with elements in the heap, with beginning and the next element after the last is the first element
{
    	Node<T>* head = NULL;
    	Node<T>* pointer = NULL;
    	Node<T>* Prev = NULL;
public:
	void CreateNode(T val)
	{
	    Node<T>* PtrToNew = new Node<T>(val, NULL, NULL);

        pointer = head;
        Prev = head;
        if(head == NULL){
            head = PtrToNew;
            PtrToNew->next = head;
            PtrToNew = NULL;
        }
        else
        {
            while( Prev->next != head)
                {
                    if(pointer->value == val){
                        delete PtrToNew;
                        return;
                }
                else if( (Prev->value < val ) && val < pointer->value)
                {
                    Prev->next = PtrToNew;
                    PtrToNew->next = pointer;
                    PtrToNew = NULL;
                    return;
                }
                Prev = pointer;
                pointer = pointer->next;
            }
            Prev->next = PtrToNew;
            PtrToNew->next = head;
            if(val< (head->value))
            {
                head=PtrToNew;
            }
            PtrToNew = NULL;
        }

	}

	void RemoveNode(T val)
	{
        pointer = head->next;
        Prev = head;
        while(Prev->next != head)
        {
            if(pointer->value==val){
                Prev->next = pointer->next;
                return;
            }
            Prev = pointer;
            pointer = pointer->next;
        }
        if(pointer->value==val)
        {
            Prev->next = pointer->next;
            if(pointer == head){head = pointer->next;}
            return;
        }
        std::cout<<"Node not found\n"<<std::endl;
	}
	void RemoveAll()
	{
	   Node<T> * tmp = new Node<T>;
        tmp = head;
        pointer = head->next;
        while(pointer->next != head)
        {
            delete tmp;
            tmp = pointer;
            pointer = tmp->next;
        }
        head = NULL;
        std::cout << "Circular List Cleaned\n";
	}
	void PrintList()
	{
	    pointer = head;
        if(head==NULL)return;
        while(pointer->next!=head){
            std::cout << "Value: " << pointer->value << " Address: " << pointer << std::endl;
            pointer = pointer->next;
        }
        std::cout << "Value: " << pointer->value << " Address: " << pointer << std::endl;
        return;
	}
	void josephus(T,T);

	CircularList()
	{
	    head = NULL;
	}

	CircularList(int e)
	{
	    for(int i = 0; i <= e; i++)
            CreateNode(i);
	}

	~CircularList()               //Destructor
    {
        RemoveAll();
    }
};

template <typename T>

void Merge(LinearList<T> &a, LinearList<T> b)
{
    Node<T>* aux = a.First;
    b.pointer = b.First;
    a.pointer = a.First;
    while(a.pointer!=NULL){
        b.pointer = b.First;
        while(b.pointer!=NULL)
        {
            if(a.First->value > b.First->value)
            {
                aux = b.First;
                b.First = a.First;
                a.First = aux;
                a.First->next = b.First;
            }
            else if(a.pointer->value > b.pointer->value)
            {
                aux = b.pointer;
                b.pointer = a.pointer;
                a.pointer = aux;
                a.pointer->next = b.pointer;
            }

            b.pointer = b.pointer->next;
        }
        b.First = b.First->next;
        a.pointer = a.pointer->next;
    }
    a.PrintList();
    return;
}

void Merge2(LinearList<T> &a, LinearList<T> b)
{
    //Node<T>* aux = a.First;
    Node<T>* aux1 = NULL;
    Node<T>* aux2 = NULL;
    Node<T>* aux3 = NULL;
    b.pointer = b.First;
    a.pointer = a.First;
    int v=1;
        if(a.First->value < b.First->value){
            aux2=a.First;
            aux3=b.First;
            while(a.pointer!=NULL){
                while(a.pointer->value < b.pointer->value && v){
                    if(a.pointer->next->value < b.pointer->value ){
                        a.pointer=a.pointer->next;
                    }else{
                        v=0;
                    }
                    //aux2=a.pointer;
                    //a.pointer=a.pointer->next;
                }
                if(a.pointer->value < b.pointer->value){

                    aux3=b.pointer;

                    aux1=a.pointer->next;
                    a.pointer->next=aux3;
                    aux3->next=aux1;
                    }
                b.pointer=b.pointer->next;
            }
        }else{
            while(b.pointer!=NULL){
                if(b.pointer->value < a.pointer->value){


                    }
                }
            b.pointer=b.pointer->next;
        }
        /*b.pointer = b.First;
        while(b.pointer!=NULL)
        {
            if(a.First->value > b.First->value)
            {
                aux = b.First;
                b.First = a.First;
                a.First = aux;
                a.First->next = b.First;
            }
            else if(a.pointer->value > b.pointer->value)
            {
                aux = b.pointer;
                b.pointer = a.pointer;
                a.pointer = aux;
                a.pointer->next = b.pointer;
            }

            b.pointer = b.pointer->next;
        }
        b.First = b.First->next;
        a.pointer = a.pointer->next;*/
    }
    a.PrintList();
    return;
}


