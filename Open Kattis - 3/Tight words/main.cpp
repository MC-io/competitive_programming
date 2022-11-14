#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>

int main()
{
    int k, n;
    while (std::cin >> k >> n)
    {
        int * A = new int[k + 1];
        int * B = new int[k + 1];

        for (int i = 0; i <= k; i++)
        {
            A[i] = 0; B[i] = 1;
        }
        for (int t = 0; t < n - 1; t++)
        {
            for (int i = 0; i <= k; i++)
            {
                for (int j = 0; j <= k; j++)
                {
                    if (std::fabs(i - j) <= 1)
                        A[j]++;
                }
            }
            for (int i = 0; i <= k; i++)
            {
                B[i] = B[i] * A[i];
                A[i] = 0; 
            }
        }
        long long hola = 0;
        for (int i = 0; i <= k; i++)
        {
            std::cout << B[i] << ' ';
            hola += B[i];
        }
        std::cout << std::fixed;
        std::cout << std::setprecision(9);
        std::cout << ((double) hola / (double)std::pow(k + 1,n)) * 100 << '\n';

        

    }


    /*
    int k, n;
    while (std::cin >> k >> n)
    {
        std::vector<int> nums;
        for (int i = 0; i <= k; i++)
        {
            nums.push_back(i);
        }
        std::vector<int> nums2;
        for (int t = 0; t < n - 1; t++)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                for (int j = 0; j <= k; j++)
                {
                    if (std::fabs(nums[i] - j) <= 1)
                    {
                        nums2.push_back(j);
                    }

                }
            }
            nums = nums2;
            nums2.clear();
        }
        std::cout << std::fixed;
        std::cout << std::setprecision(9);
        std::cout << ((double) nums.size() / (double)std::pow(k + 1,n)) * 100 << '\n';
    }

*/


/*
        std::string word, word2;
        for (int i = 0; i < n; i++)
        {
            word.push_back('0');
        }
        word2 = word;
        
        int count = 0;

        do
        {
            bool flag = true;
            for (int i = 1; i < n; i++)
            {
                if (std::fabs(word[i] - word[i - 1]) > 1)
                {
                    flag = false;
                    break;
                }
            }
            if (flag) count++;

            for (int i = n - 1; i >= 0; i--)
            {
                if (word[i] - '0' == k)
                {
                    word[i] = '0';
                }
                else 
                {
                    word[i] = word[i] + 1;   
                    break;
                }
            }
        } while (word2 != word);
        std::cout << std::fixed;
        std::cout << std::setprecision(9);
        std::cout << ((double)count / (double)std::pow(k + 1,n)) * 100 << '\n';
    }*/
    return 0;
}