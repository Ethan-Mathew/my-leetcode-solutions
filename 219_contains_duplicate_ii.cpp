class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        int left_ptr = 0;
        int right_ptr = k;

        std::unordered_map<int, int> frequency_table;
        // Initialize k-length map
        for (int i{}; i <= k; i++)
        {
            frequency_table[nums[i]]++;

            if (frequency_table[nums[i]] > 1)
            {
                return true;
            }
        }

        while (right_ptr < nums.size() - 1)
        {
            right_ptr++;
            frequency_table[nums[right_ptr]]++;

            if (frequency_table[nums[left_ptr]] > 1)
            {
                frequency_table[nums[left_ptr]]--;
            }
            else
            {
                frequency_table.erase(nums[left_ptr]);
            }
            left_ptr++;

            if (frequency_table[nums[right_ptr]] > 1)
            {
                return true;
            }
        }

        return false;
    }
};