class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size() - 1;
        long long subsequences = 0;
        long long mod = std::pow(10, 9) + 7;

        std::vector<long long> pows(nums.size(), 1);

        for (int i{1}; i < nums.size(); i++) {
            pows[i] = (pows[i - 1] * 2) % mod;
        }

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                subsequences += pows[right - left];
                subsequences = subsequences % mod;
                left++;
            } else {
                right--;
            }
        }

        return subsequences % mod;
    }
};