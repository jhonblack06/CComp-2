#include <iostream>
#include <stdlib.h>
#include <conio.h>


//Numbers in order for the game
int Numbers[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};


class P
{
private:
    int board[4][4];    //Game board

public:

//Fills the board
    void Fill()
    {
        int *pointer_to_integer = Numbers;
        for(int (*p)[4] = board; p < board + 4;p++)
        {
            for(int *q = *p; q < *p + 4; q++)
            {
                *q = *pointer_to_integer;
                pointer_to_integer++;
            }
        }

        return;
    }

//Do the movement accordingly to the user input
    void MV_UP()
    {
        // Memory addresses of the game board
        int (*mem_range_begin)[4] = board;
        int (*mem_range_limit)[4] = board + 4;
        // Pointer to search the pivot
        int *pivot;
        // Search for the pivot
        for(int (*p)[4] = board; p < board + 4;p++)
        {
            for(int *q = *p; q < *p + 4; q++)
            {
                if(*q == 0)
                    pivot = q;
            }
        }
        //Do the movement
        if( (pivot - 4) > *mem_range_begin )
        {
            //do the switch
            int tmp = *pivot;
            *(pivot) = *(pivot-4);
            *(pivot-4) = tmp;
        }
        else
            return; // Don't change the board
    }

    void MV_LF()
    {
        // Memory addresses of the game board
        int (*mem_range_begin)[4] = board;
        int (*mem_range_limit)[4] = board + 4;
        // Pointer to search the pivot
        int *pivot;
        // Search for the pivot
        for(int (*p)[4] = board; p < board + 4;p++)
        {
            for(int *q = *p; q < *p + 4; q++)
            {
                if(*q == 0)
                    pivot = q;
            }
        }
        //Do the movement
        if( ( (pivot - 1) > *mem_range_begin) )
        {
            if((((pivot - *mem_range_begin)%4) -1) < 0)
                return;

            //do the switch
            int tmp = *pivot;
            *(pivot) = *(pivot-1);
            *(pivot-1) = tmp;
        }
        else
            return; // Don't change the board
    }

    void MV_DW()
    {
        // Memory addresses of the game board
        int (*mem_range_begin)[4] = board;
        int (*mem_range_limit)[4] = board + 4;
        // Pointer to search the pivot
        int *pivot;
        // Search for the pivot
        for(int (*p)[4] = board; p < board + 4;p++)
        {
            for(int *q = *p; q < *p + 4; q++)
            {
                if(*q == 0)
                    pivot = q;
            }
        }
        //Do the movement
        if( (pivot + 4) < *mem_range_limit )
        {
            //do the switch
            int tmp = *pivot;
            *(pivot) = *(pivot+4);
            *(pivot+4) = tmp;
        }
        else
            return; // Don't change the board
    }

    void MV_RT()
    {
        // Memory addresses of the game board
        int (*mem_range_begin)[4] = board;
        int (*mem_range_limit)[4] = board + 4;
        // Pointer to search the pivot
        int *pivot;
        // Search for the pivot
        for(int (*p)[4] = board; p < board + 4;p++)
        {
            for(int *q = *p; q < *p + 4; q++)
            {
                if(*q == 0)
                    pivot = q;
            }
        }
        //Do the movement
        if( ((pivot +1) < *mem_range_limit) )
        {

            if((((pivot - *mem_range_begin)%4) +1) > 3)
                return;
            //do the switch
            int tmp = *pivot;
            *(pivot) = *(pivot+1);
            *(pivot+1) = tmp;
        }
        else
            return; // Don't change the board
    }

//Check if the user input is correct and proceed
    void Check_Input()
    {
        char input;
        bool accepted = false;
        while(accepted == false)
        {
            std::cout << "\n --> Waiting for user input... ";
            //std::cin >> input;
            input = _getch();
            switch(input)
            {
                case 'w':
                    MV_UP();
                    accepted = true;
                    break;
                case 'a':
                    MV_LF();
                    accepted = true;
                    break;
                case 's':
                    MV_DW();
                    accepted = true;
                    break;
                case 'd':
                    MV_RT();
                    accepted = true;
                    break;
                default:
                    std::cout << "\n Wrong Input, please try again ";
                    break;
            }

        }
        system("cls");
        return;
    }

//Print the board
    void Print()
    {
        for(int (*p)[4] = board; p < board + 4;p++)
        {
            for(int *q = *p; q < *p + 4; q++)
            {
                if (*q < 10)
                    std::cout << *q << "  ";
                else
                    std::cout << *q << " ";
            }
            std::cout << "\n";
        }

        return;
    }

//Verifies if the puzzle is solved
    bool Check()
    {
        int *pointer_to_integer = Numbers;
        for(int (*p)[4] = board; p < board + 4;p++)
        {
            for(int *q = *p; q < *p + 4; q++)
            {
                if(*q != *pointer_to_integer)
                    return false;
                pointer_to_integer++;
            }
        }
        return true;
    }

//The game loop
    void Play()
    {
        bool End_Game = false;
        Print();
        do
        {
            Check_Input();
            std::cout << std::endl; // For printing issues
            Print();

            End_Game = Check();
        }
        while(End_Game == false);
        std::cout << "\n YOU WIN !!! ";
        return;
    }

//Constructor
    P()
    {
        std::cout << " Movements will change the position of zero(0) in the wished direction";
        std::cout << "\n Only use 'w', 'a', 's' and 'd' keys as input \n";
        Fill();
        Play();
    }

};

