#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <random>
#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/functional.h>
#include <thrust/transform.h>
#include <math.h> 
#include <thrust/iterator/counting_iterator.h>
#include <thrust/random/uniform_real_distribution.h>
#include <thrust/random/linear_congruential_engine.h>
#include <thrust/random.h>

struct Object
{
    int value, id, pid;
    bool operator<(Object &a)
    {
        return value > a.value;
    }
};
struct Person
{
    int valuesum=0, id =0;
    std::vector<int> objids;
};
bool ordfinal (int i,int j) { return (i>j); }

struct iter_gpu{
    int N;
    int M;
    int seed;
    int *pids;
    int *values;
    int *people_sum;
    int *rns;

    iter_gpu(int N,int M,int seed,int *pids,int *values,int *people_sum,int *rns) : N(N), M(M),seed(seed) ,pids(pids), values(values),people_sum(people_sum),rns(rns) {};

    __host__ __device__
    int  operator() (const int &ite){
        // printf("ite:: %d::\n",ite);
        thrust::default_random_engine eng(ite*seed*1000);
        thrust::uniform_int_distribution<int> d(0,M-1);

        // valores aleatorios e soma
        for (int i = 0; i < N; i++){
            int rn = d(eng);
            rns[i]= rn;
            pids[ite*N+i] = rn;
            people_sum[ite*M+rn]+= values[i]; 
            
        }
        // Passo 2 
        // 1  Achar mmsp
        int mmsp= people_sum[ite*M];
        int mmspid=0;
        for (int i = 1; i < M; i++){
            if(people_sum[ite*M+i] <= mmsp){ 
                mmsp = people_sum[ite*M+i];
                mmspid= i;
            }
        }
        // printf("mmsp: %d\n", mmsp);
        // printf("mmspid: %d\n", mmspid);

        /// 2 
        long unsigned int p3 = 0;
        while(p3 < N) {
            // printf("whileeee\n");
            p3 = 0;
            for (int i = 0; i < N; i++){
                
                    // printf("peoplesum[]:: %d\n", people_sum[ite*N+pids[ite*N+i]]);
                    // printf("values[]:: %d\n",values[i]);
                    // printf("mmsp:: %d\n",mmsp);
                    
                    if((people_sum[ite*M+pids[ite*N+i]]-values[i])> mmsp){
                    
                        people_sum[ite*M+pids[ite*N+i]] -= values[i];
                        pids[ite*N+i]= mmspid;
                        people_sum[ite*M+mmspid] += values[i];
                        // printf("mmsp2222:: %d\n",mmsp);
                        // printf("newww valueee:: %d\n",people_sum[ite*N+mmspid]);
                        // printf("mmspid2:: %d\n",mmspid);

                        for (int k = 0; k< M; k++){
                            // printf("peopl sum for:: %d \n",people_sum[ite*N+k]);
                            // printf("mmspid: %d \n",mmspid);
                            // printf("peopl sum MMSPID:: %d \n",people_sum[ite*N+mmspid] );
                            if(people_sum[ite*M+k] <=people_sum[ite*M+mmspid] ){    
                                mmsp = people_sum[ite*M+k]; 
                                mmspid= k;
                            }
                        }
                        // printf("mmsp in if :: %d \n", mmsp);
                    }
                    else{
                        p3++;
                    }
                
            }       
        }

        return (mmsp);
    }
};

int main()
{
    int N, M;
    std::cin >> N >> M;
    std::vector<struct Object> objectsFinal(N);
    thrust::device_vector<struct Object> divFinal(N);
    thrust::device_vector<int> values;


    int v;
    for (int i = 0; i < N; i++){ 
        objectsFinal[i].id = i;
        std::cin >> v;
        objectsFinal[i].value = v ;
        values.push_back(v);
    }
    // for (int i = 0; i < M; i++){
    //     peopleFinal[i].id = i;
    // }

    // int iter= 100000;
    // int seed= 10;

    int seed = 0;
    char *SEED_VAR = getenv("SEED");
    if (SEED_VAR != NULL)
    {
        seed = atoi(SEED_VAR);
    }
    int iter = 100000;
    char *ITER_VAR = getenv("ITER");
    if (ITER_VAR != NULL)
    {
        iter = atoi(ITER_VAR);
    }
    int debug = 0;
    char *DEBUG_VAR = getenv("DEBUG");
    if (DEBUG_VAR != NULL)
    {
        debug = atoi(DEBUG_VAR);
    }


    thrust::device_vector<double> results(iter);
    thrust::device_vector<int> pids(N*iter);
    thrust::device_vector<int> people_sum(M*iter,0);
    thrust::device_vector<int> mmsps(iter);
    

    //teste
    thrust::device_vector<int> rns(N);

    iter_gpu itgpu(N,M,seed,pids.data().get(),values.data().get(),people_sum.data().get(),rns.data().get());

    thrust::transform(thrust::make_counting_iterator<int>(0),
                        thrust::make_counting_iterator<int>(iter),
                        mmsps.begin(),itgpu);

    // thrust::device_ptr<int> result;
    auto result= thrust::max_element(mmsps.begin(),mmsps.end());
    // int index=0;
    int index = (result - mmsps.begin());

    //debug
    if(debug){
        for(int it=0; it< iter; it++){
            std::cerr<< mmsps[it];
            for(int io = 0; io<N;io++){
                std::cerr << " "<< pids[it*N+io] ;   
            }   
            std::cerr<< "\n";
        }
    }

    //resutado
    std::cout << *(result)<<"\n";
    for(int p = 0; p<M ; p++){
        for(int io = 0; io<N;io++){
            if(pids[index*N+io]==p){
                std::cout << io << " ";
            }
        }
        std::cout<< "\n";
    }
    return 0;

}