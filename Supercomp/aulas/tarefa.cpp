#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <random>

struct Object
{
    int weight, value, id;

    bool operator<(Object &a)
    {
        return value > a.value;
    }
};

struct Person
{
    int valuesum ;
    std::vector<int> objids;
};

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<struct Object> objects(n);
    std::vector<struct Person> people(m);
    int mp = 0;
    

    // int seed = 10;
    // char *SEED_VAR = getenv("SEED");
    // if (SEED_VAR != NULL)
    // {
    //     seed = atoi(SEED_VAR);
    // }
    // std::default_random_engine generator(seed);
    // std::uniform_real_distribution<double> distribution(0.0, 1.0);

    for (int i = 0; i < n; i++)
    {
        objects[i].id = i;
        std::cin >>  objects[i].value;
        std::cout << objects[i].value<< "\n";
    }

    std::sort(objects.begin(), objects.end()); // a chance de ter pego nao importa a ordem

   
    for (auto &obj : objects){
        people[mp].valuesum += obj.value;
        people[mp].objids.push_back (obj.id);
        
        if(mp==2){
            mp=m;
        }
        else{
            mp--;
        }
    }
    

    // std::cout << currentWeight << " " << currentValue << "\n";
    // for (int i = 0; i < n; i++)
    // {
    //     if (usados[i])
    //     {
    //         std::cout << i << " ";
    //     }
    // }
    // std::cout << "\n";

    return 0;
}