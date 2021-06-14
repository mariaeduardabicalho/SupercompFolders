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
    int valuesum=0;
    std::vector<int> objids;
};

bool ordfinal (int i,int j) { return (i>j); }

int main()
{
    int N, M;
    std::cin >> N >> M;
    std::vector<struct Object> objects(N);
    std::vector<struct Person> people(M);

    
    // std::cout << N;
    for (int i = 0; i < N; i++)
    {
        objects[i].id = i;
        std::cin >> objects[i].value ;
        // std::cout << objects[i].value<< "\n";
    }
    // std::cout <<"sai do for";

    std::sort(objects.begin(), objects.end()); 



    int mp= 0;
    // int idd;
    // for (auto &obj : objects)
    // people[0].objids.push_back(objects[0].id);
    // std::cout << people[0].objids;
    for (int i = 0; i < N; i++)
    {
        // std::cout<< objects[i].value;
        // std::cout<< mp;
        people[mp].valuesum+= objects[i].value;

        people[mp].objids.push_back(objects[i].id);
        
        if(mp==M-1){
            mp=0;
        }
        else{
            mp++;
        }
        // std::cout<< "entrei";
    }
    // std::cout << M; 
    std::cout << people[M-1].valuesum << "\n";
    for (int i = 0; i < M; i++)
    {
        std::sort(people[i].objids.begin(), people[i].objids.end(),ordfinal); 
        
        for(int b = people[i].objids.size() -1; b>=0; b--){
            std::cout << people[i].objids[b] << " " ;
        }

        std::cout << "\n";
    }
    

    return 0;
}