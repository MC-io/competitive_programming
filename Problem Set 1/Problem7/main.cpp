#include <iostream>

int main()
{
    int L {};
    std::cin >> L;
    while(L != 0)
    {
        std::string points;
        
        for (int i = 0; i < L - 1; i++)
        {
            std::string dir;
            std::cin >> dir;
            
            if (i == 0) 
            {
                points = dir;
                continue;
            }

            if (dir == "No")
            {
                continue;
            }

            if (points[1])
            {
                if (points[0] == dir[0])
                {
                    if (points[0] == '+') points[0] = '-';
                    else points[0] = '+';
                }
                if (points[1] == 'x')
                {
                    points[1] = 'z';
                }
                if (points[1] == 'y')
                {
                    points[1] = 'x';
                }
                if (points[1] == 'z')
                {
                    points[1] = 'x';
                }


            }
        }

        std::cout << points << '\n';

        std::cin >> L;
    }

}