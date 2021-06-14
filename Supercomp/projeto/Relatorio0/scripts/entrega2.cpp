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
    bool operator<(Object &a)
    {
        return value > a.value;
    }
};
struct Person
{
    int valuesum=0, id =0;
    std::vector<int> objids;
};
bool ordfinal (int i,int j) { return (i>j); }

int main()
{
    int N, M;
    std::cin >> N >> M;
    std::vector<struct Object> objectsFinal(N);
    std::vector<struct Person> peopleFinal(M);

    int seed = 0;
    char *SEED_VAR = getenv("SEED");
    if (SEED_VAR != NULL)
    {
        seed = atoi(SEED_VAR);
    }
    int iter = 100000;
    char *ITER_VAR = getenv("ITER");
    if (ITER_VAR != NULL)
    {
        iter = atoi(ITER_VAR);
    }
    int debug = 0;
    char *DEBUG_VAR = getenv("DEBUG");
    if (DEBUG_VAR != NULL)
    {
        debug = atoi(DEBUG_VAR);
    }

    std::vector<std::vector<int>> results;

    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0, M-1);
    

    for (int i = 0; i < N; i++)
    { 
        objectsFinal[i].id = i;
        std::cin >> objectsFinal[i].value ;
    }
    for (int i = 0; i < M; i++)
    {
        peopleFinal[i].id = i;
    }

    // repetir iter vezes

    for(int t =0; t< iter; t++){

        std::vector<int> inresults(N+1);
        std::vector<struct Object> objects(N);
        std::vector<struct Person> people(M);

        // recriar vetor
        for(int i = 0; i < M; i++){
            people[i].id = i;
       
        }
        for(int i = 0; i < N; i++){
            objects[i].id = i;
            objects[i].value = objectsFinal[i].value;
        }

        //escolha aleatoria : colocar objs em pessoas aleatorias
        
        for (int i = 0; i < N; i++)
        {
            int rn = distribution(generator); // gera número

            people[rn].valuesum+= objects[i].value;
            people[rn].objids.push_back(objects[i].id);
            objects[i].pid= people[rn].id;   
        }
        // Passo 2 
        // 1 
        Person mmsp = people[0];
        for (int i = 1; i < M; i++){
            if(people[i].valuesum <= mmsp.valuesum ){
                mmsp = people[i];
            }
        } 
        /// 2 
        long unsigned int p3 = 0;
        while(p3 <  objects.size()){
            p3 = 0;
            for(auto &obj : objects){
                int sair=0;
                
                for (auto &mmsid :mmsp.objids){
                    if(obj.id == mmsid){                    
                        sair = 1;
                        p3++;
                    }
                } 

                if(sair == 0){

                    if((people[obj.pid].valuesum - obj.value) > mmsp.valuesum){

                        people[obj.pid].valuesum -= obj.value;

                        std::vector<int>::iterator itr = std::find(people[obj.pid].objids.begin(), people[obj.pid].objids.end(), obj.id);
                        int i = std::distance(people[obj.pid].objids.begin(), itr);
                        people[obj.pid].objids.erase(people[obj.pid].objids.begin()+ i);
                        
                        obj.pid = mmsp.id;
            
                        people[mmsp.id].valuesum += obj.value;
                        people[mmsp.id].objids.push_back(obj.id);
                        
                        mmsp = people[mmsp.id];

                        for (int i = 0; i < M; i++){
                            if(people[i].valuesum <=mmsp.valuesum ){
                                mmsp = people[i]; 
                            }
                        } 
                    }
                    else{
                        p3++;
                    }
                }
            
            }
        }
       
        //checar qual mmsp de people final
        Person mmspFinal= peopleFinal[0];

        for (int i = 1; i < M; i++){
            if(peopleFinal[i].valuesum <= mmspFinal.valuesum ){
                mmspFinal = peopleFinal[i];
            }
        }
        if(mmsp.valuesum>= mmspFinal.valuesum){
            peopleFinal = people;
            objectsFinal= objects;
        }
        

        inresults[0]=mmsp.valuesum;
        int n= 1;
        for(auto &obj : objects){
            inresults[n]=obj.pid;
            n++;
        }

        results.push_back(inresults);

    }  
    

    if(debug==1){
        for(auto &r : results){
            for(int inr=0; inr<=N; inr++){
                std::cerr << r[inr] << " ";
            }
            std::cerr << "\n";
        }
    }
    /// final

    //checar qual mmsp de people final
    Person mmspFinal= peopleFinal[0];
    for (int i = 1; i < M; i++){
        if(peopleFinal[i].valuesum <= mmspFinal.valuesum ){
            mmspFinal = peopleFinal[i];
        }
    }

    // escrver no arquivo

    std::ofstream F("out.txt");
    F <<mmspFinal.valuesum<< "\n" ;
    F.close();

    // saida terminal
        
    std::cout << mmspFinal.valuesum << "\n";
    for (int i = 0; i < M; i++)
    {
        std::sort(peopleFinal[i].objids.begin(), peopleFinal[i].objids.end(),ordfinal); 
        for(int b = peopleFinal[i].objids.size() -1; b>=0; b--){
            std::cout << peopleFinal[i].objids[b] << " " ;
        }
        std::cout << "\n";
    }
    return 0;
}