#include <iostream>
#include <vector>
#include <NTL/ZZ.h>
#include <chrono>
#include "basicZZ.h"

using namespace std;
using namespace NTL;

//K sera el tamaño de nuestra ventana, por defecto
//sera 3
ZZ SWexp(ZZ base, ZZ exponent, ZZ module, long k=3){
    //Usaremos este auxiliar siempre
    //que lo necesitemos
    ZZ aux;

    //Precomputacion
    ZZ arraux[(((2<<(k-1))*2)+1)];
    arraux[0]= base;
    aux = base*base;
    arraux[1]= mod(aux,module);
    for(int i=1;i<=((2<<(k-1))-1);i++){
        arraux[2*i] = arraux[(2*i)-2] * arraux[1];
    }
    //Variables
    ZZ A(INIT_VAL,"1");
    long i = NumBits(exponent)-1;

    //Exponenciacion en si
    //Variable auxiliar para
    // hallar la cadena mas larga
    while(i>=0){
        vector<bool> cadena;
        if(!bit(exponent,i)){
            A*=A;
            A = mod(A,module);
            i--;
        }
        else{
            //Encontrar la cadena de bits mas larga
            for(int j=0;j<=k-1;j++){
                cadena.push_back(bit(exponent,i));
                i--;
            }
            while(!cadena[cadena.size()-1]){
                cadena.pop_back();
                i++;
            }
            //Pasarlo a entero
            int pow = 1;
            int auxiliar=0;
            for(int j=0;j<cadena.size();j++){
                auxiliar+=(cadena[j]*pow);
                pow<<=1;
            }

            //Potenciarlo
            for(int j=0;j<(2<<(cadena.size()+1));j++){
                A*=A;
                A = mod(A,module);
            }
            A*= arraux[auxiliar-1];
            A = mod(A,module);
        }
    }
    return A;
}

int main()
{

    cout<<SWexp(ZZ(2),ZZ(1),ZZ(4));

    return 0;
}
