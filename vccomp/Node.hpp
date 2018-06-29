#include <iostream>
#include <string>
#include <cctype>

template <typename T = int>
class Node           //Basic element in dynamic lists
{
public:
    T value = NULL;
    Node *next = NULL, *previous = NULL;
public:

    void SetPrev(int* previous)              //Receives a memory address to the previous node
    {
        this -> previous = previous;
    }
    void SetNext(int* next)                  //Receives a memory address to the next node
    {
        this -> next = next;
    }
    void PrintValue()                       //Print the node value
    {
        std::cout << value << "\n";
    }
    Node(T value = 0, Node* next = NULL, Node* previous = NULL)   //Class constructor
    {
        this -> value = value;
        this -> next = next;
        this -> previous = previous;
    }
};

