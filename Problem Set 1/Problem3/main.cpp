#include <iostream>

int main()
{
    int T;
    std::cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N, k, max = INT32_MIN;
        std::cin >> N;
        for (int i = 0; i < N; i++)
        {
            std::cin >> k;
            if (k > max)
                max = k;
        }
        std::cout << "Case " << i + 1 << ": " << max << '\n';
    }
    return 0;
}