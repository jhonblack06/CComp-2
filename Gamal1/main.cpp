#include <iostream>
#include "CGamal.cpp"

using namespace std;

int main()
{
    CGamal obj1(64);
    int bucle=0;
    while(bucle!=1)
    {
    int opcion;
    cout<<"1)ENCRIPTAR"<<endl;
    cout<<"2)DESENCRIPTAR"<<endl;
    cout<<"ELIJA UN OPCION:";
    cin>>opcion;
    if(opcion==1){
    ZZ E1,E2,P;
    cout<<"INGRESE CLAVE PUBLICA: "<<endl;
    cout<<"ingrese E1: ";
    cin>>E1;
    cout<<"ingrese E2: ";
    cin>>E2;
    cout<<"ingrese P: ";
    cin>>P;
    cout<<endl;
    obj1.Gamal_encriptado(E1,E2,P);
    cout<<endl;
    system("pause");
    cout<<endl;
    }
    if(opcion==2){
    ZZ C1;
    cout<<"ingrese C1: ";
    cin>>C1;
    obj1.Gamal_desencriptado(C1);
    system("pause");
    cout<<endl;
    }
    }
}
