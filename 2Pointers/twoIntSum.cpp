#include <vector>
#include <iostream>



class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {

        std::vector<int> sol(2);

        for (int i=0; i < numbers.size(); i++)
        {
            int left {i+1};
            int right { static_cast<int>(numbers.size() -1)};
            int mid { (left + right) / 2 };
            int my_target { target - numbers[i] };



            while (mid >= left && mid <= right)
            {
                if (numbers[mid] == my_target)
                {
                    sol[0] = (i+1);
                    sol[1] = (mid+1);
                    return sol;
                }

                else if (numbers[mid] < my_target)
                {
                    
                    left = mid +1;
                }

                else 
                {
                    right = mid-1;
                }

                mid = (left+right) /2;
                
            }

        }
        return sol;
    }
};


int main ()
{
    Solution s {};
    std::vector<int> nums {-5,-3,0,2,4,6,8};

    std::vector<int> sol {s.twoSum(nums, 5)};

    std::cout << "[";
    for (auto num : sol)
        std::cout << num << ", ";
    std::cout << "]";

    return 0;
}