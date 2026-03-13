class Solution {
public:
    string removeStars(string s) {
        std::string noStars;

        for (int i{}; i < s.length(); i++) {
            if (s[i] == '*') {
                noStars.pop_back();
            } else {
                noStars.push_back(s[i]);
            }
        }

        return noStars;
    }
};