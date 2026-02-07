class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        const int start = 0;
        const int end = nums.size() - 1;

        for (int i{1}; i < nums.size(); i++)
        {
            nums[i] += nums[i - 1];
        }

        for (int i{0}; i < nums.size(); i++)
        {
            int target;

            if (i == start)
            {
                if ((nums[end] - nums[start]) == 0)
                {
                    return 0;
                }
            }
            else if (i == end)
            {
                target = 0;
                if (nums[i - 1] == 0)
                {
                    return end;
                }
            }
            else
            {
                target = nums[i - 1];
                if (nums[end] - nums[i] == nums[i - 1])
                {
                    return i;
                }
            }
        }

        return -1;
    }
};