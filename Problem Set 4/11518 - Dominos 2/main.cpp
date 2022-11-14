#include <iostream>

int adj[10001][10001];
bool visited[10001];
int n;

void dfs(int a)
{
    if (visited[a]) return;
    visited[a] = true;
    for (int i = 1; i < n + 1; i++)
    {
        if (adj[a][i] == 1)
        {
            dfs(i);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int T; std::cin >> T;

    for (int t = 0; t < T; t++)
    {
        int m ,l;
        std::cin >> n >> m >> l;
        visited[0] = false;
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                adj[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++)
        {
            visited[i + 1] = false;
        }
        for (int i = 0; i < m; i++)
        {
            int x, y;
            std::cin >> x >> y; 
            adj[x][y] = 1;
        }
        int count = 0;
        for (int i = 0; i < l; i++)
        {
            int z; std::cin >> z;
            dfs(z);
            
        }
        for (int i = 0; i < n + 1; i++)
        {
            if (visited[i]) count++;
        }   
        std::cout << count << '\n';
    }
    return 0;
}