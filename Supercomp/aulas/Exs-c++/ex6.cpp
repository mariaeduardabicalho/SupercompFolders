#include <iostream>
#include <iomanip> 
#include <vector>
#include<cmath>


int main(int argc, char const *argv[]){

    int N;
    std:: cout<< "Insira um numero:";
    std::cin >>N;
    std::vector<double>x(N),y(N);
    for(int i =0;i<N;i++){
        std:: cout<< "Insira um numero:";
        std::cin>> x[i]>>y[i];
    }

    std::vector<std::vector<double>>mat;

    for(int i =0;i<N;i++){
        std::vector<double> linha; //recreado td vez nulo;
        for(int j =0;i<N;j++){
            double dx=x[i] - x[j];
            double dy=y[i]-y[j];
            double dist = sqrt(dx*dx + dy*dy);
            linha.push_back(dist);
        }

        mat.push_back(linha);
    }
    std::cout << std::setprecision(2)<< std::fixed;
    for(auto linha:mat){
        for(auto el : linha){
            std::cout << el<<" ";
        }
        std::cout<< "\n";
    }
}