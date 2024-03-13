#include <iostream>
#include <chrono>


int Fibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return Fibonacci(n - 1) + Fibonacci(n - 2);

}


int main() {


    int N;
    std::cout << "Saisir la valeur de N : ";
    std::cin >> N ;
    auto start_time = std::chrono::high_resolution_clock::now();

    int value= Fibonacci(N);

    auto end_time = std::chrono::high_resolution_clock::now();

    // Calculez la différence entre le début et la fin
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    // Affichez le temps d'exécution en microsecondes
    std::cout << "Temps d'execution : " << duration.count() << " microseconds." << std::endl;
    std::cout << "Le resultat de la suite est :" << value  << std::endl;
    return 0;
}