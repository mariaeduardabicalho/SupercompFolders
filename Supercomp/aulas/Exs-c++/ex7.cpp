#include <iostream>
#include <iomanip> 
#include <vector>
#include<cmath>


void calcula_distancias();

void  calcula_distancias(int n){

    int N;
    std::cin >>N;
    std::vector<double>x(N),y(N);
    for(int i =0;i<N;i++){
        std::cin>> x[i]>>y[i];
    }

    std::vector<std::vector<double>>mat;

    for(int i =0;i<N;i++){
        std::vector<double> linha; //recreado td vez nulo;
        
        for(int j =0;i<N;j++){
            if(i<=j){
                double dx=x[i] - x[j];
                double dy=y[i]-y[j];
                double dist = sqrt(dx*dx + dy*dy);
                linha.push_back(dist);
            }  
            linha.push_back(mat[j][i]);  
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

int main(int argc, char const *argv[]){
}