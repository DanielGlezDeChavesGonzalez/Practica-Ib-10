#ifndef funcione_h_included
#define funciones_h_included
#include <iostream>


std::string cripto_uncripto_cesar (std::string texto_a_codificar_cesar, char* argv[]); //define la funcion cesar

void ayudas_programa (int argc,char* argv[]); //define la funcion de correcta ejecucion

const std::string texto_ayuda ="Este programa codifica y descodifica, de dos metodos diferentes a elegir, archivos dados en linea de comandos"; //define y describe la constante ayuda

std::string cripto_uncripto_XOR(std::string texto_a_codificar_xor,std::string pass); //define la funcion xor 

#endif