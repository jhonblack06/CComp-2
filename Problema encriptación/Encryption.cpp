#include <iostream>
#include <fstream>
#include <string>

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
		//std::cout<<a<<"\n";
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

void encrypt_monoaplha_cipher_txt(std::string file ,int Private_key = 165 )
{
    //
    std::ifstream input_file( file.c_str() );
    std::ofstream output_file("Cipher.txt");
    std::string content;
    // Copiado de la cadena
    for(int i = 0; input_file.eof()!=true; i++ )
    {
        content += input_file.get();
    }
    input_file.close();

    //Cifrado
    char encrypt = content[0];
    for( int i = 0; encrypt != '\0'; encrypt = content[++i])
    {
        int tmp = (encrypt*Private_key)%256;
        content[i] = tmp;
    }
    //Elimina el caracter de fin de cadena
    content = content.substr(0, content.length() - 1 );

    output_file << content;
    output_file.close();
    return;
}


void decryption_monoalpha_cipher_txt(std::string file, int Public_key =  45) // default 21, decipher key 61
{
    //
    std::ifstream input_file( file.c_str() );
    std::ofstream output_file("Cipher_2.txt");
    std::string txt;

    // Copiado de la cadena
    for(int i = 0; input_file.eof()!=true; i++ )
    {
        txt += input_file.get();
    }
    input_file.close();
    //
    char decrypt = txt[0];
    for( int i = 0; decrypt != '\0'; decrypt = txt[++i])
    {
        int tmp= (decrypt*Public_key)%256; // int tmp= (encrypt*Private_key + 4)%256; dende 4 es una constante e desplazamiento
        txt[i] = tmp;
    }

    //Elimina el caracter de fin de cadena
    txt = txt.substr(0, txt.length() - 1 );

    output_file << txt;
    output_file.close();
    //std::cout << txt;
    return;
}


int main()
{
    int privat,publi;
    std::cout<< "Ingrese la clave para el cifrado: " << std::endl;
    std::cin>>publi;
    privat=inversa(publi,256);
    encrypt_monoaplha_cipher_txt("Plain_Text.txt",publi);
    decryption_monoalpha_cipher_txt("Cipher.txt",privat);

    return 0;
}

