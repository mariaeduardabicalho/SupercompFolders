#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/functional.h>
#include <thrust/transform.h>
#include <iostream>
#include <math.h> 
#include <thrust/iterator/constant_iterator.h>

struct variancia
{
    double media;
    int N;
    variancia(double m, int n): media(m), N(n){};
    __host__ __device__

    double operator()(const double& x) {
        return pow((x - media),2)/N;
        
    }
};

int main() {
    thrust::device_vector<double> AAPL;
    
    double stocks_AAPL, mean, var;

    while(std::cin){
        std::cin >> stocks_AAPL;
        AAPL.push_back(stocks_AAPL);
    }

    int N = AAPL.size();

    double val = thrust::reduce(AAPL.begin(), AAPL.end());
    mean = val/2517;
    std::cout << "Média: " << mean << "\n";


    var = thrust::transform_reduce(AAPL.begin(), AAPL.end(), variancia(mean, N),0.0, thrust::plus<double>());

    std::cout << "Variância: " << var << "\n";

}