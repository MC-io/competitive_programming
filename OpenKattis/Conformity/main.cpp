#include <iostream>
#include <algorithm>
#include <vector>
int main()
{
    int n;
    while (std::cin >> n)
    {
        int * most_popular = nullptr;
        int how_many = 0;
        std::vector<int*> courses;
        for (int i = 0; i < n; i++)
        {
            int * A = new int[5];
            for (int j = 0; j < 5; j++)
            {
                std::cin >> A[j];
            }
            std::sort(A, A + 5);
            courses.push_back(A);
        }
        int max = INT32_MIN;
        int * arr = new int[5];
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            int pos_com = 0;
        }
        if (max == 1) max = n;
        std::cout << max << '\n';
    }
    return 0;
}