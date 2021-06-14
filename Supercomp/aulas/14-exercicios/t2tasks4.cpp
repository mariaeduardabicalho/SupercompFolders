///2
//sim, diminiu por mais da metdade

// 3
// duas tarefas, 

//4

//Com um numero maior de tasks o tempo piora

//




#include <omp.h>
#include <iostream>
#include <iomanip>
static long num_steps = 1024l*1024*1024*2;

#define MIN_BLK  1024*1024*256


double pi_r(long Nstart, long Nfinish, double step,double sum) {
    long i,iblk;
    if (Nfinish-Nstart < MIN_BLK){
        #pragma omp parallel for reduction (+:sum)
        for (i = Nstart; i < Nfinish; i++){
            double x = (i+0.5)*step;
            sum += 4.0/(1.0+x*x); 
        }
        return sum;
    } else {
        iblk = Nfinish-Nstart;
        sum = pi_r(Nstart,Nfinish-iblk/2,step,sum);
        sum= pi_r(Nfinish-iblk/2, Nfinish,step,sum);
    }

    return sum;
}

int main () {
    long i;
    double step, pi;
    double init_time, final_time;
    double sum1=0;
    double sum2=0,sum3=0,sum4=0;
    step = 1.0/(double) num_steps;
    init_time = omp_get_wtime();

    #pragma omp parallel 
    {
        #pragma omp master
        {
            #pragma omp task
            {   
                sum1=pi_r(0, num_steps/4, step,sum1);
            }
            #pragma omp task
            {   
                sum2=  pi_r(num_steps/4, num_steps/2, step,sum2);
            }
            #pragma omp task
            {   
                sum3=  pi_r(num_steps/2, 3*(num_steps/4), step,sum2);
            }
            #pragma omp task
            {   
                sum4=  pi_r(3*(num_steps/4), num_steps, step,sum2);
            }
        }
    }

    pi = step * (sum1+sum2+sum3+sum4);
    final_time = omp_get_wtime() - init_time;

    std::cout << "for " << num_steps << " steps pi = " << std::setprecision(15) << pi << " in " << final_time << " secs\n";
}


