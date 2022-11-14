#include <iostream>

bool visited[1000001];
std::vector<std::vector<int>> adj(100001);


int main()
{
    int n, m;
    while (std::cin >> n >> m)
    {
        for (int i = 0; i <= n; i++)
        {
            visited[i] = false;
            top_of[i] = 0;
        }
        while (m--)
        {
            int a, b;
            std::cin >> a >> b;
            top_of[a] = b;
        }
        bool flag = false;
        int * vec = new int [n + 1];
        for (int i = 1; i <= n; i++)
        {
            visited[i] = true;
            int k = i;
            int count = 0;

            vec[count++] = k;
            while (top_of[k] != 0 && !visited[top_of[k]])
            {
                k = top_of[k];
                vec[count] = k;
                count++;
            }
            if (count == n) 
            {
                flag = true;
                break;
            } 
        }

        if (flag)
        {
            for (int i = 0; i < n; i++)
            {
                std::cout << vec[i] << '\n';
            }
        }
        else std::cout << "IMPOSSIBLE\n";
    }
    return 0;
}