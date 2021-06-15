#include <vector>
#include <iostream>
#include <cstdlib>
#include <omp.h>

#include <unistd.h>
#include <cmath>
#include <random>

int main(){

    long int n = 100;
    double init_time, final_time;
    
    init_time = omp_get_wtime();
    for(int i = 0; i< n ; i ++){
        int t;
        
        t =i*(i+1)/2;
        
        std::cout << t <<"\n";
        
    
    }
    final_time = omp_get_wtime() - init_time;
	std::cout << final_time<<"\n";
    
    










}