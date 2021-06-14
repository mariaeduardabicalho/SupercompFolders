
// Tarefa 3 corrigida funcionando
// Explicacao previa no arq tarefa3.cpp


#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <random>

struct Object
{
    int id, pid, value;
    bool operator<(Object &a)
    {
        return value > a.value;
    }
};

// creiei umalista de  s
struct Person
{
    int valuesum=0, id;
    std::vector<int> objids;
    std::vector<struct Object> obvalues;

};

bool ordfinal (int i,int j) { return (i>j); }

int main()
{
    int N, M;
    std::cin >> N >> M;
    std::vector<bool> choseobs(N, false);
    std::vector<struct Person> people(M);
    std::vector<struct Object> objects(N);
    std::vector<int> mmss(M);


    int v;

    // coloco os valores dos objetos no vetor de objeyos que cada pessoa tem
    // mudei a forma que faziamos antes para em vez de ter domente 1 vetor de objs
    // cada pessoa tem um ems sua struct

    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++)
        {
            
            objects[i].id = i;
            std::cin >> objects[i].value ;

            people[i].obvalues.push_back(objects[i]);


           
        }
    }


    bool sim = true;
    for (int p = 0; p < M; p++){

        std::cin >> mmss[p];
    }

    int idpe;
    for (int i = 0; i < N; i++){

        std::cin >> idpe;
        people[idpe].objids.push_back(i);
        people[idpe].valuesum +=people[idpe].obvalues[i].value;

        std::cerr << "v"<<"\n";
        
    }

    for (int i = 0; i < M ; i++){

        if(people[i].valuesum >= mmss[i]){
            std::cerr << people[i].valuesum <<  "  "<<  mmss[i]<< "TRUE" <<"\n";
            sim= true & sim;
        }
        else{
            std::cerr  << people[i].valuesum  << "  " << mmss[i]<<"false"<<"\n";
            sim = false & sim;
        }

    }

     if(sim){
        std::cout << "sim" << "\n";
    }
    else{
        std::cout << "nao" << "\n";
    }



     
    

    // //checar qual mmsp de people final
    // Person mmspFinal= people[0];
    // for (int i = 1; i < M; i++){
    //     if(people[i].valuesum <= mmspFinal.valuesum ){
    //         mmspFinal = people[i];
    //     }
    // }

    // std::cout << mmspFinal.valuesum << "\n";
    // for (int i = 0; i < M; i++)
    // {
    //     std::sort(people[i].objids.begin(), people[i].objids.end(),ordfinal); 
        
    //     for(int b = people[i].objids.size() -1; b>=0; b--){
    //         std::cout << people[i].objids[b] << " " ;
    //     }

    //     std::cout << "\n";
    // }
    





    return 0;

}