#include <iostream>
#include <chrono>
#include <random>

#define N 100000

int main(){
    float a[N], b[N], c[N];
    int i;
    std::random_device rd;
    std::uniform_real_distribution<float> dist(-1000.0f, 1000.0f);

    for (i = 0; i < N; i++) {
        a[i] = dist(rd);
        b[i] = dist(rd);
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
    
    std::cout << "a = ";
    for (i = 0; i < 10; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n"; 

    std::cout << "b = ";
    for (i = 0; i < 10; i++) {
        std::cout << b[i] << " ";
    }
    std::cout << "\n"; 

    std::cout << "c = ";
    for (i = 0; i < 10; i++) {
        std::cout << c[i] << " ";
    }
    std::cout << "\n";  

    return 0;
}