#include <iostream>
#include <chrono>
#include <omp.h>
#include <random>

#define N 100000
#define hilos 16
#define chunk 100 
#define mostrar 10

void imprimirArreglo(float *d);

int main(){
    float a[N], b[N], c[N];
    int i;
    std::random_device rd;
    std::uniform_real_distribution<float> dist(-1000.0f, 1000.0f);

    for (i = 0; i < N; i++) {
        a[i] = dist(rd);
        b[i] = dist(rd);
    }
    int pedazos = chunk;

    std::cout << "Sumando arreglos en paralelo!\n";
    
    auto start = std::chrono::steady_clock::now();

    //Hasta aquí la lógica es la misma que ejemplo secuencial
    omp_set_num_threads(hilos);
    #pragma omp parallel for \
    shared(a, b, c, pedazos) private(i)\
    schedule(static, pedazos)
        for (i=0; i<N; i++) {
            c[i] = a[i] + b[i];
        }

    auto end = std::chrono::steady_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();

    std::cout << "Tiempo: " << time << " microsegundos\n";

    std::cout << "a = ";
    imprimirArreglo(a);
    std::cout << "\n"; 

    std::cout << "b = ";
    imprimirArreglo(b);
    std::cout << "\n";

    std::cout << "c = ";
    imprimirArreglo(c);
    std::cout << "\n";

    return 0;
}

void imprimirArreglo(float *d)
{
    for (int x = 0; x < mostrar; x++ )
        std::cout << d[x] << " ";
    std::cout << std::endl;
}