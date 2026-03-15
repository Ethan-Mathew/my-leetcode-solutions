#include <algorithm>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> solutions;

        std::sort(nums.begin(), nums.end());

        int mainPtr = 0;

        if (nums.size() < 3)
        {
            return solutions;
        }

        while (mainPtr < nums.size() - 2)
        {
            if (nums[mainPtr] > 0)
            {
                break;
            }

            int leftPtr = mainPtr + 1;
            int rightPtr = nums.size() -1;

            while (leftPtr < rightPtr)
            {
                int lrSum = nums[leftPtr] + nums[rightPtr];

                if (nums[mainPtr] + lrSum == 0)
                {
                    solutions.push_back({nums[mainPtr], nums[leftPtr], nums[rightPtr]});

                    int prevL = nums[leftPtr];
                    int prevR = nums[rightPtr];
                    while (leftPtr < rightPtr && nums[leftPtr] == prevL) leftPtr++;
                    while (leftPtr < rightPtr && nums[rightPtr] == prevR) rightPtr--;

                }
                else if (nums[mainPtr] + lrSum < 0)
                {
                    while (leftPtr < rightPtr)
                    {
                        int prev = nums[leftPtr];
                        leftPtr++;

                        if (nums[leftPtr] != prev) break;
                    }
                }
                else
                {
                    while (leftPtr < rightPtr)
                    {
                        int prev = nums[rightPtr];
                        rightPtr--;

                        if (nums[rightPtr] != prev) break;
                    }
                }
            }

            while (mainPtr < nums.size() - 2)
            {
                int prev = nums[mainPtr];
                mainPtr++;

                if (nums[mainPtr] != prev) break;
            }
        }

        return solutions;
    }
};