#include <iostream>
#include <string>
#include "calculadora_modular.h"
using namespace std;
Calculadora_modular::Calculadora_modular()
{
	cout<<"CREADO"<<"\n";
}
int Calculadora_modular::suma(int a, int b){
	return a+b;
}
int Calculadora_modular::resta(int a, int b){
	return a-b;
}
int Calculadora_modular::multiplicacion(int a, int b){
	return a*b;
}

int Calculadora_modular::mod(int a,int b){
	int c;
	if (a>=0){
		c=a%b;
	}else{
		c=-a%b;
		c=b-c;
	}
	return c;
}
int Calculadora_modular::gcd(int a,int b){
	if(!b) {
		return a;
	}else{
		return gcd(b,(mod(a,b)));
	}
}

int Calculadora_modular::inversa(int a,int b){
	int pi_2=0;
	int pi_1=1;
	int pi=1, qi_2,temp,temp1;
	int alw=b;
	if (gcd(a,b)!=1)return -1;
	while(a!=1){
		//cout<<a<<"\n"; 
		qi_2=b/a;
		pi = mod((pi_2 - (pi_1 *qi_2)),alw);
		temp=b;
		b=a;
		a=mod(temp,a);
		pi_2=pi_1;
		pi_1=pi;
	}
	return pi;
}

int Calculadora_modular::operacion(int a,int b,int modulo,string operacion)
	{
		if (operacion=="+"){
			return mod(suma(a,b),modulo);
		}else if(operacion=="-"){
			return mod(resta(a,b),modulo);
		}else if(operacion=="*"){
			return mod(multiplicacion(a,b),modulo);
		}else if(operacion=="inv"){
			a=mod(a,modulo);
			return inversa(a,modulo);
		}
	}
	
