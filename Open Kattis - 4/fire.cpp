#include <iostream>
#include <vector>
#include <queue>

int R, C;
char map[1000][1000];

int main()
{
    int T; std::cin >> T;
    while (T--)
    {
    std::cin >> R >> C;
    std::vector<std::pair<int,int>> fire_blocks;
    std::pair<int,int> player_block;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            std::cin >> map[i][j];
            if (map[i][j] == 'F')
            {
                fire_blocks.push_back({i,j});
            }
            else if (map[i][j] == 'J')
            {
                player_block = {i,j};
            }
        }
    }

    std::queue<std::pair<int,int>> colaj;
    std::vector<std::queue<std::pair<int,int>>> fire_queues(fire_blocks.size());

    colaj.push(player_block);
    for (int i = 0; i < fire_blocks.size(); i++)
    {
        fire_queues[i].push(fire_blocks[i]);
        map[fire_blocks[i].first][fire_blocks[i].second] = '.';
    }
    int steps = 0;
    bool flag = false;
    map[player_block.first][player_block.second] = '.';
    while (!colaj.empty())
    {
        // fireblocks
        for (int i = 0; i < fire_queues.size(); i++)
        {
            std::pair<int,int> fist = {-5,-5};
            int count2 = 0;

            while (!fire_queues[i].empty() && fire_queues[i].front() != fist)
            {
                std::pair<int,int> v = fire_queues[i].front();
                fire_queues[i].pop();
                if (v.first < 0 || v.first >= R || v.second < 0 || v.second >= C)
                {
                    continue;
                }
                else if (map[v.first][v.second] == 'J' || map[v.first][v.second] == '.')
                {
                    count2++;
                    map[v.first][v.second] = 'F';
                    if (count2 == 1)
                        fist = {v.first + 1, v.second};
                    fire_queues[i].push({v.first + 1, v.second});
                    fire_queues[i].push({v.first - 1, v.second});
                    fire_queues[i].push({v.first, v.second + 1});
                    fire_queues[i].push({v.first, v.second - 1});
                }
            }
            fist = {-5,-5};

        }
        bool flag2 = false;
        // Player
        std::pair<int,int> first = {-5,-5};
        int count = 0;

        while (!colaj.empty() && colaj.front() != first)
        {
            std::pair<int,int> v = colaj.front();
            colaj.pop();
            if (v.first < 0 || v.first >= R || v.second < 0 || v.second >= C)
            {
                flag = true;
                flag2 = true;
                break;
            }
            else if (map[v.first][v.second] == '.')
            {
                count++;
                map[v.first][v.second] = 'J';
                if (count == 1)
                    first = {v.first + 1, v.second};
                colaj.push({v.first + 1, v.second});
                colaj.push({v.first - 1, v.second});
                colaj.push({v.first, v.second + 1});
                colaj.push({v.first, v.second - 1});
            }
        }
        first = {-5,-5};
        if (flag2) break;
        steps++;



    }
    if (flag) std::cout << steps << '\n';
    else std::cout << "IMPOSSIBLE\n"; 
/*
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            std::cout << map[i][j];
        }
        std::cout << '\n';
    }*/
    }
    return 0;
}