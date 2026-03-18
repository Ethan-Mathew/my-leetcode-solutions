class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        
        int smallerPtr = (nums.size() / 2) - 1;
        int largerPtr = smallerPtr + 1;
        std::vector solution(nums.size(), 0);

        for (int i{}; i < nums.size(); i++) {
            if (largerPtr < nums.size() && (i % 2 == 0 || smallerPtr < 0)) {
                solution[i] = nums[largerPtr++];
            } else if (smallerPtr >= 0) {
                solution[i] = nums[smallerPtr--];
            }
        }

        return solution;
    }
};