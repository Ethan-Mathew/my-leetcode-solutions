class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (int i{}; i < words.size(); i++) {
            int left = 0;
            int right = words[i].size() - 1;

            while (left <= right) {
                if (words[i][left] != words[i][right]) {
                    break;
                }
                left++;
                right--;
            }

            if (left >= right) {
                return words[i];
            }
        }

        return "";
    }
};