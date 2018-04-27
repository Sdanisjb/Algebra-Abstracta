#include <iostream>
#include <string>
#include "afin.h"

int main()
{
    std::string mensaje = "Hola como estas";

    //Cifrado
    Afin Afin1;
    mensaje = Afin1.cifrado(mensaje);
    std::cout<<mensaje<<std::endl;
    Afin1.imprimir();

    //Descifrado
    int a,b;
    std::cin>>a>>b;

    Afin Afin2(a,b);
    Afin2.imprimir();
    mensaje = Afin2.descifrado(mensaje);
    std::cout<<mensaje<<std::endl;

    return 0;
}
