#include <iostream>

int main()
{
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        char op;
        long long a, b;
        std::cin >> a >> b;
        if (a > b)
            op = '>';
        else if (a < b)
            op = '<';
        else
            op = '=';
        std::cout << op << '\n';
    }
    return 0;
}