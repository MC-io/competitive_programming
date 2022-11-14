#include <iostream>
#include <vector>

int n;
std::vector<std::vector<int>> adj(100001);
std::vector<bool> visited(100001);
std::vector<bool> vis(100001);


void dfs(int a)
{
    if (visited[a]) return;
    visited[a] = true;
    for (int i = 0; i < adj[a].size(); i++)
    {
        dfs(adj[a][i]);
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int T; std::cin >> T;

    while(T--)
    {
        int m;
        std::cin >> n >> m;
        for (int i = 0; i < n + 1; i++)
        {  
            vis[i] = false;
            visited[i] = false;
            adj[i].clear();
        }
        int count = n;
        for (int i = 0; i < m; i++)
        {
            int x, y;
            std::cin >> x >> y;
            adj[x].push_back(y);
             
            if (vis[y]) continue;
            else
            {
                vis[y] = true;
                count--;
            }
        }
        for (int i = 1; i < n + 1; i++)
        {
            if (!vis[i])
            {
                dfs(i);
            }
        }
        for (int i = 1; i < n + 1; i++)
        {
            if (!visited[i])
            {
                dfs(i);
                count++;
            }
        }
        std::cout << count << '\n';

    }
    return 0;
}