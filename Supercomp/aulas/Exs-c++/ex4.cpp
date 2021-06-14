
#include <iostream>
#include <iomanip> 
#include<cmath>
#include <vector>

////Tarefa 4 
// int main(){

//     int n;
    
//     std::cout << "Insira uma quantidade";
//     std::cin >> n;
//     double *fracs = new double[n];

//     double m;
//     double v;

//     for (int i=0; i<n;i++){
//         std::cout << "Insira um numero";
//         std::cin >> fracs[i];

//         m+=fracs[i];    
//     }

//     m/=n;

//     for (int i=0; i<n;i++){
//         v+=  pow(fracs[i]- m,2);
//         std::cout << v << "\n";
//     }
//     v/=pow(n,2);

//     delete[] fracs;

//     std::cout << "Media: " << m << " ; " << "Variancia: " << v << "\n";

// }
////Tarefa 5

int main(){
    

    int n;
    int k;

    std::cout << "Insira uma quantidade";
    std:: cin >>n;
    std::vector<double> fracs;

    double m;
    double v;

    for (int i=0; i<n;i++){
        std::cout << "Insira um numero";
        std::cin >> k;
        fracs.push_back(k);
        m+=fracs[i]; 
    }

    m/=n;

    for (int i=0; i<n;i++){
        v+=  pow(fracs[i]- m,2);
        std::cout << v << "\n";
    }
    v/=pow(n,2);

    


    std::cout << "Media: " << m << " ; " << "Variancia: " << v << "\n";

} 





//// for it 