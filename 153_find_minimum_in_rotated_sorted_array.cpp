class Solution {
public:
    int findMin(vector<int> &nums) {
        int left_ptr = 0;
        int right_ptr = nums.size() - 1;

        while (left_ptr < right_ptr)
        {
            int mid_ptr = left_ptr + (right_ptr - left_ptr) / 2;
            
            if (nums[mid_ptr] < nums[right_ptr])
            {
                right_ptr = mid_ptr;
            }
            else
            {
                left_ptr = mid_ptr + 1;
            }
        }

        return nums[left_ptr];
    }
};