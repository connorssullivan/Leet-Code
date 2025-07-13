#include <string>
#include <vector>
#include <iostream>
#include <ctype.h>

class Solution {
public:
    bool isPalindrome(std::string s) {
        std::string newStr {};

        for (auto c : s)
        {
            if (isalnum(c))
            {
                newStr += c;
            }
        }

        return (newStr == std::string(newStr.rbegin(), newStr.rend()));
        
    }
};

// 12345
int main() 
{
    Solution s {};
    bool ans = s.isPalindrome("0p");

    std::cout << (ans ? "True" : "False") << "\n";
    return 0;

}