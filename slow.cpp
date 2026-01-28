#include <iostream>
#include <chrono>

#define N 100000

int main(){
    float a[N], b[N], c[N];
    int i;

    for (i=0; i < N; i++)
    {
        a[i] = i;
        b[i] = i*2;
    }

    using clock = std::chrono::steady_clock;
    auto start = clock::now();

    std::cout << "Sumando arreglos en secuencia!\n";

    for (int repeat = 0; repeat < 10000; repeat++) {
        for (i = 0; i < N; i++)
        {
            c[i] = a[i] + b[i];
        }
    }
    
    auto end = clock::now();
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();

    std::cout << "Tiempo: " << time << " ms\n";
    
    std::cout << "c = ";
    for (i = 0; i < 10; i++) {
        std::cout << c[i] << " ";
    }
    std::cout << "\n";  

    return 0;
}