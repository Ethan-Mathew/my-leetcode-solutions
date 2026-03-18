class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) {
            return "";
        }

        std::unordered_map<char, int> tMap;
        for (char c : t) {
            tMap[c]++;
        }
        std::unordered_set<char> tSet(t.begin(), t.end());
        //std::unordered_set<char> sRelevantSet();

        std::unordered_map<char, int> matchedChars;
        std::string shortestSubstring(s.begin(), s.end());

        int right = 0;
        int left = 0;

        int need = t.length();
        bool altered = false;

        while (right < s.length()) {
            //std::cout << right << '\n';

            if (tSet.find(s[right]) != tSet.end()) {
                matchedChars[s[right]]++;

                if (matchedChars[s[right]] <= tMap[s[right]]) {
                    need--;
                }
            }

            if (need == 0) {
                left = pruneLeft(s, tMap, matchedChars, tSet, left, need);
                std::string temp(s.begin() + left, s.begin() + right + 1);

                shortestSubstring = (temp.length() < shortestSubstring.length()) ? temp : shortestSubstring;

                matchedChars[s[left]]--;

                altered = true;

                if (matchedChars[s[left]] < tMap[s[left]]) {
                    need++;
                }

                left++;
            }

            right++;
        }

        std::cout << need;

        return altered ? shortestSubstring : "";
    }

    int pruneLeft(const std::string& s, std::unordered_map<char, int>& tMap, 
                  std::unordered_map<char, int>& matchedChars, std::unordered_set<char>& tSet,
                  int left, int& need)
    {
        while (true) {
            if (tMap.find(s[left]) != tMap.end()) {
                
                matchedChars[s[left]]--;

                // try to remove relevant character
                if (matchedChars[s[left]] == 0 || matchedChars[s[left]] < tMap[s[left]]) {
                    matchedChars[s[left]]++;
                    return left;
                } else {
                    left++;
                }

            } else {
                left++;
            }
        }

        return left;
    }
};