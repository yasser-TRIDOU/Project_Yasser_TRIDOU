#include <iostream>
#include <chrono>


long int FibIteratif(long int N)
{

    long int tmp=0;
    long int a=0;
    long int b=1;
    for(long int i=0;i<N-1;i++)
    {
        tmp=a+b;
        a=b;
        b=tmp;
    }
    return tmp;
}

long int main()
{


    long int N;
    std::cout << "Saisir la valeur de N : ";
    std::cin >> N ;
    auto start_time = std::chrono::high_resolution_clock::now();


    long int value= FibIteratif(N);

    auto end_time = std::chrono::high_resolution_clock::now();

    // Calculez la différence entre le début et la fin
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    // Affichez le temps d'exécution en microsecondes
    std::cout << "Temps d'execution : " << duration.count() << " microseconds." << std::endl;
    std::cout << "Le resultat de la suite est :" << value  << std::endl;
    return 0;




}