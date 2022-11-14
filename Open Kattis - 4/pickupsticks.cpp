#include <iostream>
#include <vector>

int n;
std::vector<bool> visited(100001);
std::vector<bool> vis(100001);

std::vector<std::vector<int>> adj(100001);
std::vector<int> order;

bool dfs(int a)
{
    if (visited[a]) return false;
    visited[a] = true;
    for (int i = 0; i < adj[a].size(); i++)
    {
        if (!dfs(adj[a][i])) return false;
    }
    order.insert(order.begin(), a);
    return true;
}

int main()
{
    int m;
    while (std::cin >> n)
    {
        std::cin >> m;
        for (int i = 0; i <= n; i++)
        {
            adj[i].clear();
            visited[i] = false;
            order.clear();
        }

        for (int i = 0; i < m; i++)
        {
            int a, b;
            std::cin >> a >> b;


            adj[a].push_back(b);
        }

        bool flag = true;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                if (!dfs(i))
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
        {
            for (int i = 0; i < order.size(); i++)
            {
                std::cout << order[i] << '\n';
            }
        }
        else std::cout << "IMPOSSIBLE.\n";
    }
    
    return 0;
}