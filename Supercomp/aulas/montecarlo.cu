#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <random>
#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/functional.h>
#include <thrust/transform.h>
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

struct is_less_1
{
  __host__ __device__
  bool operator()(const double &x)
  {
    return x <= 1;
  }
};


int main(){

    
    int N = 100000;
    double init_time, final_time;

    int seed = 0;
    char *SEED_VAR = getenv("SEED");
    if (SEED_VAR != NULL)
    {
        seed = atoi(SEED_VAR);
    }

    rng_gpu rg = {.SEED =seed};  
    thrust::device_vector<double> X(N);
    thrust::device_vector<double> Y(N);

    thrust::transform(thrust::make_counting_iterator<int>(0),
                    thrust::make_counting_iterator<int>(N), 
                    X.begin(), rg);
    
    thrust::transform(thrust::make_counting_iterator<int>(0),
                    thrust::make_counting_iterator<int>(N), 
                    Y.begin(), rg);

    // for(int i =0 ; i<N; i++){
    //     // printf("x: %lf",X[1]);
    //     // printf("Y: %f",Y[1]);

    //     std::cout << X[i]<< " ";

    // }

    // std::cout << X[0]<< " ";
    
    thrust::device_vector<double> X2(N);
    thrust::device_vector<double> Y2(N);
    thrust::device_vector<double> XY(N);

    thrust::transform(X.begin(), X.end(), X2.begin(),thrust::square<double>());
    thrust::transform(Y.begin(), Y.end(), Y2.begin(),thrust::square<double>());

    // std::cout << X2[0]<< " ";

    thrust::transform(X2.begin(), X2.end(), Y2.begin(), XY.begin(), thrust::plus<double>());
    

    int sum = thrust::count_if(XY.begin(), XY.end(), is_less_1());

    double pi = 4* sum /N ;
    std::cout<< pi <<"\n";
    std::cerr << sum <<"\n";





}