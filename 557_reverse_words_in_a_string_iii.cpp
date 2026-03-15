class Solution {
public:
    string reverseWords(string s) {
        int left = 0;
        for (int i{}; i < s.length(); i++) {
            if (s[i] == ' ') {
                int right = i - 1;
                reverse(s, left, right);
                left = i + 1;
            } else if (i == s.length() - 1) {
                int right = i;
                reverse(s, left, right);
                return s;
            }
        }

        return s;
    }

    void reverse(std::string& s, int left, int right) {
        while (left <= right) {
            std::swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};