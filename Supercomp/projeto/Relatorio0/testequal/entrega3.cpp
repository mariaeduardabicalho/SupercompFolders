#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <random>
#include <fstream>

struct Object
{
    int value, id, pid;
    bool operator<(Object &a);
};

struct Person
{
    int valuesum=0, id =0;
    std::vector<int> objids;
};

struct solucao {
    std::vector<Person> people; 
    int mms=0;
    int solsvals;
    solucao(int m){
        people.resize(m);
        mms=0;
        
    }
    void calc_mms(){
        mms =people[0].valuesum;
        for(auto &p : people){
            if(p.valuesum<= mms){
                mms=p.valuesum;
            }
        }
    }
};
bool ordfinal (int i,int j) { return (i>j); }

solucao busca_exaustiva( std::vector<Object> &obj,std::vector<Person> &per , solucao &melhor,solucao &atual,long unsigned int io =0,int solsvals=0){
    if(io == (obj.size())){
        atual.calc_mms();
        solsvals++;
        melhor.solsvals=solsvals;
        if(atual.mms >=melhor.mms){
            melhor= atual;
            melhor.solsvals=solsvals;
        }
        
        return melhor;
    }
    // todas as possiveis direcoes do no (ir para cada pessoa)
    
    for (long unsigned int i = 0; i < per.size(); i++){
        

        atual.people[i].valuesum+= obj[io].value;
        atual.people[i].objids.push_back(obj[io].id);
    
        busca_exaustiva(obj,per,melhor, atual, io+1,melhor.solsvals);

        // tira 
        atual.people[i].valuesum-= obj[io].value;
        std::vector<int>::iterator itr = std::find(atual.people[i].objids.begin(), atual.people[i].objids.end(), io);
        int n = std::distance(atual.people[i].objids.begin(), itr);
        atual.people[i].objids.erase(atual.people[i].objids.begin()+ n);

    }
    return melhor;

}
int main()
{
    int N, M;
    std::cin >> N >> M;
    std::vector<struct Object> objects(N);
    std::vector<struct Person> people(M);

    int debug = 0;
    char *DEBUG_VAR = getenv("DEBUG");
    if (DEBUG_VAR != NULL)
    {
        debug = atoi(DEBUG_VAR);
    }

    for (int i = 0; i < N; i++){
        objects[i].id = i;
        std::cin >> objects[i].value ;  
    }

    solucao melhor(M);
    solucao atual(M);

    melhor = busca_exaustiva(objects,people,atual,melhor);
    
    if(debug==1){
        std::cerr<< melhor.solsvals<< "\n";
    }

    // escrver no arquivo

    std::ofstream F("out.txt");
    F <<melhor.mms<< "\n" ;
    F.close();

    // saida terminal
    
    std::cout << melhor.mms << "\n";

    for (int i = 0; i < M; i++)
    {
        std::sort(melhor.people[i].objids.begin(), melhor.people[i].objids.end(),ordfinal); 
        
        for(int b = melhor.people[i].objids.size() -1; b>=0; b--){
            std::cout << melhor.people[i].objids[b] << " " ;
        }

        std::cout << "\n";
    }
    return 0;
}