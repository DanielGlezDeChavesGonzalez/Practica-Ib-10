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
 ///exit

#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include "funciones_cripto.h"
#include <cstring>
#include <fstream>

/** Main function
 *  @param[in] argc Number of command line parameters
 *  @param[in] argv Vector containing (char*) the parameters
 */

int main(int argc,char* argv[]){
ayudas_programa(argc,argv); //funcion para verificar si esta bien ejecutado el programa
std::string archivo1 = argv[1];
std::string archivo2 = argv[2];
std::ifstream in_txt (archivo1.c_str()); //abre el archivo 1
std::ofstream out_txt (archivo2.c_str()); //abre el archivo 2
std::string line;
std::string signo= argv[5]; //guarda el signo de encriptacion
std::string newline;
std::string metodo = argv[3]; //guarda el metodo de encriptacion
std::string file_lines;
while(std::getline(in_txt, line)){ //archiva todas las lineas del archivo
    file_lines += line;
    file_lines.push_back('\n');
}
if(metodo=="cesar"){  //comprueba si el metodo de encriptacion es cesar
newline = cripto_uncripto_cesar (file_lines,argv); //encripta o desencripta en cesar
newline.pop_back();
out_txt<<newline;
    if(signo== "+"){
    std::cout<<"Codigo encriptado, metodo cesar, correctamente en archivo: "<<argv[2]<<std::endl;
    }
    if(signo== "-"){
    std::cout<<"Codigo desencriptado, metodo cesar, correctamente en archivo: "<<argv[2]<<std::endl;
    }
return 0;
}
if(metodo=="xor"){  //comprueba si el metodo de encriptacion es xor
std::string pass = argv[4];
newline = cripto_uncripto_XOR (file_lines,pass); //funcion que encripta o desencripta en xor
newline.pop_back();
    if(signo=="+"){
    std::cout<<"Codigo encriptado, metodo xor, correctamente en archivo: "<<argv[2]<<std::endl;
    out_txt<<newline;
    }
    if(signo=="-"){
    std::cout<<"Codigo desencriptado, metodo xor, correctamente en archivo: "<<argv[2]<<std::endl;
    out_txt<<newline;
    }
return 0; 
}
if(metodo!="xor" && metodo!="cesar"){  //comprueba si el metodo de encriptacion no es ni cesar ni xor
std::cout<<"Metodo de encriptacion incorrecto, por favor escriba "<<argv[0]<<" --help para más ayuda" <<std::endl;
return 0;
}
return 0;
}