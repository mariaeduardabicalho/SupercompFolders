#include <stdio.h>
#include <iostream> 
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

struct Object {   
    int weight;   
    int value;
    int id;
};

bool myfunction (Object a, Object b) { return (a.value>b.value); }
bool myotherfunction (Object a, Object b) { return (a.id<b.id); }



int main(){
    int N, peso_maximo;
    std::cin >> N >> >> peso_maximo;
    std::vector<objeto> objetos(N);
    std::vector<bool> usados(N,false);


    int seed =10;
    char *SEED_VAR = getenv("SEED");
    if (SEED_VAR != NULL){
        seed= atoi(SEED_VAR);
    }

    default_random_engine eng("SEED");
    uniform_int_distribution<double> dist(0,1);

    for (int i = 0; i < n; i++){
        objetos[i].id = i;
        std::cin >> objetos[i].peso >> objetos[i].valor;
    }

    std::sort(objetos.begin(),objetos.end(), myfunction);

    int peso_atual =0;
    int valor_atual=0;
    for auto &obj : objetos){
        double rnd = dist(eng);
        if(peso_atual +obj.peso<= peso_maximo && rnd <=0.75){
            peso_atual+= obj.peso;
            valor_atual += obj.valor;
            usados[0bj.id] = true;

        }
    }

    std::cout << peso_atual << " "<<  valor_atual << " "<< "0";
    std:: cout << "\n";
    sort(finalBackpack.begin(),finalBackpack.end(), myotherfunction);
    for (int i = 0; i < n; i++){
        if(usados[1]){
            std::cout << i <<" "; 
        }
    }








}