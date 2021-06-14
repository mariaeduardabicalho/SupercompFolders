///  Passos:
// Pegar a entrada e 
//avaliar qual mms de cada pessoa 
// Para achar o mms individual é necessario fazer uma analise para todas as pessoas como se o valor dos 
//objetos  fossem  os atribuidos pela pesso a. Ou seja repeditir o numero de pessoas vezes achar o mms 
//para   cada, depois comparar o com a entrada.

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <random>

struct Object
{
    int value, id;
    bool operator<(Object &a)
    {
        return value > a.value;
    }
};

struct Person
{
    int valuesum=0, mms;

    std::vector<int> objids;
    std::vector<int> values;
    

};

bool ordfinal (int i,int j) { return (i>j); }

int main()
{
    int N, M;
    std::cin >> N >> M;
    std::vector<struct Object> objects(N);
    std::vector<struct Person> peoplereal(M);
    std::vector<int> mmss(M);



    // Descobre mms de cada pessoa. Pegando as entradas e fazendo mms de cada uma

    for (int p = 0; p < M; p++){

        std::vector<struct Object> objects(N);
        std::vector<struct Person> people(M);
        for (int i = 0; i < N; i++)
        {
            objects[i].id = i;
            std::cin >> objects[i].value ;
            // std::cout << objects[i].value<< "\n";
        }

        std::sort(objects.begin(), objects.end()); 
        int mp= 0;
        int mms = 0;
        for (int i = 0; i < N; i++)
        {
            people[mp].valuesum+= objects[i].value;
            people[mp].objids.push_back(objects[i].id);
            if(mp==M-1){
                mp=0;
            }
            else{
                mp++;
            }
        }
        
        peoplereal[p].mms=people[M-1].valuesum ;
    }

    bool sim = false;
    for (int p = 0; p < M; p++){

        std::cin >> mmss[p];

        if (mmss[p] >= peoplereal[p].mms){
            std::cerr << mmss[p]<< "  " << peoplereal[p].mms << "\n";
            sim= true;
        }
        else{
            sim = false;
        }

    }

    if(sim){
        std::cout << "sim" << "\n";
    }
    else{
        std::cout << "nao" << "\n";
    }






    // // for (int i = 0; i < M; i++)
    // {
    //     std::sort(people[i].objids.begin(), people[i].objids.end(),ordfinal); 
        
    //     for(int b = people[i].objids.size() -1; b>=0; b--){
    //         std::cout << people[i].objids[b] << " " ;
    //     }

    //     std::cout << "\n";
    // }
    

    return 0;
} 