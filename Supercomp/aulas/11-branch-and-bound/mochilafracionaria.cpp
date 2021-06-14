#include <stdio.h>
#include <iostream> 
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>


struct objeto{
    double  peso,valor;
    int id;
    double fracao=0;
    
    bool operator<(objeto &a)
    {
        return valor/peso < a.valor/a.peso; 
    }
     
};

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

    std::sort(objetos.begin(), objetos.end()); 

    double peso_final= 0;
    for(int i = 0; i<n; i++){

        if(peso_final+objetos[i].peso< w){
            objetos[i].fracao=1;
            peso_final+= objetos[i].fracao *objetos[i].peso;
            usados[i]=true;
        }
        else if (peso_final<w){
            
            objetos[i].fracao =(w-peso_final)/ objetos[i].peso;
            peso_final+= objetos[i].fracao * objetos[i].peso;
            
            
        }
        
    
    }

    std::cout<< peso_final<<"\n";

    for(int i = 0; i<n; i++){
        std::cout << objetos[i].fracao << "\n";
    }
    
}

