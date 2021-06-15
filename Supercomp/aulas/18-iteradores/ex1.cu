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

    thrust::device_vector<double> means(2518,mean);
    thrust::device_vector<double> dps(2518,0);
    thrust::device_vector<double> vars(2518,0);

    thrust::transform(means.begin(), means.end(), MEAN_DIF.begin(), dps.begin(), thrust::minus<double>());
    thrust::transform(dps.begin(), dps.end(), vars.begin(),thrust::square<double>());
    double v = thrust::reduce(vars.begin(), vars.end());
    double var = v/ 2517;

    std::cout << "variancia : " << fabs(var) << "\n";

}