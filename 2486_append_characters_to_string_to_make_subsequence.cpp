class Solution {
public:
    int appendCharacters(string s, string t) {
        
        int ptr = 0;
        for (int i{}; i < t.size(); i++) {
            bool found = false;
            while (ptr < s.size()) {
                if (s[ptr] == t[i]) {
                    ptr++;
                    found = true;
                    break;
                }

                ptr++;
            }

            if (!found) {
                return (t.size() - i);
            }
        }

        return 0;
    }
};