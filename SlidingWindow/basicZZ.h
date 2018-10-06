#ifndef BASICZZ_H_INCLUDED
#define BASICZZ_H_INCLUDED
#include <NTL/ZZ.h>
#include <string>

using namespace NTL;
using namespace std;

//Funciones con Enteros
int md(int,int);
string intToString(long);
//Funciones con ZZ
ZZ mod(ZZ&,ZZ&);
ZZ mcd(ZZ,ZZ);
ZZ invMul(ZZ,ZZ);
ZZ expMod(ZZ&,ZZ&,ZZ&);
ZZ phiN(ZZ&,ZZ&);
#endif // BASICZZ_H_INCLUDED
