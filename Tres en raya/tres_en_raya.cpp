#include <iostream>
using namespace std;

void imprimir_tablero(char (*tablero)[3][3],int tam=3)
{
	for (char (*a)[3][3]=tablero; a < tablero+tam; a++)
	{
		cout<<"piso->"<<tablero+tam-a<<"\n";
		for (char (*b)[3]=*a; b < *a+tam; b++)
		{
			for (char *c=*b; c < *b+tam; c++)
			{		
				cout<<" "<<*c;	
			}
			cout<<"\n";
		}
		cout<<"\n";	
	}		
}

char *renovar_tablero_derecha(char (*tablero)[3][3],int tam,char *estoy,char &temp,char poner)
{
		if(estoy!=*(*(tablero))+2 and  estoy!=*(*(tablero)+1)+2 and estoy!=*(*(tablero)+2)+2 and estoy!=*(*(tablero+1))+2 and estoy!=*(*(tablero+1)+1)+2 and estoy!=*(*(tablero+1)+2)+2 and estoy!=*(*(tablero+2))+2 and estoy!=*(*(tablero+2)+1)+2 and estoy!=*(*(tablero+2)+2)+2 )
		{
			*estoy=temp;
			estoy++;
			temp=*estoy;
			*estoy=poner;
		}
		return estoy;
}
char *renovar_tablero_izquierda(char (*tablero)[3][3],int tam,char *estoy,char &temp,char poner)
{
		if(estoy!=*(*(tablero)) and  estoy!=*(*(tablero)+1) and estoy!=*(*(tablero)+2) and estoy!=*(*(tablero+1)) and estoy!=*(*(tablero+1)+1) and estoy!=*(*(tablero+1)+2) and estoy!=*(*(tablero+2)) and estoy!=*(*(tablero+2)+1) and estoy!=*(*(tablero+2)+2) )
		{
			*estoy=temp;
			estoy--;
			temp=*estoy;
			*estoy=poner;
		}
		return estoy;
}
char *renovar_tablero_arriba(char (*tablero)[3][3],int tam,char *estoy,char &temp,char poner)
{
		if(estoy!=*(*(tablero)) and estoy!=*(*(tablero))+1 and estoy!=*(*(tablero))+2  )
		{
			*estoy=temp;		
			estoy-=3;
			temp=*estoy;
			*estoy=poner;
		}
		return estoy;
}
char *renovar_tablero_abajo(char (*tablero)[3][3],int tam,char *estoy,char &temp,char poner)
{
		if(estoy!=*(*(tablero+2)+2) and estoy!=*(*(tablero+2)+2)+1 and estoy!=*(*(tablero+2)+2)+2)
		{
			*estoy=temp;
			estoy+=3;
			temp=*estoy;
			*estoy=poner;
		}
		return estoy;
}
char *renovar_tablero_bajar_nivel(char (*tablero)[3][3],int tam,char *estoy,char &temp,char poner)
{
		if(estoy-9>(**tablero)-1 )
		{
			*estoy=temp;
			estoy-=9;
			temp=*estoy;
			*estoy=poner;
		}
		return estoy;
}
char *renovar_tablero_subir_nivel(char (*tablero)[3][3],int tam,char *estoy,char &temp,char poner)
{
		if(estoy+9<**(tablero+tam))
		{
			*estoy=temp;
			estoy+=9;
			temp=*estoy;
			*estoy=poner;
		}
		return estoy;
}

bool verificar_filas(char (*tablero)[3][3],int tam,char poner)
{
	int cont_f=0;
	for (char (*a)[3][3]=tablero; a < tablero+tam; a++)
	{
		for (char (*b)[3]=*a; b < *a+tam; b++)
		{
			for (char *c=*b; c < *b+tam; c++)
			{		
				if(*c==poner){
					cont_f++;
				}	
			}
				if(cont_f==3){
					//cout<<"aqui";
					return true;
				}else{
					cont_f=0;}
		}	
	}
	return false;
}
bool verificar_columnas(char (*tablero)[3][3],int tam,char poner)
{	
	for (char (*a)[3][3]=tablero; a < tablero+tam; a++)
	{	
		for (char *b=**a; b < *(*a+1); b++)
		{
			if(*b==poner and *(b+3)==poner and *(b+6)==poner)
			{
				//cout<<"aqui1";
				return true;
			}
		}	
	}
	return false;
}
bool verificar_diagonales(char (*tablero)[3][3],int tam,char poner)
{
	for (char (*a)[3][3]=tablero; a < tablero+tam; a++)
	{
		if(***a==poner and *(*(*a+1)+1)==poner and *(*(*a+2)+2)==poner)
		{	
			//cout<<"aqui2";
			return true ;
		}else if(*(**a+2)==poner and *(*(*a+1)+1)==poner and *(*(*a+2))==poner){
			//cout<<"aqui3";
			return true ;
		}	
	}
	return false;
}
bool verificar_columnas_2d(char (*tablero)[3][3],int tam,char poner)
{
	char (*a)[3][3]=tablero;
	for (char *b=**a; b < *(*a+tam); b++)
	{
		//cout<<"respuesta::"<<*b<<"---"<<*(b+3*tam)<<"---"<<*(b+6*tam)<<"\n";
		if(*b==poner and *(b+3*tam)==poner and *(b+6*tam)==poner)
		{
			//cout<<"aqui4\n";
			return true;
		}
	}
	return false;
}
bool verificar_diagonales_2d(char (*tablero)[3][3],int tam,char poner)
{
	int patron=13;
	char (*a)[3][3]=tablero;
	for (char *b=**a; b < *(*a+tam); b++)
	{
				if(*b==poner and *(b+patron)==poner and *(b+2*patron)==poner ){
					//cout<<"aqui5";
					return true;
				}else{
					patron--;
				} 
	}
	return false;	
}
bool verificar(char (*tablero)[3][3],int tam,char poner)
{
	if(verificar_filas(tablero,tam,poner) or verificar_columnas(tablero,tam,poner) or verificar_diagonales(tablero,tam,poner) or verificar_columnas_2d(tablero,tam,poner) or verificar_diagonales_2d(tablero,tam,poner)){
		return true;
	}else{
		return false;
	}
}

