#include <iostream>

/* Calendario, input = mes y año (4 cifras), output,Impresion del calendaio (mes del año), lunes,
martes, miercoles, jueves, viernes */

bool Verif_Year (int year)
{
    bool bool_ver = true;
    bool_ver=(((year%4) == 0)&&((year%100)!= 0))?(true):(false);
    return bool_ver;
}

int dia_find(int dia, int mes, int year)
{
    bool bisiesto = false;
    char *dia_fecha_res[7] = {"Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sábado"};
    int respuesta = 0;
        if ((dia > 31)||(dia < 1)){std::cout << "Formato invalido"; return 0;}
        if ((mes > 12)||(mes < 1)){std::cout << "Formato invalido"; return 0;}
        if(Verif_Year(year)==true){bisiesto = true;}
    std::cout << dia << "-" << mes << "-" << year << std::endl;
    int mod_year= ((year%1000)%100);
    int var = (mod_year/12);
    int verif = mod_year - (var*12);
    int ver_4 = verif/4;
    int year_2 = ((year%1000)-mod_year)/100;
    int tmp= (year - mod_year)/100;
    int anchor_day = tmp % 4;
        switch(anchor_day)
        {
            case 0:
                //std::cout <<"Anchor day es Martes " << std::endl;
                anchor_day = 2;
                break;
            case 1:
                //std::cout <<"Anchor day es Domingo " << std::endl;
                anchor_day = 0;
                break;
            case 2:
                //std::cout <<"Anchor day es Miercoles " << std::endl;
                anchor_day = 5;
                break;
            case 3:
                //std::cout <<"Anchor day es Viernes " << std::endl;
                anchor_day = 3;
                break;
        }
    int res = var + verif + ver_4 + anchor_day;
    int dia_actual = res -((res/7)*7);
        switch(dia_actual)
        {
            case 0:
                //std::cout <<"Domingo " << std::endl;
                break;
            case 1:
                //std::cout <<"Lunes " << std::endl;
                break;
            case 2:
                //std::cout <<"Martes " << std::endl;
                break;
            case 3:
                //std::cout <<"Miercoles " << std::endl;
                break;
            case 4:
                //std::cout <<"Jueves " << std::endl;
                break;
            case 5:
                //std::cout <<"Viernes " << std::endl;
                break;
            case 6:
                //std::cout <<"Sabado " << std::endl;
                break;
        }
        std::cout << "\n Dia inicial..." << dia_fecha_res[dia_actual] << "...\n";
        return  dia_actual;
        //___    ______   _____//

        std::cout << "\n Dia ";
    int dia_2;
        if(mes == 2){ dia_2 = 28 - dia_actual;}
        if (bisiesto == true)
            {
                if(mes == 2){ dia_2 = 29 - dia_actual;}
            }
        if((mes == 1)||(mes == 3)||(mes == 5)||(mes == 7)||(mes == 8)||(mes == 10)||(mes == 12))
            {
                dia_2 = 31 - dia_actual;
            }
        if((mes == 4)||(mes == 6)||(mes == 9)||(mes == 11))
            {
                dia_2 = 30 - dia_actual;
            }
    int fin_de_mes = 0;
        switch(mes)
        {
        case 1:
            if (bisiesto == true){fin_de_mes = 4;}
            else{fin_de_mes = 3;}
            break;
        case 2:
            if (bisiesto == true){fin_de_mes = 29;}
            else{fin_de_mes = 28;}
            break;
        case 3:
            fin_de_mes = 7;
            break;
        case 4:
            fin_de_mes = 4;
            break;
        case 5:
            fin_de_mes = 9;
            break;
        case 6:
            fin_de_mes = 6;
            break;
        case 7:
            fin_de_mes = 11;
            break;
        case 8:
            fin_de_mes = 8;
            break;
        case 9:
            fin_de_mes = 5;
            break;
        case 10:
            fin_de_mes = 10;
            break;
        case 11:
            fin_de_mes = 7;
            break;
        case 12:
            fin_de_mes = 12;
            break;
        }
    int resultante = 0;
        if (fin_de_mes > dia)
            {
                resultante =  (dia + fin_de_mes%7);
                resultante = (resultante - dia_actual)%7+1;
                if (resultante < 0){resultante = resultante*(-1);}
                if (resultante >= 7){resultante = resultante%7;}
                std::cout << dia << "-" << mes << "-" << year << " es " << dia_fecha_res[resultante]<<std::endl;
                return resultante;
            }
        else if (fin_de_mes < dia)
            {
                resultante = (dia - fin_de_mes)%7;
                resultante = (resultante + dia_actual)%7;
                std::cout << dia << "-" << mes << "-" << year << " es " << dia_fecha_res[resultante]<<std::endl;
                return resultante;
            }
        else
            {
                resultante = 0;
                std::cout << dia << "-" << mes << "-" << year << " es " << dia_fecha_res[dia_actual]<<std::endl;
                return resultante;
            }

//2 0 5 3   (0-2  1-0 2-5 3-3 // 4-2 5-0 6-5 7-3 // 8-2 9-0)
}

void Calendario(int x, int y) /* x = mes, y = año */
{
    int m[7][7];

    bool bisiesto = false;
    if( Verif_Year(y) == true ){ bisiesto = true;}
    int dias[7] = {0,1,2,3,4,5,6};
    int dia_inicio = dia_find(1, x, y);
    int dias_totales = 0;


        if(x == 2){ dias_totales = 28;}
        if (bisiesto == true)
            {
                if(x == 2){ dias_totales = 29;}
            }
        if((x == 1)||(x == 3)||(x == 5)||(x == 7)||(x == 8)||(x == 10)||(x == 12))
            {
                dias_totales = 31;
            }
        if((x == 4)||(x == 6)||(x == 9)||(x == 11))
            {
                dias_totales = 30;
            }


    std::cout << dia_inicio << std::endl;
    std:: cout << dias_totales << std::endl;

    /* crea matriz, la llena de 0's */
    for( int i = 0; i < 7; i++)
    {
        for( int j = 0; j < 7; j++)
        {
            m[i][j] = 0;
        }
    }

    int dia = 1;

    for( int i = 0; i < 5; i++)
    {
        for( int j = 0; j < 7; j++)
        {
            m[0][dia_inicio]= dia;
            dia++;
            if( dia == dias_totales + 1)
            {
                dia = 1;
            }
            dia_inicio++;
        }
    }

    for( int i = 0; i < 7; i++)
    {
        for( int j = 0; j < 7; j++)
        {
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return;
}

/* __ */

int main()
{

    //dia_find(21,3,2018);
    //Diciembre de 1976 inicia un miercoles
    dia_find(1,12,1976);


    Calendario(2,1976);

    return 0;
}



