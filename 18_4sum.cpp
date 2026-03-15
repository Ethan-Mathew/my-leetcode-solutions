class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> quadruplets;
        int ptr1 = 0;

        while (ptr1 < (int)nums.size() - 3) {
            int ptr2 = ptr1 + 1;

            while (ptr2 < (int)nums.size() - 2) {
                int ptr3 = ptr2 + 1;
                int ptr4 = (int)nums.size() - 1;

                while (ptr3 < ptr4) {
                    long long sum = (long long)nums[ptr1] + nums[ptr2] + nums[ptr3] + nums[ptr4];
                    if (sum == target) {
                        quadruplets.push_back({nums[ptr1], nums[ptr2], nums[ptr3], nums[ptr4]});
                        while (ptr3 < ptr4 && nums[ptr3] == nums[ptr3 + 1]) ptr3++;
                        while (ptr3 < ptr4 && nums[ptr4] == nums[ptr4 - 1]) ptr4--;
                        ptr3++;
                        ptr4--;
                    } else if (sum < target) {
                        ptr3++;
                    } else {
                        ptr4--;
                    }
                }

                while (ptr2 < (int)nums.size() - 2 && nums[ptr2] == nums[ptr2 + 1]) ptr2++;
                ptr2++;
            }

            while (ptr1 < (int)nums.size() - 3 && nums[ptr1] == nums[ptr1 + 1]) ptr1++;
            ptr1++;
        }

        return quadruplets;
    }
};