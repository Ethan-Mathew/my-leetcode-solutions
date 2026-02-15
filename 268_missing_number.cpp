class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int range = 0;
        int num_total = 0;

        for (int i{}; i < nums.size(); i++)
        {
            range += (i + 1);
            num_total += nums[i];
        }

        return range - num_total;
    }
};