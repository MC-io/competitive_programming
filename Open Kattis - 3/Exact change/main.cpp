#include <iostream>

int main()
{
    int T; std::cin >> T;
    for (int t = 0; t < T; t++)
    {
        int m; std::cin >> m;
        int n; std::cin >> n;
        int * A = new int[n];
        for (int i = 0; i < n; i++)
        {
            std::cin >> A[i];
        }

        for (int i = 0; i < n; i++)
        {
            int x = A[i];
            std::fabs(m - x)
        }
    }

    return 0;
}