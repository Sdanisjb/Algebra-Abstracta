#include "encript.h"
#include <string>
#include <iostream>
#include <algorithm>


std::string firstSpiral(std::string mensaje, int clave){
    int tamanio=clave*clave;
    std::string cifrado(tamanio,'0');
    int nsaltos = clave;
    int corrimiento = clave-1;
    int iterador=0;
    int pos = (clave-1)-clave;

    bool adelante = true;
    for(int i=0;i<clave/2;i++){
        if(adelante){
            for(int i=0;i<nsaltos;i++){
                pos+=clave;
                cifrado[pos]=mensaje[iterador];
                iterador++;
            }
            nsaltos--;

            for(int i=0;i<corrimiento;i++){
                pos--;
                cifrado[pos]=mensaje[iterador];
                iterador++;
            }
            corrimiento--;
            adelante=false;
        }
        if(!adelante){
            for(int i=0;i<nsaltos;i++){
                pos-=clave;
                cifrado[pos]=mensaje[iterador];
                iterador++;
            }
            nsaltos--;
            for(int i=0;i<corrimiento;i++){
                pos++;
                cifrado[pos]=mensaje[iterador];
                iterador++;
            }
            corrimiento--;
            adelante=true;
        }

    }

    return cifrado;
}

std::string secondSpiral(std::string mensaje,int clave){
    int tamanio=clave*clave;
    int iterador = 0;
    std::string cifrado(tamanio,'0');
    int nsaltos = clave;
    int corrimiento = clave-1;
    int fila = clave*4;
    iterador+=fila-1;
    int pos = (clave-1)-clave;

    bool adelante = true;
    for(int i=0;i<clave/2;i++){
        if(adelante){
            for(int i=0;i<nsaltos;i++){
                pos+=clave;
                cifrado[pos]=mensaje[iterador];
                iterador--;
            }
            nsaltos--;

            for(int i=0;i<corrimiento;i++){
                pos--;
                cifrado[pos]=mensaje[iterador];
                iterador--;
            }
            corrimiento--;
            adelante=false;
        }
        if(!adelante){
            for(int i=0;i<nsaltos;i++){
                pos-=clave;
                cifrado[pos]=mensaje[iterador];
                iterador--;
            }
            nsaltos--;
            for(int i=0;i<corrimiento;i++){
                pos++;
                cifrado[pos]=mensaje[iterador];
                iterador--;
            }
            corrimiento--;
            adelante=true;
        }

    }
    if(clave%2==0){
        return cifrado;
    }
    else{
        std::reverse(cifrado.begin(),cifrado.end());
        return cifrado;
    }
}

std::string secondN(std::string mensaje,int clave){
    std::string cifrado;
    int patron1 = clave-1;
    int patron2= 0;
    for(int i=clave-1;i>=0;i--){
        int pos=i;
        bool par=false;
        bool impar=true;
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

std::string firstN(std::string mensaje, int clave){
    std::string cifrado;
    int patron1 = clave-1;
    int patron2= 0;
    int inicio;
    if(clave%2==0){
        inicio=-((clave/2)-1);

    }
    else{
        inicio=-(clave/2);

    }
    for(int i=inicio;i<(clave+inicio);i++){
        int pos=i;
        bool par=true;
        bool impar=false;
        int aux=-1;
        while(pos<mensaje.length() || pos<0){
            if((aux!=pos) && (pos>=0)){
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

std::string reconcatenacion(std::string espiral1,std::string n1,std::string espiral2,std::string n2,int clave){
    std::string cifrado;
    int inicio;
    if(clave%2==0){
        inicio=((clave/2)-1);

    }
    else{
        inicio=(clave/2);

    }
    for(int i=0;i<clave;i++){
        std::string uno = espiral1.substr(clave*i,clave);
        std::string dos;
        if(i<inicio){
            dos = n1.substr(i,1);
        }
        else if(i==clave-1){
            dos = n1.substr(((clave-1)*3)-1,2);
        }
        else{
            dos = n1.substr(i,3);
        }
    }
}




