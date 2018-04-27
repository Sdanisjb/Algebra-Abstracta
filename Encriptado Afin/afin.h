#ifndef AFIN_H_INCLUDED
#define AFIN_H_INCLUDED
#include <string>

class Afin{
private:
    int a;
    int b;
    bool euclides(int);
    int euclidesExt(int);
public:
    Afin();
    Afin(int,int);
    void imprimir();
    std::string cifrado(std::string);
    std::string descifrado(std::string);
};



#endif // AFIN_H_INCLUDED
