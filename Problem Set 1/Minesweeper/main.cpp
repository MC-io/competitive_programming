#include <iostream>

int main()
{
    int m, n;
    std::cin >> m >> n;
    char ** map = new char * [m];
    for (int i = 0; i < m; i++)
    {
        map[i] = new char[n];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> map[i][j];
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int c = 0;
            if (i > 0)
            {
                if (map[i - 1][j] == '*') c++;
            }
            if (i < m - 1)
            {
                if (map[i + 1][j] == '*') c++;
            }
            if (j > 0)
            {
                if (map[i][j - 1] == '*') c++;
            }
            if (j < n - 1)
            {
                if (map[i][j + 1] == '*') c++;
            }
            if (i > 0 && j > 0)
            {
                if (map[i - 1][j - 1] == '*') c++; 
            }
            if (i > 0 && j < n - 1)
            { 
                if (map[i - 1][j + 1] == '*') c++; 
            }
            if (i < m - 1 && j > 0)
            {
                if (map[i + 1][j - 1] == '*') c++;
            }
            if (i < m - 1 && j < n - 1)
            {
                if (map[i + 1][j + 1] == '*') c++;
            }
            if (map[i][j] == '.') map[i][j] = c + '0';
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << map[i][j] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}