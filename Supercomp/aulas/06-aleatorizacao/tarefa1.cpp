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

int main()
{
    
    int n;
    cin >> n;
    int maxweight;
    cin >> maxweight;
    // struct Object backpack[n]; 
    vector<struct Object> backpack(n);
    vector<struct Object> finalBackpack;
    struct Object final;
    int finalWeight = 0;
    int finalValue = 0;
    

    int seed =10;
    char *SEED_VAR = getenv("SEED");
    if (SEED_VAR != NULL){
        seed= atoi(SEED_VAR);
    }

    default_random_engine eng("SEED");
    uniform_int_distribution<double> dist(0,1);

    for (int i = 0; i < n; i++){
        backpack[i].id = i;
        cin >> backpack[i].weight >> backpack[i].value;
    }

    sort(backpack.begin(),backpack.end(), myfunction);

    for (int i = 0; i < n; i++){

        // if distribution(generator) == 0.75 {
        //         i++;
        // }
        double rnd = dist(eng);
        
        if ((finalWeight + backpack[i].weight) <= maxweight && rnd <=0.75 ){
            final.id = backpack[i].id;
            final.value = backpack[i].value;
            final.weight = backpack[i].weight;
            finalBackpack.push_back(final);
            finalWeight += backpack[i].weight;
            finalValue += backpack[i].value;
        }
    }

    cout << finalWeight << " "<<  finalValue << " "<< "0";
    cout << "\n";
    sort(finalBackpack.begin(),finalBackpack.end(), myotherfunction);
    for (auto linha:finalBackpack){
        cout << linha.id;
        cout << " ";
    }


}