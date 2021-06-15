/////// Bom para quando maiores pq o discard n precisa contar varios.



#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/functional.h>
#include <thrust/transform.h>
#include <iostream>
#include <math.h> 
#include <thrust/iterator/counting_iterator.h>
#include <thrust/random/uniform_real_distribution.h>
#include <thrust/random/linear_congruential_engine.h>
#include <thrust/random.h>

struct rng_gpu{
    int SEED;

    __device__ __host__
    double operator()(const int &i){
        thrust::default_random_engine eng(i*SEED);
        thrust:: uniform_real_distribution<double> d(0.0,1.0);

        eng.discard(100);

        return d(eng);
    }
};

int main() {    
    

    thrust::default_random_engine eng(10);
    thrust::uniform_real_distribution<double> dist(25,40);

    for(int i =0;i<10;i++){
        std::cout<< dist(eng) <<"\n";
    }

    rng_gpu rg = {.SEED =10};  

    thrust::device_vector<double> D(10);

    thrust::transform(thrust::make_counting_iterator<int>(0),
                    thrust::make_counting_iterator<int>(10), 
                    D.begin(), rg);

    for(int i = 0; i < 10; i++){
        std::cout << D[i] << "\n";
    }                




}