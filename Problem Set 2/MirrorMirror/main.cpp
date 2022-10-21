#include <iostream>

int main()
{
    int n, k = 1;
    while (std::cin >> n)
    {
        char ** cells = new char * [n];
        char ** alter = new char * [n];
        for (int i = 0; i < n; i++)
        {
            cells[i] = new char[n];
            for (int j = 0; j < n; j++)
            {
                std::cin >> cells[i][j];
            }
        }
        for (int i = 0; i < n; i++)
        {
            alter[i] = new char[n];
            for (int j = 0; j < n; j++)
            {
                std::cin >> alter[i][j];
            }
        }

        bool flag_vertical = true;
        bool flag_90 = true;
        bool flag_180 = true;
        bool flag_270 = true;
        bool flag_pre = true;
        bool flag_ver_90 = true;
        bool flag_ver_180 = true;
        bool flag_ver_270 = true;


        int i2 = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            int j2 = 0;
            for (int j = n - 1; j >= 0; j--)
            {
                if (flag_vertical && alter[i2][j2] != cells[i][j2]) flag_vertical = false;
                if (flag_90 && alter[i2][j2] != cells[j][i2]) flag_90 = false;
                if (flag_180 && alter[i][j] != cells[i2][j2]) flag_180 = false;
                if (flag_270 && alter[j][i2] != cells[i2][j2]) flag_270 = false;
                if (flag_pre && alter[i2][j2] != cells[i2][j2]) flag_pre = false;
                if (flag_ver_90 && alter[i2][j] != cells[i2][j2]) flag_ver_90 = false;
                if (flag_ver_180 && alter[i][j2] != cells[i2][j2]) flag_ver_180 = false;
                if (flag_ver_270 && alter[j][i] != cells[i2][j2]) flag_ver_270 = false;

                j2++;
            }
            i2++;
        }
        std::cout << "Pattern " << k;
        if (flag_pre) std::cout << " was preserved.\n";
        else if (flag_vertical) std::cout << " was reflected vertically\n.";
        else if (flag_90) std::cout << " was rotated 90 degrees.\n";
        else if (flag_180) std::cout << " was rotated 180 degrees.\n";
        else if (flag_270) std::cout << " was rotated 270 degrees.\n";
        else if (flag_ver_90) std::cout << " was reflected vertically and rotated 90 degrees.\n";
        else if (flag_ver_180) std::cout << " was reflected vertically and rotated 180 degrees.\n";
        else if (flag_ver_270) std::cout << " was reflected vertically and rotated 270 degrees.\n";

        else std::cout << " was improperly transformed.\n";
        k++;
    }

    return 0;
}