#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/functional.h>
#include <thrust/transform.h>
#include <iostream>
#include <math.h> 
#include <thrust/iterator/constant_iterator.h>

struct is_greater
{
  __host__ __device__
  bool operator()(const double &x)
  {
    return x > 0;
  }
};

int main() {

    thrust::device_vector<double> stocks;
    

    double s;
    while(std::cin){
        std::cin >> s;
        stocks.push_back(s);
    }

    int N = stocks.size();
    thrust::device_vector<double> ganho_diario(N-1);

    thrust::transform(stocks.begin()+1, stocks.end(), stocks.begin(), ganho_diario.begin(), thrust::minus<double>());

    int subiu = thrust::count_if(ganho_diario.begin(), ganho_diario.end(), is_greater());
    std::cout << "As ações subiram "<< subiu << " vezes";
    
    printf("\n");
}

