#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <bitset>


int main()
{
    int C;
    std::cin >> C;

    for (int i = 0; i < C; i++)
    {
        int M;
        std::string pir_desc;
        std::cin >> M;
        for (int j = 0; j < M; j++)
        {
            int T;
            std::string pirates;
            std::cin >> T >> pirates;
            for (int k = 0; k < T; k++)
            {
                pir_desc.append(pirates);
            }
        }
        unsigned long long pirate = std::bitset<64>(pir_desc).to_ullong();
        int size = pir_desc.size();
        std::cout << pirate << '\n';
        int Q;
        std::cin >> Q;
        char op;
        std::cout << "Case 1:\n";
        for (int j = 0; j < Q; j++)
        {
            int k = 1;
            std::cin >> op;
            if (op == 'F')
            {
                int a, b;
                std::cin >> a >> b;
                int x = std::pow(2,(b - a + 1)) - 1;
                x <<= size - b - 1;

                pirate = pirate | x;
            }
            else if (op == 'E')
            {
                int a, b;
                std::cin >> a >> b;

                std::cout << pirate << '\n';


                long num = (1ll << (4 * 8 - 1)) - 1;
                long num2 = ((1 << b) - 1) ^ ((1 << (a - 1)) - 1);
                num = num ^ num2;

                std::cout << num << '\n';


                pirate = pirate & num;
                
/*
                int x = std::pow(2,(b - a + 1)) - 1;
                x <<= size - b - 1;
                x = ~x;
                int y = std::pow(2,a + 1) - 1;
                std::cout << x << '\n';
                y <<= size - b;
                x = x + y;
                std::cout << x << '\n';
                std::cout << pirate << '\n';
                pirate = pirate & x;*/


            }
            else if (op == 'I')
            {
                int a, b;
                std::cin >> a >> b;
                int y = std::pow(2,(b - a + 1)) - 1;
                y <<= size - b - 1;

                pirate = pirate ^ y;

            }
            else
            {
                int a, b;
                std::cin >> a >> b;
                std::cout << pirate << '\n';

                int n = pirate + std::pow(2,size);
                n >>= size - b - 2;
                
                int x = std::pow(2,b - a + 1) - 1 + std::pow(2,size);
                
                int y = n & x;
                n = y;

                
                int count = 0;
                while(n != 0)
                {
                    n = n & (n - 1);
                    count++;
                }
                std::cout << 'Q' << k << ": " << count - 1 << '\n'; 
                k++;
            }
        }
    
    }
    return 0;
}