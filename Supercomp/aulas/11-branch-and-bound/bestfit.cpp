#include <stdio.h>
#include <iostream> 
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>

/// igual na func mas bound é mochila fracionaria

struct objeto{
    double valor, peso;
    int id;
    int fracao= valor/peso;
    
    bool operator<(objeto &a)
    {
        return valor/peso > a.valor/a.peso; 
    }
     
};

struct solucao {
    std::vector<bool> usado; 
    int peso, valor;
    solucao(int n){
        usado.resize(n,false);
        valor=peso=0;
    }
};



void busca_exaustiva( std::vector<objeto> &obj, int c, solucao &melhor, solucao &atual, long unsigned int i =0){
    
    if(i== obj.size()){
        // num_leafs++;
        if(atual.valor>melhor.valor){
            melhor= atual;
            // num_copy++;
        }
        return;
    }

    

    if((obj[i].peso)<=c){
        atual.usado[i]=true;
        atual.valor+=obj[i].valor;
        atual.peso+=obj[i].peso;

        busca_exaustiva(obj,c, melhor, atual, i+1);
        atual.usado[i]=false;
        atual.valor-=obj[i].valor;
        atual.peso-=obj[i].peso;
    }

    atual.usado[i]=false;
    busca_exaustiva(obj,c,melhor,atual,i+1);
}

int main(){
    int n, w;
    std::cin >> n >> w;
    std::vector<struct objeto> objetos(n);
    std::vector<bool> usados(n, false);

    for (int i = 0; i < n; i++)
    {
        objetos[i].id = i;
        std::cin >> objetos[i].peso >> objetos[i].valor;  
    }

    solucao melhor(n);
    solucao atual(n);

    std::sort(objetos.begin(), objetos.end()); 

    busca_exaustiva(objetos,w,melhor,atual);

    std::cout << melhor.peso << "" << melhor.valor << "1" << "\n";

    for( int i = 0; i<n; i++){
        if(melhor.usado[i]){
            std::cout << i << " " << "\n";
        }
    }
}


