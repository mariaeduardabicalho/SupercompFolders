#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <iostream>
#include <chrono>
#include <thrust/extrema.h>
#include <thrust/execution_policy.h>
#include <thrust/functional.h>

int main() {

    thrust::host_vector<double> host(10, 0);

    for(int i = 0; i<10;i++){
        double s;
        std::cin >> s;
        host[i] = s;
    }

    // for(int i =0; i < 2517; i++){
    //     std::cin >> stocks;
    //     host.push_back(stocks);
    // }


    auto start = std::chrono::steady_clock::now(); 
    thrust::device_vector<double> dev(host);  
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;

    printf("Host vector: ");
    for (auto i = host.begin(); i != host.end(); i++) {
        std::cout << *i << " "; // este acesso é rápido -- CPU
    }
    printf("\n");
    
    printf("Device vector: ");
    for (auto i = dev.begin(); i != dev.end(); i++) {
        std::cout << *i << " "; // este acesso é lento! -- GPU
    }
    printf("\n");

    std::cerr << "elapsed time: " << elapsed_seconds.count() << "s\n";  

    // val = thrust::reduce(dev.begin(), dev.end(), 0, thrust::plus<double>()));

}