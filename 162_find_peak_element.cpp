class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        
        while (left <= right) {
            mid = (right + left) / 2;

            long rightCheck = (mid + 1 >= nums.size()) ? std::numeric_limits<long>::min() : nums[mid + 1];
            long leftCheck = (mid - 1 < 0) ? std::numeric_limits<long>::min() : nums[mid - 1];

            if (nums[mid] > rightCheck && nums[mid] > leftCheck) {
                break;
            } else if (nums[mid] < rightCheck) {
                left = mid + 1;
            } else if (nums[mid] > rightCheck) {
                right = mid;
            }
        }
        
        return mid;
    }
};