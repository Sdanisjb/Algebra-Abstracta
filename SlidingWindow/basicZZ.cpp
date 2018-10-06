#include "basicZZ.h"
#include <NTL/ZZ.h>
#include <iostream>
#include <sstream>

using namespace NTL;

//operaciones con enteros
int md(int a,int b){
    int q= a/b;
    int r = a-(q*b);
    if(r<0){
        r=b+r;
    }
    return r;
}

string intToString(long a){
    stringstream buffer;
    buffer << a;
    return buffer.str();
}

//operaciones con zz
ZZ mod(ZZ &a,ZZ &b){
    ZZ q = a/b;
    ZZ r = a - (q*b);
    if(r<0){
        r = b + r;
    }
    return r;
}

// a necesariamente tiene que ser mayor a b
ZZ mcd(ZZ a,ZZ b){
    ZZ g (1);
    ZZ t;
    ZZ dos(2);
    while(mod(a,dos)==0 && mod(b,dos)==0){
        a>>=1;
        b>>=1;
        g<<=1;
    }
    while (a!=0){
        while(mod(a,dos)==0){
            a>>=1;
        }
        while(mod(b,dos)==0){
            b>>=1;
        }
        if(a>=b){
            t = a-b;
            a = t;
        }
        else{
            t = b-a;
            b = t;
        }
    }

    return g*b;
}

ZZ invMul(ZZ a,ZZ b){
    ZZ b0 = b, t, q;
	ZZ x0(0), x1(1);
	ZZ uno(1);
	if (b==uno) return uno;
	while (a > uno) {
		q = a / b;
		t = b, b = mod(a,b), a = t;
		t = x0, x0 = x1 - (q * x0), x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}


ZZ expMod(ZZ& base,ZZ& exp,ZZ& n)
{
   if (exp == 0) return ZZ(1);

   long k = NumBits(exp);

   ZZ res(1);

   for (long i = k-1; i >= 0; i--) {
      res = (res*res);
      res = mod(res,n);
      if (bit(exp, i)){
        res = res*base;
        res = mod(res,n);

      }
   }

   return mod(res,n);
}

ZZ phiN(ZZ& a,ZZ& b){
    return (a-1)*(b-1);
}

