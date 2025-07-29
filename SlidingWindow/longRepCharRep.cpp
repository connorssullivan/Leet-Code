#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        if (s.length() == 0)
            return 0;

        std::unordered_map<char, int> counts;
        int left {0};
        int right {0};
        int res {0};
        

        while (right < s.length())
        {
            counts[s[right]]++;

            int largest {0};
            for (auto& val : counts)
            {
                if (val.second > largest)
                {
                    largest = val.second;
                }
            }

            bool valid;
            (((right - left) - largest)+1 <= k) ? valid = true : valid = false;
            if (valid)
            {
                res = std::max(res, right - left + 1);
                if (right < s.length())
                    right++;
                else 
                    break;
            }

            else 
            {
                counts[s[left]]--;
                left++;
                if (right - left +1 < s.length() && right == s.length() - 1)
                    break;
            }

        }

        return res;

    }
};

int main ()
{
    // k = 1
    // a b b b a
}