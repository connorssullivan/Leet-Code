#include <string>
#include <vector>
#include <iostream>

class Solution {
public:

    std::string encode(std::vector<std::string>& strs) {
        
        std::string sol {};

        for (const auto& s : strs) 
        {
            sol += std::to_string(s.size()) + "#" + s;
        }

        return sol;

        
    }

    std::vector<std::string> decode(std::string s) {
        
        std::vector<std::string> strs;
        int i { 0 };

        while ( i < s.size()) 
        { 
            int j { i + 1 };
            while ( s[j] != '#') 
                j++;
            
            int strLength = std::stoi(s.substr(i, j-i));

            std::string word = s.substr(j+1, strLength);
            strs.push_back(word);

            i = j + strLength + 1;
        }

        return strs;

    }
};


int main() {

    Solution sol {};
    std::vector<std::string> strs = { "neet","code","love","you" };

    std::string s { sol.encode(strs) };
    std::cout << s << "\n";

    std::vector<std::string> words { sol.decode(s)};

    for (const auto word : words)
        std::cout << word << "\n"; 
    

    return 0;
}