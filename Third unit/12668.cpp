#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<char>> table(100);
vector<vector<int>> pawns_number(100);
vector<bool> available_rows(100);
vector<bool> available_cols(100);


class Cell
{
public:
    int pawns;
    int i;
    int j;

    Cell(int pawns,int i, int j)
    {
        this->pawns = pawns;
        this->i = i;
        this->j = j;
    }
};

struct less_than_key
{
    inline bool operator() (const Cell& struct1, const Cell& struct2)
    {
        return (struct1.pawns< struct2.pawns);
    }
};

int main()
{
    int N;
    while (cin >> N)
    {
        vector<Cell> cells;
        for (int i = 0; i < N; i++)
        {
            table.push_back(vector<char>(100));
            pawns_number.push_back(vector<int>(100));
            for (int j = 0; j < N; j++)
            {
                cin >> table[i][j]; 
            }
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (table[i][j] == 'X') 
                {
                    pawns_number[i][j] == -1;
                    continue;
                }
                int count = 0;
                if (i > 0)
                {
                    if (table[i - 1][j] == 'X') count++;
                }
                if (j > 0)
                {
                    if (table[i][j - 1] == 'X') count++;
                }
                if (i < N - 1)
                {
                    if (table[i + 1][j] == 'X') count++;
                }
                if (j < N - 1)
                {
                    if (table[i][j + 1] == 'X') count++;
                }
                pawns_number[i][j] = count;
                cells.push_back(Cell(count,i,j));
            }
        }

        sort(cells.begin(), cells.end(), less_than_key());
        
        int counter = 0;
        while(!cells.empty())
        {
            Cell tmp = cells[0];
            cells.erase(cells.begin());
            bool flag = true;
            for (int ii = 0; ii < N; ii++)
            {
                if (table[tmp.i][ii] == 'R')
                {
                    flag = false;
                    break;
                }
            }
            if (!flag) continue;
            for (int ii = 0; ii < N; ii++)
            {
                if (table[ii][tmp.j] == 'R')
                {
                    flag = false;
                    break;
                }
            }
            if (!flag) continue;
            
            table[tmp.i][tmp.j] == 'R';
            counter++;
        }




    }

    return 0;
}