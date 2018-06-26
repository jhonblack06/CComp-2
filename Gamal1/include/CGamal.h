#ifndef CGAMAL_H
#define CGAMAL_H
#include <iostream>
#include <string>
#include <iostream>
#include <windows.h>
#include <sstream>
#include <fstream>
#include <time.h>
#include <bitset>
#include <vector>
#include <stdlib.h>
#include <math.h>

#include <NTL/ZZ.h>


using namespace NTL;
using namespace std;

class CGamal
{
    public:
        ZZ P;
        ZZ E_1;
        ZZ D;
        ZZ E_2;
        ZZ C_1;
        CGamal(int);
        void Gamal_encriptado(ZZ,ZZ,ZZ);
        void Gamal_desencriptado(ZZ);
        //
        string abecedario="abcdefghijklmnopqrstuvwxyz ";
        virtual ~CGamal();

    protected:

    private:
};

#endif // CGAMAL_H
