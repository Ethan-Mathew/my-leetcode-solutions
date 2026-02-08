class Solution
{
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int length = nums.size();
        int sum = 0;
        int shortest_subarray = 100001;
        int left_ptr = 0;

        for (int i{}; i < length; i++)
        {
            sum += nums[i];

            while (sum >= target)
            {
                int current_subarray = i - left_ptr + 1;
                shortest_subarray = std::min(shortest_subarray, current_subarray);

                sum -= nums[left_ptr];
                left_ptr++;
            }
        }

        return (shortest_subarray == 100001) ? 0 : shortest_subarray;
    }
};