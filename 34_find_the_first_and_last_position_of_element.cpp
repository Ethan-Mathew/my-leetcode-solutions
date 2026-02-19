class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        std::vector<int> solutions;

        int i = -1;
        while (left <= right) {
            int mid = (right + left) / 2;

            if (nums[mid] == target) {
                i = mid;
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        solutions.push_back(i);
        left = 0;
        right = nums.size() - 1;
        i = -1;
        while (left <= right) {
            int mid = (right + left) / 2;

            if (nums[mid] == target) {
                i = mid;
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        solutions.push_back(i);

        return solutions;
    }
};