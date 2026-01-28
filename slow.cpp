#include <iostream>
#include <chrono>
#include <random>

#define N 100000
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

    std::cout << "Sumando arreglos en secuencia!\n";

    auto start = std::chrono::steady_clock::now();
    for (i=0; i<N; i++)
    {
        c[i] = a[i] + b[i];
    }
    
    
    auto end = std::chrono::steady_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();

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
}

void imprimirArreglo(float *d)
{
    for (int x = 0; x < mostrar; x++ )
        std::cout << d[x] << " ";
    std::cout << std::endl;
}