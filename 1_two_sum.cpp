class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    
        std::unordered_set<int, int> indices;
        int length{ static_cast<int>(nums.size()) };
        
        for (int i{}; i < length; i++)
        {
            int compliment{ target - nums[i] };

            if (indices.find(compliment) != indices.end())
            {
                return {indices[compliment], i};
            }

            indices[nums[i]] = i;
        }
        
        return {};
    }
};