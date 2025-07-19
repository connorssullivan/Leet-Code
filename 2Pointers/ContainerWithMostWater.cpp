#include <iostream>
#include <string>
#include <vector>



class Solution {

public:
    int maxArea(std::vector<int>& heights) {
        int max_area { 0 };
        int left {0};
        int right { static_cast<int> (heights.size()-1) };

        while (left < right)
        {
            int area {0};
            area = std::min(heights[left], heights[right]) * ((right - left));

            max_area = std::max(area, max_area);

            if (heights[left] < heights[right])
                left++;
            else right--;
        }

        return max_area;
        
    }
};


int main()
{
    Solution sol {};
    std::vector<int> heights {1,7,2,5,4,7,3,6};
    std::cout << sol.maxArea(heights) << std::endl;


    return 0;
}