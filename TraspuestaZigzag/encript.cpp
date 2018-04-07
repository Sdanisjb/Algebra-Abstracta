#include "encript.h"
#include <iostream>


std::string trasponer(std::string mensaje, std::string alfabeto){
    std::string cifrado;
    for(int i=0;i<mensaje.length();i++){
        for(int j=0;j<alfabeto.length();j++){
            if(mensaje[i]==alfabeto[j]){
                cifrado=cifrado+alfabeto[alfabeto.length()-1-j];
            }
        }
    }
    return cifrado;
}


std::string zigzag(std::string mensaje, int clave){
    std::string cifrado;
    int patron1 = clave-1;
    int patron2= 0;
    while((mensaje.length()%(clave-1))!=1){
        mensaje= mensaje + "a";
    }
    for(int i=0;i<clave;i++){
        int pos=i;
        bool par=true;
        bool impar=false;
        int aux=-1;
        while(pos<mensaje.length()){
            if(aux!=pos){
                cifrado = cifrado + mensaje[pos];

            }
            aux=pos;
            if(par){
                pos=pos+(2*patron1);
                par=false;
                impar=true;



            }
            else if(impar){
                pos=pos+(2*patron2);
                par=true;
                impar=false;

            }

        }
        patron1--;
        patron2++;
    }
    return cifrado;

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
std::string zigzaginverse(std::string cifrado,int clave){
    std::string descifrado;
    descifrado.resize(cifrado.length());
    int patron1=clave-1;
    int patron2=0;
    int pos=0;
    int aux=-1;
    int it=0;

    for(int i=0;i<clave;i++){
        pos=i;
        bool par=true;
        bool impar=true;
        while(pos<cifrado.length()){
            if(aux!=pos){
                descifrado[pos]=cifrado[it];
                it++;
            }
            aux=pos;
            if(par){
                pos = pos+(patron1*2);
                par=false;
                impar=true;
            }
            else if(impar){
                pos = pos+(patron2*2);
                par=true;
                impar=false;
            }

        }
        patron1--;
        patron2++;

    }

    return descifrado;
}



