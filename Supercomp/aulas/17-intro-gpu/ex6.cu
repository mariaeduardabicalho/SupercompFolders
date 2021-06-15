#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/functional.h>
#include <thrust/transform.h>
#include <iostream>

int main() {

    thrust::device_vector<double> AAPL;
    thrust::device_vector<double> MSFT;
    thrust::device_vector<double> MEAN_DIF(2518,0);
    double stocks_AAPL, stocks_MSFT, mean;

    for(int i =0; i < 2518; i++){
        std::cin >> stocks_AAPL >> stocks_MSFT;
        AAPL.push_back(stocks_AAPL);
        MSFT.push_back(stocks_MSFT);
    }


    thrust::transform(AAPL.begin(), AAPL.end(), MSFT.begin(), MEAN_DIF.begin(), thrust::minus<double>());
    double val = thrust::reduce(MEAN_DIF.begin(), MEAN_DIF.end());
    mean = val/2517;
    std::cout << "Média: " << fabs(mean) << "\n";

}