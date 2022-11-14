#include <iostream>
char matrix[60][60];

int movs[] = {1, 0,-1, 0, 0, 1, 0, -1};
int W, H;
int count = 0;

bool check(int x, int y)
{
    return !(x < 0 || y < 0 || x >= H || y >= W);
}

void dfs(int x, int y, bool **& visited)
{
    if (x < 0 || y < 0 || x >= H || y >= W) return;
    if (matrix[x][y] == '#') 
    {
        visited[x][y] = true;
        return;
    }
    if (!visited[x][y])
    {
        if (matrix[x][y] == 'G')
        {
            count++;
        }
        visited[x][y] = true;
        bool flag = false;
        // print
        // Check if there is no trap around
        for (int i = 0; i < 4; i++)
        {
            if (check(x + movs[i * 2], y + movs[i * 2 + 1]) && matrix[x + movs[i * 2]][y + movs[i * 2 + 1]] == 'T')
            {
                flag = true;
                break;
            }
        }
        if (flag) return;
        for (int i = 0; i < 4; i++)
        {
            dfs(x + movs[i* 2],y + movs[i * 2 + 1],visited);
        }
    }
}

int main()
{
    while (std::cin >> W >> H)
    {
    std::pair<int,int> start_pos;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            std::cin >> matrix[i][j];
            if (matrix[i][j] == 'P') 
            {
                start_pos.first = i;
                start_pos.second = j;
            }
        }
    }

    bool ** visited = new bool * [H];
    for (int i = 0; i < H; i++)
    {
        visited[i] = new bool[W];
        for (int j = 0; j < W; j++)
        {
            visited[i][j] = false;
        }
    }
    dfs(start_pos.first, start_pos.second, visited);

    std::cout << count << '\n';
    count = 0;
    }
    return 0;
}