#include <iostream>

int main()
{   
    int r;
    std::cin >> r;
    while(r != -1)
    {
        bool win = true;
        std::string word, guess;
        std::cin >> word >> guess;
        int counter = 0;
        for (int i = 0; i < guess.length() && counter < 7; i++)
        {
            bool flag = false;
            for (int j = 0; j < word.length(); i++)
            {
                if (word[j] == guess[i])
                {
                    flag = true;
                    break;
                }
            }
            if (!flag) counter++;
            if (counter == 7)
            {
                std::cout << "You lose.\n";
                break;
            }
        }
        if (counter < 7 && )
    }
    return 0;
}