#ifndef CALCULADORA_MODULAR_H
#define CALCULADORA_MODULAR_H
#include <string>

using namespace std;

class Calculadora_modular
{
    public:
    	Calculadora_modular();
		int suma(int a, int b);
		int resta(int a, int b);
		int multiplicacion(int a, int b);
		int mod(int a,int b);
		int gcd(int a,int b);
		int inversa(int a,int b);
		int operacion(int a,int b,int modulo,string operacion);

};

#endif
