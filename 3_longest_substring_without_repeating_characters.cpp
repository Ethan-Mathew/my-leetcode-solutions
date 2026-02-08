class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> window_characters;
        int longest_substring = 0;
        int left_ptr = 0;

        for (int right_ptr{}; right_ptr < s.length(); right_ptr++)
        {
            window_characters[s[right_ptr]]++;

            while (window_characters[s[right_ptr]] > 1)
            {
                window_characters[s[left_ptr]]--;
                left_ptr++;
            }

            longest_substring = std::max(longest_substring, right_ptr - left_ptr + 1);
        }

        return longest_substring;
    }
};