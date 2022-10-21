#include <iostream>
#include <vector>

int main()
{
    int T {};
    int robot_pos = 0;
    std::cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n {};
        std::cin >> n;
        
        std::vector<int> moves(n);
        for (int j = 0; j < n; j++)
        {
            std::string move;
            std::cin >> move;
            if (move == "LEFT")
            {
                robot_pos--;
                moves[j] = -1;
            }
            else if (move == "RIGHT")
            {
                robot_pos++;
                moves[j] = 1;
            }
            else if (move == "SAME")
            {
                int same_as_pos {};
                std::cin >> move;
                std::cin >> same_as_pos;
                robot_pos += moves[same_as_pos - 1];
                moves[j] = moves[same_as_pos - 1];
            } 
        }
        std::cout << robot_pos << '\n';
        robot_pos = 0;
    }

    return 0;
}