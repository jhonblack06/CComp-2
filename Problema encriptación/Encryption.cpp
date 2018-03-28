#include <iostream>
#include <fstream>
#include <string>

void encrytion_monoaplhabetic_cipher(std::string &txt, int Private_key =  21) // default 21, decipher key 61
{

    char encrypt = txt[0];
    for( int i = 0; encrypt != '\0'; encrypt = txt[++i])
    {
        int tmp= (encrypt*Private_key)%256;
        txt[i] = tmp;
    }

    return;
}

void decryption_monoaplhabetic_cipher(std::string &txt, int Private_key =  61) // default 21, decipher key 61
{
    char encrypt = txt[0];
    for( int i = 0; encrypt != '\0'; encrypt = txt[++i])
    {
        int tmp= (encrypt*Private_key)%256; // int tmp= (encrypt*Private_key + 4)%256; dende 4 es una constante e desplazamiento
        txt[i] = tmp;
    }

    return;
}

void encrypt_this (std::string &txt, int key = 331) //XOR method  // 42 as default key
{
    char encrypt = txt[0];
    for(int i = 0; encrypt != '\0';encrypt = txt[++i])
    {
        int tmp = encrypt/1;
        txt[i] = tmp^key;
    }
    //std::cout << txt << std::endl;
    return;
}

void decrypt_this (std::string &txt, int key = 331) //XOR method
{
    char encrypt = txt[0];
    for(int i = 0; encrypt != '\0';encrypt = txt[++i])
    {
        int tmp = encrypt/1;
        txt[i] = tmp^key;
    }
    //std::cout << txt<< std::endl;
    return;
}

// CIFRADO MONOALFABETICO o ALGORITMO AFIN (EJERCICIO 5) //

void copy_text(std::string a , std::string b )// = "Plain_Text.txt" = "Cypher.txt"
{
    std::ifstream input_file( a.c_str() );
    std::ofstream output_file( b.c_str() );
    std::string input_content = "";

    int i = 0;
    for( i; input_file.eof()!=true; i++ )
    {
        input_content += input_file.get();
    }
    input_file.close();

    //Elimina el caracter de fin de cadena
    input_content = input_content.substr(0, input_content.length() - 1 );

    output_file << input_content;
    output_file.close();

    return;
}

void encrypt_monoaplha_cipher_txt(std::string file ,int Private_key = 21 )
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


void decryption_monoalpha_cipher_txt(std::string file, int Public_key =  61) // default 21, decipher key 61
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
    /*
    std::string a = "Prueba texto, num3r05 .... @@ $% ..    espacios";

    std::cout<<a<<std::endl;
    encrypt_this(a);
    std::cout<<a<<std::endl;
    decrypt_this(a);
    std::cout<<a<<std::endl;

    std::cout << "\nPrueba de cifrado 2, cifrado monoalfabetico o algoritmo afin \n" << std::endl;

    std::cout<<a<<std::endl;
    encrytion_monoaplhabetic_cipher(a);
    std::cout<<a<<std::endl;
    decryption_monoaplhabetic_cipher(a);
    std::cout<<a<<std::endl;
    */
    //copy_text("Plain_Text.txt", "Prueba.txt");

    encrypt_monoaplha_cipher_txt("Plain_Text.txt");
    decryption_monoalpha_cipher_txt("Cipher.txt");

    return 0;
}

