#include <iostream>
#include <string>
#include "encript.h"


std::string alfabeto = "abcdefghijklmnopqrstuvwxyz ";

int main()
{
    std::string mensaje;
    std::cout<<"Ingrese su mensaje:"<<std::endl;
    getline(std::cin,mensaje);
    int clave;
    std::cout<<"Ingrese su clave:"<<std::endl;
    std::cin>>clave;
    //std::string traspuesta= trasponer(mensaje,alfabeto);
    mensaje= trasponer(mensaje,alfabeto);
    std::cout<<mensaje<<std::endl;
    //std::string cifrado= zigzag(traspuesta,clave);
    mensaje= zigzag(mensaje,clave);
    std::cout<<mensaje<<std::endl;
    //std::string descifrado = zigzaginverse(cifrado,clave);
    mensaje = zigzaginverse(mensaje,clave);
    std::cout<<mensaje<<std::endl;
    //std::string mensaje2 = trasponer(descifrado,alfabeto);
    mensaje = trasponer(mensaje,alfabeto);
    std::cout<<mensaje<<std::endl;
    return 0;
}
