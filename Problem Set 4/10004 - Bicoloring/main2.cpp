#include <iostream>
#include <vector>
#include <list>
#include <math.h>

int n;
int adj[200][200];
int visited[200];


bool dfs(int a, int p, int color)
{
    // si ya fue coloreado
    if (visited[a] != -1)
    {
        if (color != visited[a])
            return false;
        return true;
    }

    visited[a] = color;
    for (int i = 0; i < n; i++)
    {
        if (adj[a][i] == 1 && i != p)
        {
            if (!dfs(i,a,std::fabs(color - 1))) return false;
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
            visited[i] = -1;
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

        visited[0] = 0;
        for (int i = 1; i < n; i++)
        {
            if (adj[0][i] == 1)
            {
                flag = dfs(i,0,1); 
            }
        }
        if (flag) std::cout << "BICOLORABLE.\n";
        else std::cout << "NOT BICOLORABLE.\n";
        std::cin >> n;
    }
}