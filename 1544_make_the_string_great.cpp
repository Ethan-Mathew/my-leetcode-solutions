class Solution {
public:
    string makeGood(string s) {
        std::string goodString = "";
        std::stack<int> pendingIndices;
        pendingIndices.push(0);
        std::unordered_set<int> eliminatedIndices;

        for (int i{1}; i < s.length(); i++) {
            if (!pendingIndices.empty()) {
                if (s[pendingIndices.top()] != s[i] && std::toupper(s[pendingIndices.top()]) == std::toupper(s[i])) {
                    eliminatedIndices.insert(i);
                    eliminatedIndices.insert(pendingIndices.top());
                    pendingIndices.pop();
                } else {
                    pendingIndices.push(i);
                }
            } else {
                pendingIndices.push(i);
            }
        }

        for (int i{}; i < s.length(); i++) {
            if (eliminatedIndices.find(i) == eliminatedIndices.end()) {
                goodString.push_back(s[i]);
            }
        }

        return goodString;
    }
};