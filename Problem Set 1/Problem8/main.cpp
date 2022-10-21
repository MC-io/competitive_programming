#include <iostream>
#include <string>
int main()
{
    int T;
    std::cin >> T;
    for (int i = 0; i < T; i++)
    {
        int A, F;
        std::cin >> A >> F;
        for (int j = 0; j < F; j++)
        {
            for (int k = 1; k <= A; k++)
            {
                for (int m = 0; m < k; m++)
                {
                    std::cout << k;
                }
                std::cout << '\n';
            }
            for (int k = A - 1; k > 0; k--)
            {
                for (int m = 0; m < k; m++)
                {
                    std::cout << k;
                }
                std::cout << '\n';
            }
            if (j != F - 1) std::cout << '\n';
        }
    }

    return 0;
}