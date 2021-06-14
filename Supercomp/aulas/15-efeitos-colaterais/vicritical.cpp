#include <unistd.h>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <omp.h>




double conta_complexa(int i) {
    sleep(1);
    return 2 * i;
}


int main() {
	int N = 10; 
	std::vector<double> vec;
	double init_time, final_time;

	init_time = omp_get_wtime();

	#pragma omp parallel for default(none) shared(vec) firstprivate(N)
	for (int i = 0; i < N; i++) {
        double r = conta_complexa(i);
		#pragma omp critical
		{
			vec.push_back(r);
		}
		
	}
	
	for (int i = 0; i < N; i++) {
		std::cout << vec[i] << " ";
	}
	final_time = omp_get_wtime() - init_time;
	std::cout << final_time;
	
	return 0;
}
