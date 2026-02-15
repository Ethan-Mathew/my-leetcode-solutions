class Solution {
public:
    int scoreOfString(string s) {
        int total = 0;
        
        for (int i{1}; i < s.length(); i++)
        {
            total += abs(static_cast<int>(s[i]) - static_cast<int>(s[i - 1]));
        }

        return total;
    }

    int abs(int num)
    {
        return (num < 0) ? -num : num;
    }
};