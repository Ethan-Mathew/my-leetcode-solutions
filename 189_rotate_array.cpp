class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        k = k % nums.size();

        while (left <= right) {
            std::swap(nums[left], nums[right]);
            left++;
            right--;
        }

        left = 0;
        right = k - 1;

        while (left <= right) {
            std::swap(nums[left], nums[right]);
            left++;
            right--;
        }

        left = k;
        right = nums.size() - 1;

        while (left <= right) {
            std::swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
};