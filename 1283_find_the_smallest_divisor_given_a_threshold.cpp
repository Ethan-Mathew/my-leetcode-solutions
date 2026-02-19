class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = *std::max_element(nums.begin(), nums.end());

        int i = -1;
        while (left <= right) {
            int mid = (right + left) / 2;

            if (testDivisor(nums, threshold, mid)) {
                i = mid;
                right = mid - 1;
            } else if (!testDivisor(nums, threshold, right)) {
                break;
            } else {
                left = mid + 1;
            }
        }

        return i;
    }

    bool testDivisor(std::vector<int>& nums, int threshold, double divisor) {
        int sum = 0;
        for (int num : nums) {
            sum += std::ceil(num / divisor);
        }

        if (sum <= threshold) {
            return true;
        }

        return false;
    }
};