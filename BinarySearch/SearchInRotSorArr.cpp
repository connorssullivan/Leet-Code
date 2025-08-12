#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) return mid;

            // Right half is sorted
            if (nums[mid] < nums[left]) 
            {
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;  
                else
                    right = mid - 1;  
            }
            // Left half is sorted
            else 
            {
                if (target < nums[left] || target > nums[mid])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};
