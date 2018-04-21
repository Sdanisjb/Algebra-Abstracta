#include <iostream>
#include <string>
#include "encript.h"

using namespace std;


int main()
{
    int clave = 5;

    //string mensaje="abcdefghijklmnop012345678abcdefghijklmnop0123456789";
    string mensaje ="Recibir dos strings por consola. Dividir el primer string usando el segundo como separador de elementos. Imprimir cada uno de los substrings en una nueva linea.";
    string cifradoTotal;
    int espiral = clave*clave;
    int k;
    if(clave%2==0){
        k=(clave/2)-1;
    }
    else{
        k=(clave/2);
    }
    int n1 = ((clave-1)*3)+1-k;
    int n2 = ((clave-1)*3)+1;


    //Mensajes
    string mensaje1 = mensaje.substr(0,espiral);
    string mensaje2 = mensaje.substr(espiral,n1);
    string mensaje3 = mensaje.substr(espiral+n1,espiral);
    string mensaje4 = mensaje.substr(espiral+espiral+n1,n2);
    //Cifrados
    string cifrado = firstSpiral(mensaje1,clave);
    string cifrado2 = firstN(mensaje2,clave);
    string cifrado3= secondSpiral(mensaje3,clave);
    string cifrado4= secondN(mensaje4,clave);

    //Descifrados;
    string descifrado = fSpiralD(cifrado,clave);
    string descifrado2 = fnD(cifrado2,clave);
    string descifrado3 = sSpiralD(cifrado3,clave);
    string descifrado4 = snD(cifrado4,clave);

    //Reconcatenacion de los cifrados
    int hitos[clave];
    generatingHitos(clave,hitos);

    cifradoTotal = reconcatenate(cifradoTotal,cifrado,0,hitos,clave);
    cifradoTotal = reconcatenate(cifradoTotal,cifrado2,1,hitos,clave);
    cifradoTotal = reconcatenate(cifradoTotal,cifrado3,2,hitos,clave);
    cifradoTotal = reconcatenate(cifradoTotal,cifrado4,3,hitos,clave);

    cout<<cifradoTotal<<endl;

    return 0;
}
