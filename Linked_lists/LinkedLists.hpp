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
        std::cout << std::endl << std::endl;
        return;
	}
	void josephus(int num,int salto){
	    for(int i=1;i<=num;i++){
            CreateNode(i);
        }
        PrintList();
        //Variables Auxiliares
        Node<T>* pointer = new Node<T>;
        Node<T>* Prev = new Node<T>;
        Prev = head;
        pointer = head;
        while(head->next->next!=head){
            for(int i=1;i<salto;i++){
                Prev=pointer;
                pointer=pointer->next;
            }
            if(pointer==head){head=head->next;}
            Prev->next = pointer->next;
            pointer = pointer->next;
            PrintList();
        }
        std::cout<<"Quedan:"<<'\t';
        PrintList();
    }

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
