#include <iostream>

int main()
{
    int S, B;
    std::cin >> S >> B;
    while (S > 0 && B > 0)
    {
        int * LE = new int[S + 2];
        LE[0] = -1;
        for (int i = 1; i <= S + 1; i++)
        {
            LE[i] = i - 1;
        }
        int * RI = new int[S + 2];
        RI[S + 1] =  -1;
        for (int i = 0; i <= S; i++)
        {
            RI[i] = i + 1;
        }
        for (int i = 0; i < B; i++)
        {
            int L, R;
            std::cin >> L >> R;
            RI[LE[L]] = RI[R];
            LE[RI[R]] = LE[L];
            
            if (L == 1 || LE[RI[R]] == 0) std::cout << '*';
            else std::cout << LE[RI[R]];
            std::cout << ' ';
            
            if (R == S || RI[LE[L]] == S + 1) std::cout << '*';
            else std::cout << RI[LE[L]];
            std::cout << '\n';
        }
        
        delete [] LE;
        delete [] RI;

        std::cout << "-\n";
        std::cin >> S >> B;
    }
    return 0;
}