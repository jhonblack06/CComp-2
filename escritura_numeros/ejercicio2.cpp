//ejercicio 2
#include <iostream>
#include <string>
using namespace std;

string nivel1(int numero,int esp)//0-99
	{
	string resultado=" ";
	string u[21]={"cero","uno","dos","tres","cuatro","cinco","seis","siete","ocho","nueve","diez","once","doce",
	"trece","catorce","quince","dieciseis","diesciete","diesciocho","diescinueve","veinte"};
	string d[8]={"veinti","treinta","cuarenta ","cincuenta ","sesenta ","setenta ","ochenta ","noventa "};
	string especial[1]={"veintiun"};

	if (numero<=20){
		return u[numero];	
	}else if(numero<30){
		if (esp==1 and numero==21) return especial[0];
		int det=10;
		resultado+=d[(numero/det)-2];
		resultado=resultado+u[numero%det];
		return resultado;
	}
	int det=10;
	resultado+=d[(numero/det)-2];	
	if (numero%det>0) resultado=resultado+" y "+u[numero%det];
	return resultado;	
	}
string nivel2(int numero,int esp)//'100-999
	{
	if(numero<100)return nivel1(numero,esp);
	if(numero==100) return "cien";
	string resultado=" ";
	string u[9]={"ciento","doscientos","trescientos","cuatrocientos","quinientos","seicientos","setecientos","ochocientos","novecientos"};
	int det=100;
	resultado+=u[((numero/det)-1)];
	if (numero%det>0) resultado+=" "+nivel1(numero%det,esp);
	return resultado;
	}
string nivel3(int numero,int esp)//1000-999 999
	{
	if (numero<1000)return nivel2(numero,esp);
	string resultado=" ";	
	int n1=numero/1000;
	int n2=numero%1000;
	if(n1==1){
		resultado=+" mil "+nivel2(n2,0);
	}else{
		if(n2==0){
			resultado=nivel2(n1,1)+" mil ";
				
		}else{
			esp=1;
			resultado=nivel2(n1,1)+" mil "+nivel2(n2,0);
		}	
	}
	return resultado;
	}
string nivel4(long int numero,int esp)//1 000 000-999 999 999 999
	{
		if (numero<1000000)return nivel3(numero,esp);
		string resultado=" ";	
		int n1=numero/1000000;
		int n2=numero%1000000;
		if(n1==1){
			resultado="un millon "+nivel3(n2,0);
		}else{
			if(n2==0){
			resultado=nivel3(n1,1)+" millones ";
			}else{
			resultado=nivel3(n1,1)+" millones "+nivel3(n2,0);
			}
		}
		return resultado;
	}
int main ()
{
	long int n;
	string res;
	int especial=0;
	cin>>n;
	if (n<0){cout<<"no se lee numeros negativos";
	}else{res=nivel4(n,especial);} 
	cout<<"SE LEE::"<<res<<"\n";
	return 0;
}
