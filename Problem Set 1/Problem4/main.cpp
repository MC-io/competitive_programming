#include <iostream>
#include <string>
#include <vector>

int main()
{
    int T {};
    std::cin >> T;

    for (int i = 0; i < T; i++)
    {
        std::vector<int> indices;
        std::vector<std::string> webpages(10);
        std::vector<int> relevance(10);

        int max = INT32_MIN;

        for (int j = 0; j < 10; j++)
        {
            std::cin >> webpages[j] >> relevance[j];
            if (relevance[j] > max)
            {
                max = relevance[j];
                indices.clear();
                indices.push_back(j);
            }
            else if (relevance[j] == max)
            {
                indices.push_back(j);
            }
        }

        std::cout << "Case #" << i + 1 << ":\n";
        for (int j = 0; j < indices.size(); j++)
        {
            std::cout << webpages[indices[j]] << '\n';
        }
    }

    return 0;
}