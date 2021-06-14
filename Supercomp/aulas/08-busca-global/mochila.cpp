#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <random>

struct Object
{
    int peso, valor, id;

};

void mochila(p,v,n,c,i,usados,melhor){

    if (i == n){
        if(usados.valor >melhor.valor){
            melhor = usados;
        }
        return 0;
    }

    int comI = mochila(p,v,n,c,i+1,usados,melhor)+v[i];

    if (c-p[i]>= 0){
        usados[i]= true;
        int semI= mochila(p,v,n,c-p[i],i+1,usados,melhor) + v[i];
    }

    return std::max(comI,semI)

}

int main(){

}