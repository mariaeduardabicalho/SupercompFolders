#include <vector>
#include <iostream>
#include <cstdlib>
#include <omp.h>
#include <unistd.h>

double conta_complexa(int i) {
	sleep(1);
	return 2 * i;
}

int main() {
	int N = 10; 
	std::vector<double> vec;
	double init_time, final_time;

	init_time = omp_get_wtime();
	#pragma omp parallel for 
	for (int i = 0; i < N; i++) {
		vec.push_back(conta_complexa(i));
	}
	
	for (int i = 0; i < N; i++) {
		std::cout << i << " ";
	}

	final_time = omp_get_wtime() - init_time;
	std::cout << final_time;
	
	return 0;
}
