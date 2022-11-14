#include <iostream>
#include <vector>

int energy[101];


std::vector<std::vector<int>> adj;
int n; 

bool dfs(int a, int cur_energy, std::vector<bool> visited)
{
    if (a == n) return true;
    if (visited[a])
    {
        if (cur_energy + energy[a] > 0) return true;
        else return false;
    }
    visited[a] = true;
    if (cur_energy + energy[a] <= 0) return false;
    bool flag = false;
    for (int i = 0; i < adj[a].size(); i++)
    {
        if (dfs(adj[a][i],cur_energy + energy[a],visited))
        {
            flag = true;
            break;
        }
    }
    return flag;
}

int main()
{
    std::ios::sync_with_stdio(false);

    std::cin.tie(NULL); std::cout.tie(NULL);

    std::cin >> n;
    while(n != -1)
    {
        adj.clear();
        adj.resize(101);
        std::vector<bool> visited;
        visited.resize(101);
        for (int i = 1; i <= n; i++)
        {
            std::cin >> energy[i];
            int e; std::cin >> e;
            for (int j = 0; j < e; j++)
            {
                int a; std::cin >> a;
                adj[i].push_back(a);
            }
        }
        int cur_energy = 100;
        visited[0] = false;
        visited[1] = true;
        bool flag = false;
        for (int i = 0; i < adj[1].size(); i++)
        {
            if (dfs(adj[1][i],cur_energy + energy[1],visited))
            {
                flag = true;
                break;
            }
        }
        if (flag) std::cout << "winnable\n";
        else std::cout << "hopeless\n";
        std::cin >> n; 
    }

    

    return 0;
}