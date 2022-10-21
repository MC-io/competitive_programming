#include <iostream>

int main()
{
    int M, N;
    std::cin >> M >> N ;
    while (M > 0 && N > 0)
    {
        if (M == 1|| N == 1) std::cout << M * N;
        else if (M == 2 && N == 2) std::cout << 4;
        else if ((M == 3 && N == 2) || (M == 2 && N == 3)) std::cout << 4;
        else if ((M * N) % 2 > 0) std::cout << (M * N) / 2 + 1;
        else std::cout << (M * N) / 2;
        std::cout << " knights may be placed on a " << M << " row " << N << " column board.\n";
        std::cin >> M >> N;
    }
    return 0;

}