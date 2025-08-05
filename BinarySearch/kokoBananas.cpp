#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        std::sort(piles.begin(), piles.end());

        int left = 0;
        int right = piles[piles.size() - 1];
        int min_rate = right;
        while (left <= right)
        {
            int mid = left + (right-left) / 2;
            int time = 0;

            for (int i=0; i < piles.size(); i++)
            {
                time += (piles[i] + mid - 1) / mid;
            }

            if (time > h) 
            {
                left = mid +1;
            }
            else
            {
                min_rate = mid;
                right = mid -1;
            }

        }

        return min_rate;

    }
};