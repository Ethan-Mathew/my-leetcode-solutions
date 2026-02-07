class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> solutions;
        int length = std::size(nums);

        for (int i{}; i < length; i++)
        {
            int product = 1;

            for (int j{}; j < length; j++)
            {
                if (j != i)
                {
                    product *= nums[j];
                }
            }

            solutions.push_back(product);
        }

        return solutions;
    }
};