#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <iostream>
#include <chrono>
#include <thrust/extrema.h>
#include <thrust/execution_policy.h>
#include <thrust/functional.h>

int main() {

    thrust::host_vector<double> host;

    for(int i = 0; i<2517;i++){
        double s;
        std::cin >> s;
        host.push_back(s);
    }

    // for(int i =0; i < 2517; i++){
    //     std::cin >> stocks;
    //     host.push_back(stocks);
    // }


    auto start = std::chrono::steady_clock::now(); 
    thrust::device_vector<double> dev(host);  
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;

    

    std::cerr << "elapsed time: " << elapsed_seconds.count() << "s\n";  
    
    //  media
    double val = thrust::reduce(dev.begin(), dev.end());
    double mean = val/2517;
    std::cout << "media: " << mean << "\n";

    // media anual 

    double val2 = thrust::reduce(dev.begin()+2152, dev.end());
    double mean2 = val2/356;
    std::cout << "media ultimo ano: " << mean2 << "\n";


    auto result = thrust::minmax_element(dev.begin(), dev.end());
    auto result2 = thrust::minmax_element(dev.end() - 365, dev.end());
    std::cout << "Mínimo 10 anos: " << *(result.first) << "\n";  
    std::cout << "Máximo 10 anos: " << *(result.second) << "\n";  
    std::cout << "Mínimo último ano: " << *(result2.first) << "\n";  
    std::cout << "Máximo último ano: " << *(result2.second)<< "\n"

}