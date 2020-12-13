/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Daniel Glez de Chaves
 * @date 13 dic. 2020
 * @brief Pasado un archivo de encriptar un archivo en el que salga el texto encriptado, el tipo de encriptado  
 *        una contraseña, encripta o desencripta el archivo pasado por el usuario
 *        
 *
 */   


#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "funciones_cripto.h"
#include <string.h>
#include <cstring>

/** Muestra el modo de uso correcto del programa
 *  En caso de que el uso no sea el correcto, muestra el mensaje y finaliza
 *  la ejecución del programa.
 *  El programa precisa un único número natural para su ejecución.
 *
 *  @param[in] argc Number of command line parameters
 *  @param[in] argv Vector containing (char*) the parameters
 */
void ayudas_programa (int argc,char* argv[]){ //funcion para la correcta ejecucion del programa 
if(argc==2){
std::string ayuda= argv[1];
    if(ayuda=="--help"){
        std::cout<<texto_ayuda<<std::endl;
        std::cout<<argv[0]<<" -- Cifrado de ficheros"<<std::endl;
        std::cout<<"Modo de uso: "<<argv[0]<<" fichero_entrada fichero_salida método password operación"<<std::endl;
        std::cout<<" "<<std::endl;
        std::cout<<"fichero_entrada: Fichero a codificar"<<std::endl;
        std::cout<<"fichero_salida:  Fichero codificado"<<std::endl;
        std::cout<<"método:          Indica el método de encriptado"<<std::endl;
        std::cout<<"                   1: Cifrado xor"<<std::endl;
        std::cout<<"                   2: Cifrado de cesar"<<std::endl;
        std::cout<<"password:        Palabra secreta en el caso de método 1, Valor de K en el método 2"<<std::endl;
        std::cout<<"operación:       Operación a realizar en el fichero"<<std::endl;
        std::cout<<"                   +: encriptar el fichero"<<std::endl;
        std::cout<<"                   -: desencriptar el fichero"<<std::endl;
        exit(EXIT_SUCCESS);
}
}
if(argc!=6){
    std::cout<<"Modo de uso: "<<argv[0]<<" fichero_entrada fichero_salida método password operación"<<std::endl;
    std::cout<<"Para más ayuda, y saber su metodo de uso pruebe a escribir: "<<argv[0]<<" --help"<<std::endl;
    exit(EXIT_SUCCESS);
}
}

/** Devuelve el valor de la suma de todos los términos de valor par de la serie de
 *  Fibonacci menores que kLimit
 *
 *  @param[in] texto_a_codificar es el texto a codificar
 *  @param[in] argv[]  almacena los datos pasados por linea de codigo
 *  @return el codigo encriptado o desencriptado
 */
std::string cripto_uncripto_cesar (std::string texto_a_codificar, char* argv[]){ //funcion que encripta o desencripta el archivo pasado en cesar
std::string palabra = texto_a_codificar;
int largo = palabra.length();
std::string signo= argv[5];
char letra;
int key = std::stoi(argv[4]);
std::string operacion= argv[5];
std::string palabra_cripto=palabra;
if (signo=="+"){  
    for(int i=0;i<=largo;i++){
        letra=palabra[i];
        letra=static_cast<char>(letra+key);
        palabra_cripto[i]= letra;
    }
return palabra_cripto;
}if(signo=="-")  {
    for(int i=0;i<=largo;i++){
        letra=palabra[i];
        letra=static_cast<char>(letra-key);
        palabra_cripto[i]= letra;
    }
return palabra_cripto;
}
if(signo!="-"|| "+"){
    std::cout<<"Error"<<std::endl;
    std::cout<<"Signo de operacion invalido"<<std::endl;
    return 0;
}
}
/** Devuelve el valor de la suma de todos los términos de valor par de la serie de
 *  Fibonacci menores que kLimit
 *
 *  @param[in] texto_a_codificar es el texto a codificar
 *  @param[in] pass  almacena los contraseña pasada por linea de codigo
 *  @return el codigo encriptado o desencriptado
 */
std::string cripto_uncripto_XOR(std::string texto_a_codificar_xor,std::string pass){ //funcion que encripta o desencripta el archivo en xor
std::string texto = texto_a_codificar_xor;
std::string texto_encriptado;
std::string key = pass;
int contador = 0;
unsigned char letra_xor;
for (auto &element: key){
    element ^= 128;
}
for (int i = 0; i < texto.length(); i++){
    letra_xor = texto[i] ^ key[contador];
    texto_encriptado += letra_xor;
    contador++;
    if(contador >= key.length()){
    contador = 0;
    }
}
return texto_encriptado;
}