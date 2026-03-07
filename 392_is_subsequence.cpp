class Solution {
public:
    bool isSubsequence(string s, string t) {

        int ptr = 0;
        for(int i{}; i < s.size(); i++) {
            bool charFound = false;
            while (ptr < t.size()) {
                if (t[ptr] == s[i]) {
                    ptr++;
                    charFound = true;
                    break;
                }

                ptr++;
            }

            if (!charFound) return false;
        }

        return true;
    }
};