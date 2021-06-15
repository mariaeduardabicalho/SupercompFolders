#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/functional.h>
#include <thrust/transform.h>
#include <iostream>
#include <math.h> 
#include <thrust/iterator/constant_iterator.h>

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

    printf("Ganho: ");
    for (thrust::device_vector<double>::iterator i = ganho_diario.begin(); i != ganho_diario.end(); i++) {
        std::cout << *i << " ";
    }
    printf("\n");
}

