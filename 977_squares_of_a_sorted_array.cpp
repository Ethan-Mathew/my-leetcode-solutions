class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int i = -1;
        while (left <= right) {
            int mid = (right + left) / 2;
            if (nums[mid] >= 0) {
                i = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        std::cout << i;

        for (int i{}; i < nums.size(); i++) {
            nums[i] = nums[i] * nums[i];
        }

        if (i == 0) {
            return nums;
        } else if (i == -1) {
            left = 0;
            right = nums.size() - 1;

            while (left <= right) {
                std::swap(nums[left], nums[right]);
                left++;
                right--;
            }
            return nums;
        } else {
            std::vector<int> solutions;

            int pos = i;
            int neg = i - 1;

            while (pos < nums.size() && neg >= 0) {
                if (nums[pos] < nums[neg]) {
                    solutions.push_back(nums[pos]);
                    pos++;
                } else {
                    solutions.push_back(nums[neg]);
                    neg--;
                }
            }

            while (pos < nums.size()) {
                solutions.push_back(nums[pos]);
                pos++;
            }

            while (neg >= 0) {
                solutions.push_back(nums[neg]);
                neg--;
            }

            return solutions;
        }

        return nums;
    }
};