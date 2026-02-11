class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int pos = digits.size() - 1;

        while (pos >= 0)
        {
            if (digits[pos] + 1 < 10)
            {
                digits[pos]++;
                return digits;
            }

            digits[pos] = 0;
            pos--;
        }

        std::vector<int> larger_result(digits.size() + 1, 0);
        larger_result[0] = 1;

        return larger_result;
    }
};