#include <iostream>
#include <vector>

int n;
std::vector<std::vector<int>> adj(100001);
std::vector<bool> visited(100001);

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int T; std::cin >> T;

    for (int t = 0; t < T; t++)
    {
        int m;
        std::cin >> n >> m;
        for (int i = 0; i <= n; i++)
        {
            visited[i] = false;
        }
        int count = n;

        for (int i = 0; i < m; i++)
        {
            int x, y;
            std::cin >> x >> y; 
            if (visited[y]) continue;
            else
            {
                visited[y] = true;
                count--;
            }
        }
        std::cout << count << '\n';
    }
    return 0;
}