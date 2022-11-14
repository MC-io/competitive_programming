#include <iostream>

char grid[100][100];
bool visited[100][100];

int main()
{
    int T; std::cin >> T;
    for (int t = 0; t < T; t++)
    {
        int N; std::cin >> N;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                std::cin >> grid[i][j];
                visited[i][j] = false;
            }
        }
        int count = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (visited[i][j]) continue;
                visited[i][j] = true;
                if (grid[i][j] == 'x')
                {
                    count++;
                    for (int k = i + 1; k < N; k++)
                    {
                        if (grid[k][j] == 'x' ||grid[k][j] == '@')
                        {
                            visited[k][j] = true;
                        }
                        else break;
                    }
                    for (int k = j + 1; k < N; k++)
                    {
                        if (grid[i][k] == 'x' || grid[i][k] == '@')
                        {
                            visited[i][k] = true;
                        }
                        else break;
                    }
                }

            }
        }
        std::cout << "Case " << t + 1 << ": " << count << '\n';
    }

    return 0;
}