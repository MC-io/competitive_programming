#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> soundex = {"AEIOUHWY","BFPV","CGJKQSXZ","DT","L","MN","R"};
    std::string word;

    while(std::cin >> word)
    {
        std::string ans;
        for (int i = 0; i < word.length(); i++)
        {
            if (soundex[0].find(word[i]) != std::string::npos) continue;
            for (int j = 1; j < 7; j++)
            {
                if (soundex[j].find(word[i]) != std::string::npos)
                {
                    while (soundex[j].find(word[i]) != std::string::npos)
                    {
                        i++;
                    }
                    i--;
                    ans.append(std::to_string(j));
                    break;
                }

            }
        }
        std::cout << ans << '\n';
    }
    

    return 0;
}