#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>

int main()
{

    long long int A[1000];
    long long int ans, cur, mid;

    int  N, q, cs = 1;
    while(std::cin >> N)
    {
        std::cout << "Case " << cs << ":\n";

        for( int i = 0; i < N; i++ )
            std::cin >> A[i];

        std::cin >> q;

        while(q--)
        {
            std::cin >> mid;
            ans = A[0] + A[1];
            for (int i = 0; i < N; i++ )
            {
                for (int j = i + 1; j < N; j++ )
                {
                    cur = A[i] + A[j];
                    if (std::abs(ans - mid) > std::abs(cur - mid)) ans = cur;
                }
            }
            std::cout << "Closest sum to " << mid << " is " << ans << ".\n"; 
        }
        cs++;
    }
    return 0;
}