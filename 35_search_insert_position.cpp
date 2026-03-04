class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 1) {
            return (nums[0] < target) ? 1 : 0;
        }

        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = (right + left) / 2;

            // Case where insertion point is found
            if (mid == nums.size() - 1) {
                return nums.size();
            } else if (nums[mid] < target && nums[mid + 1] >= target) {
                return mid + 1;
            } else if (nums[mid] < target) {
                left = left + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return 0;
    }
};