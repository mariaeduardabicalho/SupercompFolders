// Utilizei uma idei parecida com a da pergunta anterior, ordenei os valores de objetos 
//de cada pessoa e fui  colocando ate os objetos acabarem

// por algum motivo não esta rodando todas as vezes no for dos objetos entao cada pessoa so 
//ta ficando  cm um vou debugar se der  tempo



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

    int v;

    // coloco os valores dos objetos no vetor de objeyos que cada pessoa tem
    // mudei a forma que faziamos antes para em vez de ter domente 1 vetor de objs
    // cada pessoa tem um ems sua struct

    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++)
        {
            
            objects[j].id = j;
            std::cin >> objects[j].value ;

            people[i].obvalues.push_back(objects[j]);

           
        }
    }

    for (int i = 0; i < M; i++){
        
        std::sort(people[i].obvalues.begin(), people[i].obvalues.end()); 
        for(int j = 0; j < N; j++){
            // std::cerr << people[i].obvalues[j].id<< "  "  ;
            
        }
        // std::cerr << "\n";

    }

    int p=0;
    // col
    for (int i = 0; i < N; i++){

        for (int k = 0; k < N; k++){
            if( choseobs[people[p].obvalues[k].id] == false ){
                choseobs[people[p].obvalues[k].id] = true;
                people[p].valuesum += people[p].obvalues[k].value;
                people[p].objids.push_back(people[p].obvalues[k].id);
                // std::cerr << p << "\n ";
                k=0 ;

                if( p == M-1){
                    // std::cerr << "cheguei fim p " << "\n ";
                    p=0;
                }
                else{
                    p++;
                }  
            }
        }
        if( p == M-1){
            p=0;
        }
        else{
            p++;
        }

        // std::cerr << i << "\n";

    }

    //checar qual mmsp de people final
    Person mmspFinal= people[0];
    for (int i = 1; i < M; i++){
        if(people[i].valuesum <= mmspFinal.valuesum ){
            mmspFinal = people[i];
        }
    }


    std::cout << mmspFinal.valuesum << "\n";
    for (int i = 0; i < M; i++)
    {
        std::sort(people[i].objids.begin(), people[i].objids.end(),ordfinal); 
        
        for(int b = people[i].objids.size() -1; b>=0; b--){
            std::cout << people[i].objids[b] << " " ;
        }

        std::cout << "\n";
    

    }
    







}