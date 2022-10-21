#include <iostream>
#include <math.h>

int main()
{
    int n;
    while(std::cin >> n)
    {
        int * A = new int[n];
        bool * B = new bool[n];
        for (int i = 0; i < n; i++)
        {
            std::cin >> A[i];
            B[i] = false;
        }
        bool flag = false;
        for (int i = 1; i < n; i++)
        {
            if (std::fabs(A[i - 1] - A[i]) < n && std::fabs(A[i - 1] - A[i]) > 0)
            {
                if (B[A[i - 1] - A[i] - 1] == false)
                    B[A[i - 1] - A[i] - 1] = true;
                else 
                {
                    std::cout << "Not jolly\n";
                    flag = true;
                    break;
                }
            }
            else 
            {
                std::cout << "Not jolly\n";
                flag = true;
                break;
            }
        }
        if (!flag) std::cout << "Jolly\n";
    }

    return 0;
}