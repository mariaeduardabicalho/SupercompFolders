#include <vector>
#include <iostream>
#include <cstdlib>
#include <omp.h>
#include <unistd.h>
#include <cmath>
#include <random>

int main(){

    double sum = 0;
    int N = 1000000;
    double init_time, final_time;

    int seed = 0;
    char *SEED_VAR = getenv("SEED");
    if (SEED_VAR != NULL)
    {
        seed = atoi(SEED_VAR);
    }

    
    
    init_time = omp_get_wtime();
    #pragma omp parallel for reduction (+:sum) default(none) firstprivate(N) 
    for (int i = 0; i < N; i++){ 
        int NUM_T =  omp_get_num_threads();
        std::default_random_engine generator(N/NUM_T);
        std::uniform_real_distribution<> distribution(0.0, 1.0);

        double x = distribution(generator);
        double y = distribution(generator);
        
        if( (pow(x,2) + pow(y,2)) <= 1) {
            sum++;
        }
    }
    double pi = 4* sum /N ;
    std::cout<< pi <<"\n";
    std::cerr << sum <<"\n";

    final_time = omp_get_wtime() - init_time;
	std::cout << final_time<<"\n"; 

  



}