#include <iostream>





int main()
{
    int k;
    std::cin >> k;
    int * A = new int[k];
    int * B = new int[6];
    for (int i = 0; i < k; i++)
        std::cin >> A[i];

    for (int i = 0; i < 6; i++)
    {
        B[i] = A[i];
    }


    int m = k - 1;
    while (m >= 0)
    {
        for (int i = k - 1; i >= 0; i--)
        {
            for (int j = i; j < k - 1; j++)
            {
                B[i] = A[i + 1];  
            }      
        }
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = i; j < 6; j++)
        {
            
        }
    }

    return 0;
}