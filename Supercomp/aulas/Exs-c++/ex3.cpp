#include <iostream>
#include <iomanip> 
#include<cmath>

int main(){
    int n;
    std:: cout<< "Insira um numero:";
    std::cin >> n;

    double s = 0.0;
    for(int i = 0; i<=n ; i++){
        
        s+= 1/pow(2,i);
        
    }
    std::cout << std::setprecision(15) << s<< "\n";
}

