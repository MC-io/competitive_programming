#include <iostream>

int main()
{
    int N, M, c = 0;

    std::cin >> N >> M;

    while(N != 0 && M != 0)
    {
        int * jack = new int[N];
        int * jill = new int[M];

        for (int i = 0; i < N; i++)
        {
            std::cin >> jack[i];
        }
        int start_pos = 0;
        for (int i = 0; i < M; i++)
        {
            std::cin >> jill[i];
            for (int j = start_pos; j < N; j++)
            {
                if (jack[j] == jill[i])
                {
                    start_pos = j;
                    c++;
                    break;
                }
            }
        }
        delete [] jack;
        delete [] jill;

        std::cout << c << '\n';
        std::cin >> N >> M;
    }
    

    return 0;
}