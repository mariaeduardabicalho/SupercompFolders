#include <stdio.h>
#include <iostream> 
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>

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

    for (int i = 0; i < n; i++){
        backpack[i].id = i;
        cin >> backpack[i].weight >> backpack[i].value;
    }

    sort(backpack.begin(),backpack.end(), myfunction);

    // for (auto linha:backpack){
    //     cout << "Valor:" << linha.value;
    //     cout << "\n";
    // }

    for (int i = 0; i < n; i++){
        if ((finalWeight + backpack[i].weight) <= maxweight){
            final.id = backpack[i].id;
            final.value = backpack[i].value;
            final.weight = backpack[i].weight;
            finalBackpack.push_back(final);
            finalWeight += backpack[i].weight;
            finalValue += backpack[i].value;
        }
    }

    // for (auto linha:finalBackpack){
    //     cout << "Id:" << linha.id<< "Valor:" << linha.value << "Peso:" << linha.weight;
    //     cout << "\n";
    // }
    cout << finalWeight << " "<<  finalValue << " "<< "0";
    cout << "\n";
    sort(finalBackpack.begin(),finalBackpack.end(), myotherfunction);
    for (auto linha:finalBackpack){
        cout << linha.id;
        cout << " ";
    }


}