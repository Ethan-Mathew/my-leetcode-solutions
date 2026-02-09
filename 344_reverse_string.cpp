class Solution
{
public:
    void reverseString(vector<char>& s)
    {
        int left_ptr = 0;
        int right_ptr = s.size() - 1;

        while (left_ptr < right_ptr)
        {
            std::swap(s[left_ptr], s[right_ptr]);
            left_ptr++;
            right_ptr--;
        }
    }
};