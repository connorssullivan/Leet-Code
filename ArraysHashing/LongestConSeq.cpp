#include <iostream>
#include <vector>
#include <algorithm> 
#include <unordered_set>

class Solution {

public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        std::unordered_set<int> nums_set {nums.begin(), nums.end()};

        int longest_streak {1};
        for (auto num : nums) 
        {
            int streak {1};
            int curr {num};

            while (nums_set.find(curr + 1) != nums_set.end())
            {
                streak++;
                curr++;
            }

            longest_streak = std::max(streak, longest_streak);
            
        }

        return longest_streak;
        
    }
};


int main()
{
    Solution s {};
    std::vector<int> nums {-8, -8, -8, -8, -4, -4, -3, -2, -1, 0, 0, 2, 2, 4, 4, 5, 5, 5, 6, 6, 7, };

    std::cout << s.longestConsecutive(nums) << "\n";


}