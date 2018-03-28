#include <iostream>

using namespace std;

void div1(int num){
     cout << "Se nesesitan " << num << " envases de 1 litro" << endl;
}

void div3(int num){
    int cont=0;
    while(num>=3){
        num = num - 3;
        cont++;
    }
    cout << "Se nesesitan " << cont << " envases de 3 litros" << endl;
    div1(num);
}

void div5(int num){
    int cont=0;
    while(num>=5){
        num = num - 5;
        cont++;
    }
    cout << "Se nesesitan " << cont << " envases de 5 litros" << endl;
    div3(num);
}

void div7(int num){
    int cont=0;
    while(num>=7){
        num = num - 7;
        cont++;
    }
    cout << "Se nesesitan " << cont << " envases de 7 litros" << endl;
    div5(num);
}

int ingresarNum(){
    int num;
    cout << "Ingrese un numero de litros de leche(int+): " << endl;
    cin>> num;
    return num;
}
int main()
{
    int a= ingresarNum();
    while (a < 0){
        cout << "El numero ingresado es invalido " << endl;
        a = ingresarNum();
    }
    cout << "Respuesta: " << endl;
    div7(a);

    return 0;
}
