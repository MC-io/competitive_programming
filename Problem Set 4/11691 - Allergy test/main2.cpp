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

        int shortest_test = 0;
        for (int i = 1; i < k; i++) 
        {
            shortest_test += A[i];
        }
        printf("%d\n", shortest_test + 1);
    }
    return 0;
}