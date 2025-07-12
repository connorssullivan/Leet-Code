#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        // Check rows
        for (int row=0; row < 9; row++)
        {
            std::unordered_set<char> us;
            for (int i=0; i < 9; i++)
            {
                if( board[row][i] == '.')
                    continue;
                if (us.count(board[row][i]))
                    return false;
                us.insert(board[row][i]);
            }
        }

        // Check Cols
        for (int col=0; col < 9; col++)
        {
            std::unordered_set<char> us;
            for (int i=0; i < 9; i++)
            {
                if (board[i][col] == '.')
                    continue;
                if (us.count(board[i][col]))
                    return false;
                us.insert(board[i][col]);

            }
        }

        // Check the tiles
        for (int square = 0; square < 9; square++)
        {
            std::unordered_set<char> us;
            for (int i=0; i < 3; i++)
            {
                for (int j=0; j < 3; j++)
                {
                    int row { (square/3) * 3 + i };
                    int col { (square%3) * 3 + j };

                    if (board[row][col] == '.')
                        continue;
                    if (us.count(board[row][col]))
                        return false;
                    us.insert(board[row][col]);
                }
            }
            
        }
        return true;
    }

};

int main() 
{   
    Solution s {};
    std::vector<std::vector<char>> testBoard = {
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    std::cout << ((s.isValidSudoku(testBoard)) ? "True": "False") << "\n";

    return 0;
}