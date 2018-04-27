#include "afin.h"
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>

std::string alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ.,_-0123456789";

//Algoritmo de Euclides para verificar si son primos entre si
//Retorna un booleano que dice si el mcd es 1
bool Afin::euclides(int b){
    int q;
    int a = alfabeto.length();
    while(b>0){
        q = a/b;
        int r = a - (q*b);
        a = b;
        b = r;
    }
    if(a == 1){
        return true;
    }
    else{
        return false;
    }
}


//Algoritmo de Euclides Extendido pero que solo calcula la inversa del primer numero
int Afin::euclidesExt(int b){
    int a = alfabeto.length();
    int q;
    int s;
    int r;
    int s1 = 0;
    int s2 = 1;
    while(b>0){
        q = a/b;
        //Actualizando A y B
        r = a - q*b;
        a = b;
        b = r;
        //Actualizando s's
        s = s1 - (q*s2);
        s1 = s2;
        s2 = s;
    }
    if(s1<0){
        s1 = alfabeto.length() + s1;
        //std::cout<<s1<<std::endl;
        return s1;
    }
    else{
        //std::cout<<s1<<std::endl;
        return s1;
    }
}

void Afin::imprimir(){
    std::cout<<"Clave publica A : "<<a<<std::endl;
    std::cout<<"Clave publica B : "<<b<<std::endl;

}


//Constructor sin parametros
//Valores aleatorios
//mcd(a, alfabetotamaño) tiene que ser 1
//b tiene que ser cualquier numero que se halle dentro del rango
// [0,alfabeto)
Afin::Afin(){
    do{
        srand(time(NULL));
        a = rand() % alfabeto.length();
    }while(!euclides(a));



    b = rand() % alfabeto.length();
}


//Constructor con parametros
Afin::Afin(int a, int b):
    a(a),
    b(b)
{};


std::string Afin::cifrado(std::string mensaje){
    std::string cifrado;
    int pos;
    for(int i=0;i<mensaje.length();i++){
        pos = alfabeto.find(mensaje[i]);
        pos = pos * a;
        pos = pos + b;
        pos = pos%alfabeto.length();
        cifrado+=alfabeto[pos];

    }
    return cifrado;
}


std::string Afin::descifrado(std::string cifrado){
    std::string mensaje;
    int inv = euclidesExt(a);
    //std::cout<<inv<<std::endl;
    int pos;
    for(int i=0;i<cifrado.length();i++){
        pos = alfabeto.find(cifrado[i]);
        pos = pos - b;
        if(pos<0){
            pos = alfabeto.length()+pos;
        }
        pos = pos*inv;
        pos = pos%alfabeto.length();
        mensaje+=alfabeto[pos];
    }
    return mensaje;

}










