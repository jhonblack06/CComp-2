#include <iostream>

bool CheckPalindrome(char* word)
{
    word += '\0';
    char* p = word;
    char* q = p;
    while(*q != '\0')
        q++;
    q--;
    while (p<q)
    {
        //std::cout << "P= " << *p << " Q= "<< *q << "\n";
        while(*p == ' ')
            p++;
        while(*q == ' ')
            q--;
        if(*p != *q)
            return false;
        p++;
        q--;
    }
    return true;
}

class Palindrome
{
public:
    bool operator () (char* word)
    {
        return CheckPalindrome(word);
    }
};


int main()
{
    Palindrome p;
    std::cout << p("anita lava la tina");
}
