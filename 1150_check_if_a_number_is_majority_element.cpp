class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        int leftIndex = findLeft(nums, target);
        int rightIndex = findRight(nums, target);

        if (leftIndex == -1 || rightIndex == -1) {
            return false;
        }

        return (rightIndex - leftIndex) + 1 > nums.size() / 2;
    }

    int findLeft(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int i = -1;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                i = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }



        return i;
    }

    int findRight(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int i = -1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                i = mid;
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return i;
    }
};