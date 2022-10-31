#include <iostream>

int main()
{
    int T; std::cin >> T;
    
    int *  A = new int[1000000];

    for (int k = 0; k < T; k++) 
    {
        int l, n;
        std::cin >> l >> n;

        for(int i = 0; i < n; i++) 
        {
            std::cin >> A[i];
        }

        int earliest = -1;
        int latest = -1;

        for (int i = 0; i < n; i++) 
        {
            earliest = std::max(earliest, std::min(A[i], l - A[i]));
            latest = std::max(latest, std::max(A[i], l - A[i]));
        }

        std::cout << earliest << ' ' << latest << '\n';
    }

    delete [] A;

    return 0;
}