int main ()
{
	//INICIALIZAR
	char tablero[3][3][3]={{{'-','-','-'},{'-','-','-'},{'-','-','-'}},{{'-','-','-'},{'-','-','-'},{'-','-','-'}},{{'-','-','-'},{'-','-','-'},{'-','-','-'}}};
    char movimiento;
    
    
    //JUGADOR LOCAL
    char temp_local=tablero[0][0][0];
    tablero[0][0][0]='X';
    //JUGADOR VISITANTE 
    char temp_visitante=tablero[2][2][2];
    tablero[2][2][2]='O';
    
    char *estoy_local=&tablero[0][0][0]; 
    char *estoy_visitante=&tablero[2][2][2];
     
    imprimir_tablero(tablero);
    bool continua=true;	
    bool local,visitante,ganador;
	int cont=0;
	while(continua){
		if(!(cont%2)){
			local=true;
			while(local){
				cin>>movimiento;
				if(movimiento=='a'){
					estoy_local=renovar_tablero_izquierda(tablero,3,estoy_local,temp_local,'X');			
				}else if(movimiento=='d'){
					estoy_local=renovar_tablero_derecha(tablero,3,estoy_local,temp_local,'X');
				}else if(movimiento=='w'){
					estoy_local=renovar_tablero_arriba(tablero,3,estoy_local,temp_local,'X');
				}else if(movimiento=='s'){
					estoy_local=renovar_tablero_abajo(tablero,3,estoy_local,temp_local,'X');
				}else if(movimiento=='f'){
					estoy_local=renovar_tablero_bajar_nivel(tablero,3,estoy_local,temp_local,'X');
				}else if(movimiento=='g'){
					estoy_local=renovar_tablero_subir_nivel(tablero,3,estoy_local,temp_local,'X');
				}else if(movimiento=='m'){
					*estoy_local='X';
					temp_local='X';
					local=false;
					ganador=verificar(tablero,3,'X');
				}else if(movimiento=='q'){
					continua=false;
					local=false;
				}
				imprimir_tablero(tablero);
				if(ganador){
					cout<<"GANO EL LOCAL , GANO X\n";
					continua=false;
					local=false;
				}
			}
		}else{
			visitante=true;
			while(visitante){
				cin>>movimiento;
				if(movimiento=='a'){
					estoy_visitante=renovar_tablero_izquierda(tablero,3,estoy_visitante,temp_visitante,'O');			
				}else if(movimiento=='d'){
					estoy_visitante=renovar_tablero_derecha(tablero,3,estoy_visitante,temp_visitante,'O');
				}else if(movimiento=='w'){
					estoy_visitante=renovar_tablero_arriba(tablero,3,estoy_visitante,temp_visitante,'O');
				}else if(movimiento=='s'){
					estoy_visitante=renovar_tablero_abajo(tablero,3,estoy_visitante,temp_visitante,'O');
				}else if(movimiento=='f'){
					estoy_visitante=renovar_tablero_bajar_nivel(tablero,3,estoy_visitante,temp_visitante,'O');
				}else if(movimiento=='g'){
					estoy_visitante=renovar_tablero_subir_nivel(tablero,3,estoy_visitante,temp_visitante,'O');
				}else if(movimiento=='m'){
					*estoy_visitante='O';
					temp_visitante='O';
					visitante=false;
					ganador=verificar(tablero,3,'O');
				}else if(movimiento=='q'){
					continua=false;
					visitante=false;
				}
				imprimir_tablero(tablero);
				if(ganador){
					cout<<"GANO EL VISITANTE , GANO O\n";
					continua=false;
					visitante=false;
				}
			}
		}	
		cont++;
	}
	
	return 0;
}
