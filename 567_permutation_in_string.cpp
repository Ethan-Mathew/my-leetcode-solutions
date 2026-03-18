class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::unordered_map<char, int> s1Table;
        for (char c : s1) {
            s1Table[c]++;
        }

        // sliding window init
        int right = s1.length() - 1;
        std::unordered_map<char, int> s2Table;
        for (int i{}; i <= right; i++) {
            s2Table[s2[i]]++;
        }
        
        if (s1Table == s2Table) {
            return true;
        }

        int left = 0;
        right = s1.length() - 1;
        while (right < s2.length() - 1) {
            if (s2Table[s2[left]] == 1) {
                s2Table.erase(s2[left]);
            } else {
                s2Table[s2[left]]--;
            }

            left++;
            right++;
            s2Table[s2[right]]++;           
            
            if (s1Table == s2Table) {
                return true;
            }
        }

        return false;
    }
};
