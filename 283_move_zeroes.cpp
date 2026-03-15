class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int swapLocation = 0;
        int ptr = 0;

        while (ptr < nums.size()) {
            if (nums[ptr] != 0) {
                std::swap(nums[swapLocation], nums[ptr]);
                swapLocation++;
            }

            ptr++;
        }
    }
};