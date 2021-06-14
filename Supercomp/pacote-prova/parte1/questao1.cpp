/// Pergunta inicial:
///  N pacotes , N fornecedores, distancia
// Eu quero  mininimizar a relação preçofornecedor vezes dustancia para entrega
// Um forma de resolver seria pegar as distancias mais longas e colocar os custos  menores
// Dessa forma,  poderia ordenar os preços dos menores para os maiores e as distancias das maiores
// para as menores e ir colocando cada um.



// Pergunta 2 

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <random>

struct pacote
{
    int id;
    float dist;
    bool operator<(pacote &a)
    {
        return dist > a.dist;
    }

};

struct forne
{
    int id;
    float preco;
    bool operator<(forne &a)
    {
        return preco < a.preco;
    }
};


// bool ordmaior (int i,int j) { return (i>j); }

// bool ordmenor (int i,int j) { return (i<j); }

int main(){
    int n;
    std::cin >>n;

    std::vector<struct pacote> pacs(n);
    std::vector<struct forne> fornes(n);

    std::vector<float> final(n);

    float c =0 ;
    

    float v;
    for (int i = 0; i < n; i++){

        pacs[i].id = i;
        std::cin >> pacs[i].dist ;
    }

    for (int i = 0; i < n; i++){
        fornes[i].id = i;
        std::cin >> fornes[i].preco ;
    }


    std::sort(pacs.begin(), pacs.end()); 
    std::sort(fornes.begin(), fornes.end()); 

    for (int i = 0; i < n; i++){
        c+= pacs[i].dist * fornes[i].preco;
        final[pacs[i].id] = fornes[i].id;
    }




     std::cout << c << "\n";

    for (int i = 0; i < n; i++){

        std::cout << final[i]  << "  \n" ;
        
    }

    // for (int i = 0; i < n; i++){

    //     std::cout << pacs[i].dist  << "  \n" ;
    //     std::cout << fornes[i].preco << "\n" ;
    // }

   

}