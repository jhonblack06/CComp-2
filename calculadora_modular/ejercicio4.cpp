#include <iostream>
#include <string>
using namespace std;

int suma(int a, int b){
	return a+b;
}
int resta(int a, int b){
	return a-b;
}
int multiplicacion(int a, int b){
	return a*b;
}

int mod(int a,int b){
	int c;
	if (a>=0){
		c=a%b;
	}else{
		c=-a%b;
		c=b-c;
	}
	return c;
}
int gcd(int a,int b){
	if(!b) {
		return a;
	}else{
		return gcd(b,(mod(a,b)));
	}
}

int inversa(int a,int b){
	int pi_2=0;
	int pi_1=1;
	int pi=1, qi_2,temp,temp1;
	int alw=b;
	if (gcd(a,b)!=1)return -1;
	while(a!=1){
		cout<<a<<"\n"; 
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

int operacion(int a,int b,int modulo,string operacion)
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
int main ()
{
	int op1,op2,modulo,resultado;
	string operando;
	cout<<"INGRESAR DATOS:\n";
	cout<<"op1:\n";
	cin>>op1;	
	cout<<"op2:\n";
	cin>>op2;
	cout<<"modulo de::\n";
	cin>>modulo;
	cout<<"operacio(+,-,*,inv):\n";
	cin>>operando;
	resultado=operacion(op1,op2,modulo,operando);
	cout<<"RESULTADO::\n";
	if (resultado==-1) {
		cout<<"NO TIENEN INVERSA\n";
	}else{
		cout<<resultado<<"modulo"<<modulo<<"\n";
	}
	return 0;
}



