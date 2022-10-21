#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        int rows, cols, max;
        char piece;
        std::cin >> piece >> rows >> cols;
        if (piece == 'r')
        {
            if (rows <= cols) max = rows;
            else max = cols;
        }
        else if (piece == 'k')
        {
            if (rows == 1) max = cols;
            else if (cols == 1) max = rows;
            else if (rows == 2 && cols == 2) max = 4;
            else if (rows == 3 || cols == 3) max = ((cols * rows) / 3) * 2;
            else max = (cols * rows) / 2;
        }
        else if (piece == 'Q')
        {
            if (rows <= cols) max = rows - 1;
            else max = cols - 1;
        }
        else if (piece == 'K')
        {

        }
        std::cout << max << '\n';
    }

    return 0;
}