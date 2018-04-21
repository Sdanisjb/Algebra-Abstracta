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
    int pos = -1;
    int nVueltas;
    if(clave%2==0){
        nVueltas = clave/2;
    }
    else{
        nVueltas = (clave/2)+1;
    }

    bool adelante = true;
    for(int i=0;i<nVueltas;i++){
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
    int fila = clave*clave;
    iterador+=fila-1;
    int pos = -1;
    int nVueltas;
    if(clave%2==0){
        nVueltas = clave/2;
    }
    else{
        nVueltas = (clave/2)+1;
    }

    bool adelante = true;
    for(int i=0;i<nVueltas;i++){
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




std::string fSpiralD(std::string cifrado,int clave){
    int tamanio=clave*clave;
    std::string mensaje;
    int nsaltos = clave;
    int corrimiento = clave-1;
    int iterador=0;
    int pos = (clave-1)-clave;
    int nVueltas;
    if(clave%2==0){
        nVueltas = clave/2;
    }
    else{
        nVueltas = (clave/2)+1;
    }

    bool adelante = true;
    for(int i=0;i<nVueltas;i++){
        if(adelante){
            for(int i=0;i<nsaltos;i++){
                pos+=clave;
                mensaje+=cifrado[pos];
                iterador++;
            }
            nsaltos--;

            for(int i=0;i<corrimiento;i++){
                pos--;
                mensaje+=cifrado[pos];
                iterador++;
            }
            corrimiento--;
            adelante=false;
        }
        if(!adelante){
            for(int i=0;i<nsaltos;i++){
                pos-=clave;
                mensaje+=cifrado[pos];
                iterador++;
            }
            nsaltos--;
            for(int i=0;i<corrimiento;i++){
                pos++;
                mensaje+=cifrado[pos];
                iterador++;
            }
            corrimiento--;
            adelante=true;
        }

    }

    return mensaje;
}


std::string fnD(std::string cifrado, int clave){
    std::string mensaje;
    mensaje.resize(cifrado.length());
    int patron1 = clave-1;
    int patron2= 0;
    int inicio;
    int it =0;
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
                mensaje[pos] = cifrado[it];
                it++;
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
    return mensaje;
}


std::string sSpiralD(std::string cifrado,int clave){
    int tamanio=clave*clave;
    int iterador = 0;
    std::string mensaje;

    int nsaltos = clave;
    int corrimiento = clave-1;
    int fila = clave*4;
    iterador+=fila-1;
    int pos = -1;
    int nVueltas;
    if(clave%2==0){
        nVueltas = clave/2;
    }
    else{
        nVueltas = (clave/2)+1;
    }
    if(clave%2==1){
        std::reverse(cifrado.begin(),cifrado.end());
    }

    bool adelante = true;
    for(int i=0;i<nVueltas;i++){
        if(adelante){
            for(int i=0;i<nsaltos;i++){
                pos+=clave;
                mensaje+=cifrado[pos];
                iterador--;
            }
            nsaltos--;

            for(int i=0;i<corrimiento;i++){
                pos--;
                mensaje+=cifrado[pos];
                iterador--;
            }
            corrimiento--;
            adelante=false;
        }
        if(!adelante){
            for(int i=0;i<nsaltos;i++){
                pos-=clave;
                mensaje+=cifrado[pos];
                iterador--;
            }
            nsaltos--;
            for(int i=0;i<corrimiento;i++){
                pos++;
                mensaje+=cifrado[pos];;
                iterador--;
            }
            corrimiento--;
            adelante=true;
        }

    }

    std::reverse(mensaje.begin(),mensaje.end());
    return mensaje;

}

std::string snD(std::string cifrado,int clave){
    std::string mensaje;
    mensaje.resize(cifrado.length());
    int patron1 = clave-1;
    int patron2= 0;
    int iterador = 0;
    for(int i=clave-1;i>=0;i--){
        int pos=i;
        bool par=false;
        bool impar=true;
        int aux=-1;
        while(pos<mensaje.length()){
            if(aux!=pos){
                mensaje[pos]=cifrado[iterador];
                iterador++;
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
    return mensaje;
}


void generatingHitos(int clave,int hitos[]){
    for(int i=0;i<clave;i++){
        hitos[i] = 0;
    }
}

void refreshHitos(int pos,int hitos[],int n,int clave){
    for(pos;pos<clave;pos++){
        hitos[pos]+=n;
    }
}
void print(int hitos[],int clave){
    for(int i =0;i<clave;i++){
        std::cout<<hitos[i]<<" ";
    }
    std::cout<<std::endl;
}


std::string reconcatenate(std::string full, std::string partial, int type, int hitos[], int clave){
    if(type==0 || type ==2){
        int inicio = 0;
        for(int i=0;i<clave;i++){
            std::string aux = partial.substr(inicio,clave);
            full.insert(hitos[i],aux);
            inicio+=clave;
            refreshHitos(i,hitos,clave,clave);
        }
        return full;
    }

    else if(type==1){
        int inicio;
        std::string aux;
        if(clave%2==0){
        inicio=-((clave/2)-1);
        }
        else{
            inicio=-(clave/2);
        }
        int start=0;
        int posH = 0;
        for(int i=inicio;i<(clave+inicio);i++){

            if(i==inicio){
                aux=partial.substr(start,1);
                full.insert(hitos[posH],aux);
                start++;
                refreshHitos(posH,hitos,1,clave);
                posH++;
            }
            else if(i<0 || i==(clave+inicio-1)){
                aux = partial.substr(start,2);
                full.insert(hitos[posH],aux);
                start+=2;
                refreshHitos(posH,hitos,2,clave);
                posH++;
            }
            else{
                aux = partial.substr(start,3);
                full.insert(hitos[posH],aux);
                start+=3;
                refreshHitos(posH,hitos,3,clave);
                posH++;
            }


        }
        return full;
    }

    else if(type ==3){
        int inicio = 0;
        std::string aux;
        for(int i=0;i<clave;i++){
            if(i==0 || i==(clave-1)){
                aux = partial.substr(inicio,2);
                full.insert(hitos[i],aux);
                inicio+=2;
                refreshHitos(i,hitos,2,clave);
            }
            else{
                aux=partial.substr(inicio,3);
                full.insert(hitos[i],aux);
                inicio+=3;
                refreshHitos(i,hitos,3,clave);
            }
        }
        return full;
    }


}









