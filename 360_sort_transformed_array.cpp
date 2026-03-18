class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        for (int i{}; i < nums.size(); i++) {
            int x = nums[i];
            int sum = a * x * x + b * x + c;
            nums[i] = sum;
        }

        auto max = std::max_element(nums.begin(), nums.end());
        auto min = std::min_element(nums.begin(), nums.end());

        if (*max == nums[0] && *min == nums[nums.size() - 1]) { // monotonic decrease
            std::reverse(nums.begin(), nums.end());
            return nums;
        } else if (*max == nums[nums.size() - 1] && *min == nums[0]) {
            return nums;
        } else if ((*max > nums[nums.size() - 1] && *max > nums[0]) ||
                   (*min < nums[nums.size() - 1] && *min < nums[0]))
        {
            std::vector<int> sorted;

            if (*max == nums[nums.size() - 1] || *max == nums[0]) {
                int minIndex = std::distance(nums.begin(), min);
                int left = minIndex;
                int right = minIndex + 1;

                while (left >= 0 && right < nums.size()) {
                    if (nums[left] < nums[right]) {
                        sorted.push_back(nums[left]);
                        left--;
                    } else {
                        sorted.push_back(nums[right]);
                        right++;
                    }
                }

                while (left >= 0) {
                    sorted.push_back(nums[left]);
                    left--;
                }

                while (right < nums.size()) {
                    sorted.push_back(nums[right]);
                    right++;
                }

            } else {
                int left = 0;
                int right = nums.size() - 1;

                while (left <= right) {
                    if (nums[left] < nums[right]) {
                        sorted.push_back(nums[left]);
                        left++;
                    } else {
                        sorted.push_back(nums[right]);
                        right--;
                    }
                }

            }

            return sorted;
        }

        return nums;
    }
};