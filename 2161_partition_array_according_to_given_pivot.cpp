class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        std::vector<int> smaller;
        std::vector<int> pivots;
        std::vector<int> larger;

        for (int i{}; i < nums.size(); i++) {
            if (nums[i] < pivot) {
                smaller.push_back(nums[i]);
            } else if (nums[i] == pivot) {
                pivots.push_back(nums[i]);
            } else {
                larger.push_back(nums[i]);
            }
        }

        smaller.insert(smaller.end(), pivots.begin(), pivots.end());
        smaller.insert(smaller.end(), larger.begin(), larger.end());

        return smaller;
    }
};