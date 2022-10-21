#include <iostream>
#include <string>
int main()
{
    int d;
    std::cin >> d;
    while (d > 0)
    {
        char letter {};
        std::cin >> letter;
        if (letter == 'S')
        {
            std::string nums;
            std::cin >> nums;
            std::string first, second, third;
            for (int i = 0; i < nums.length(); i++)
            {
                if (nums[i] - '0' == 1)
                {
                    first.append("* . ");
                    second.append(". .");
                    third.append(". .");
                }
                else if (nums[i] - '0' == 2)
                {
                    first.append("* . ");
                    second.append("* . ");
                    third.append(". . ");
                }
                else if (nums[i] - '0' == 3)
                {
                    first.append("* * ");
                    second.append(". .");
                    third.append(". .");
                }   
                else if (nums[i] - '0' == 4)
                {
                    first.append("* * ");
                    second.append(". * ");
                    third.append(". . ");
                }   
                else if (nums[i] - '0' == 5)
                {
                    first.append("* . ");
                    second.append(". * ");
                    third.append(". . ");
                }   
                else if (nums[i] - '0' == 6)
                {
                    first.append("* * ");
                    second.append("* . ");
                    third.append(". . ");
                }   
                else if (nums[i] - '0' == 7)
                {
                    first.append("* * ");
                    second.append("* * ");
                    third.append(". .");
                }   
                else if (nums[i] - '0' == 8)
                {
                    first.append("* . ");
                    second.append("* * ");
                    third.append(". . ");
                }   
                else if (nums[i] - '0' == 9)
                {
                    first.append(". * ");
                    second.append("* . ");
                    third.append(". . ");
                }   
                else if (nums[i] - '0' == 0)
                {
                    first.append(". * ");
                    second.append("* * ");
                    third.append(". . ");
                }             
            }
            std::cout << first << '\n' << second << '\n' << third << '\n';
        }
        else if (letter == 'B')
        {
            std::string first, second, third;
            std::getline(std::cin, first);
            std::getline(std::cin, second);
            std::getline(std::cin, third);
            for (int i = 0; i < first.length(); i+= 4)
            {
                if (first.substr(i,3) == " " && second.substr(i,3) == " " && third.substr(i,3) == " ")
                {

                }
                else if (first.substr(i,3) == " " && second.substr(i,3) == " " && third.substr(i,3) == " ")
                {

                }
                else if (first.substr(i,3) == " " && second.substr(i,3) == " " && third.substr(i,3) == " ")
                {

                }
                else if (first.substr(i,3) == " " && second.substr(i,3) == " " && third.substr(i,3) == " ")
                {

                }
                else if (first.substr(i,3) == " " && second.substr(i,3) == " " && third.substr(i,3) == " ")
                {

                }
                else if (first.substr(i,3) == " " && second.substr(i,3) == " " && third.substr(i,3) == " ")
                {

                }
                else if (first.substr(i,3) == " " && second.substr(i,3) == " " && third.substr(i,3) == " ")
                {

                }
                else if (first.substr(i,3) == " " && second.substr(i,3) == " " && third.substr(i,3) == " ")
                {

                }
                else if (first.substr(i,3) == " " && second.substr(i,3) == " " && third.substr(i,3) == " ")
                {

                }
                else if (first.substr(i,3) == " " && second.substr(i,3) == " " && third.substr(i,3) == " ")
                {

                }
            }
        }
    }

    return 0;
}