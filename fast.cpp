#include <iostream>
#include <chrono>
#include <omp.h>

#define N 100000
#define chunk 1000
#define hilos 8

int main(){
    float a[N], b[N], c[N];
    int i;

    for (i=0; i < N; i++)
    {
        a[i] = i;
        b[i] = i*2;
    }

    int pedazos = chunk;

    using clock = std::chrono::steady_clock;
    auto start = clock::now();

    //Hasta aquí la lógica es la misma que ejemplo secuencial
    omp_set_num_threads(hilos);
    #pragma omp parallel shared(a, b, c, pedazos) private(i)
    {
        for (int repeat = 0; repeat < 10000; repeat++) {
            #pragma omp for schedule(static, pedazos)
            for (i = 0; i < N; i++) {
                c[i] = a[i] + b[i];
            }
        }
    }

    auto end = clock::now();
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();

    std::cout << "Elapsed: " << time << " milliseconds\n";
    
    std::cout << "c = ";
    for (i = 0; i < 10; i++) {
        std::cout << c[i] << " ";
    }
    std::cout << "\n"; 

    return 0;
}