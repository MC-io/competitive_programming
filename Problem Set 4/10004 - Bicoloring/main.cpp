#include <iostream>
#include <vector>
#include <list>

int n;
int adj[200][200];
bool visited[200];


bool dfs(int a, int p)
{
    if (visited[a]) return true;
    visited[a] = true;
    for (int i = 0; i < n; i++)
    {
        if (adj[a][i] == 1 && i != p)
        {
            if (adj[i][p]) return false;
            if (!dfs(i,a)) return false;
        }
    }
    return true;
}

int main()
{
    std::cin >> n;
    while (n != 0)
    {
        int l; std::cin >> l;

        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
            for (int j = 0; j < n; j++)
            {
                adj[i][j] = 0;
            }
        }

        for (int i = 0; i < l ;i++)
        {
            int a, b; std::cin >> a >> b;
            adj[a][b] = 1;
            adj[b][a] = 1;
        }
        bool flag = true;

        visited[0] = true;
        for (int i = 0; i < n; i++)
        {
            if (adj[0][i] == 1 && i != 0)
            {
                if (!dfs(i,0)) flag = false;  
            }
        }
        if (flag) std::cout << "BICOLORABLE.\n";
        else std::cout << "NOT BICOLORABLE.\n";
        std::cin >> n;
    }
}