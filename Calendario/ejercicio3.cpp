#include <iostream>
#include <string>
using namespace std;
int abs(int a){
	return (a<0) ? -a:a;
}
int dias_pasan(int ano,int s)
{
	int eje=2020;
	int anos=abs(ano-eje);
	int bis=anos/4 +s;
	int dias=bis*366 +(anos-bis)*365;
	return dias%7;
}
int main ()
{	
	string mes;
	int ano;
	cout<<"mes::";
	cin>>mes;
	cout<<"año::";
	cin>>ano;
	int agre=0;
	int inicio_2020=3;
	int dia=0;
	int indice=0;
	int suma=0;
	string dias[7]={"Domingo ","Lunes ","Martes ","Miercoles ","Jueves ","Viernes ","Sabado "};
	string meses[12]={"enero","febrero","marzo","abril","mayo","junio","julio","agosto","setiembre","octubre","noviembre","diciembre"};
	int meses_n[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(ano>=2020){
		agre=dias_pasan(ano,1);
		dia=(inicio_2020+agre)%7;
	}else{
		agre=7-dias_pasan(ano,0);
		dia=(inicio_2020+agre)%7;
	}
	if (!(ano%4)) meses_n[1]++;
	for (unsigned int i = 0; i < 12; i ++)
	{
		if(mes==meses[i]){
			indice=i;
			break;		
		}
		suma+=meses_n[i];
	}	
	int cont=0;
	cout<<"dia_en inicio::"<<dia<<"\n";
	cout<<"suma::"<<suma<<"\n";
	cout<<"indice::"<<indice<<"\n";
	dia=(dia+suma%7)%7;
	cout<<"                     "<<mes<<"\n";
	for (unsigned int i = 0; i < 7; i += 1)
	{
		cout<<" "<<dias[i];		
	}
	for (unsigned int b = 0; b < 6; b += 1)
	{
		cout<<"\n";
		for (unsigned int a= 0; a < 7; a += 1)
		{
			if(a>=dia){
			 cout<<"   "<<++cont<<"    ";
			 dia=0;
			}else{
			cout<<"         ";
			}
		if (cont>=meses_n[indice]){
			cout<<"\n";	
			return 0;}	
		}
	} 
}
