#include <iostream>
#include <math.h>
#include <vector>

std::vector<std::pair<int,int>> inter_mall1(2001);
std::vector<std::pair<int,int>> inter_mall2(2001);

int dist(std::pair<int,int> a, std::pair<int,int> b)
{
    return std::fabs(a.first - b.first) + std::fabs(a.second - b.second);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    int p1, p2;

    std::cin >> p1;
    while (p1 != 0)
    {
    for (int i = 0; i < p1; i++)
    {
        int a, s; std::cin >> a >> s;
        inter_mall1[i] = {a,s};
    }
    
    std::cin >> p2;
    for (int i = 0; i < p2; i++)
    {
        int a, s; std::cin >> a >> s;
        inter_mall2[i] = {a,s};
    }

    int min = INT32_MAX;
    for (int i = 0; i < p1; i++)
    {
        for (int j = 0; j < p2; j++)
        {
            if (dist(inter_mall1[i],inter_mall2[j]) < min)
            {
                min = dist(inter_mall1[i],inter_mall2[j]);
            }
        }
    }
    if (min == 0) min = 1;
    std::cout << min << '\n';
    std::cin >> p1;
    }


    return 0;
}