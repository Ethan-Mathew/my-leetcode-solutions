class Solution {
public:
    void reverseWords(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            std::swap(s[left], s[right]);
            left++;
            right--;
        }
        
        int ptr = 0;
        left = 0;
        while (ptr <= s.size()) {
            if (s[ptr] == ' ' || ptr == s.size()) {
                right = ptr - 1;

                while (left < right) {
                    std::swap(s[left], s[right]);
                    left++;
                    right--;
                }

                left = ptr + 1;
                ptr++;
            } else {
                ptr++;
            }
        }
    }
};