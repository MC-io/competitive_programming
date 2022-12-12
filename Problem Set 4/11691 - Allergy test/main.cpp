#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <functional>
using namespace std;

int A[21];  
int main()
{
    int N; scanf("%d", &N);
    while(N--) 
    {
        int k; scanf("%d", &k);

        for (int i = 0; i < k; i++)
            scanf("%d", &A[i]);

        std::sort(A, A + k, greater<int>());
        //printf("%d\n",A[0]);

        int shortest_test = INT32_MAX;
        for (int i = 0; i < A[0]; i++) 
        {
            int l = i;
            int r = A[0] - i - 1;
            int cost = A[0];
            for (int j = 1; j < k; j++) 
            {
                int left, right;
                left = std::min(l, A[j] - 1);
                right = std::min(r, A[j] - 1);
                if (left > right)
                {
                    l = A[j] - left - 1;
                    cost += l + 1;
                }
                else
                {
                    r = A[j] - right - 1;
                    cost += r + 1;
                }
            }
            shortest_test = std::min(shortest_test, cost);
        }
        printf("%d\n", shortest_test);
    }
    return 0;
}