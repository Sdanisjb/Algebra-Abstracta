#include <iostream>
#include <string>
#include "encript.h"

using namespace std;


int main()
{
    int clave = 4;

    string mensaje="abcdefghijklmnopabcdefghiabcdefghijklmnopabcdefghij";
    int espiral = clave*clave;
    int n1 = (clave-1)*3;
    int n2 = ((clave-1)*3)+1;

    string mensaje1 = mensaje.substr(0,espiral);
    cout<<mensaje1<<endl;
    string mensaje2 = mensaje.substr(espiral,n1);
    cout<<mensaje2<<endl;
    string mensaje3 = mensaje.substr(espiral+n1,espiral);
    cout<<mensaje3<<endl;
    string mensaje4 = mensaje.substr(espiral+espiral+n1,n2);
    cout<<mensaje4<<endl;

    string cifrado = firstSpiral(mensaje1,clave);
    cout<<cifrado<<endl;
    string cifrado2 = firstN(mensaje2,clave);
    cout<<cifrado2<<endl;
    string cifrado3= secondSpiral(mensaje3,clave);
    cout<<cifrado3<<endl;
    string cifrado4= secondN(mensaje4,clave);
    cout<<cifrado4<<endl;



    return 0;
}
