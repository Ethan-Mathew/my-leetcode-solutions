class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int runningSum = 0;
        int maxSum = 0;

        for (int i{}; i < nums.size(); i++) {
            if (i != 0 && nums[i] > nums[i - 1]) {
                runningSum += nums[i];
            } else if (i != 0) {
                maxSum = std::max(maxSum, runningSum);
                runningSum = nums[i];
            } else {
                runningSum += nums[i];
            }
        }

        return std::max(maxSum, runningSum);
    }
};