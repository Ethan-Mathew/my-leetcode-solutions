class Solution {
public:
    int minAddToMakeValid(string s) {
        std::stack<char> openingStack;
        int unmatchedClosings = 0;
        
        for (char c : s) {
            if (c == '(') {
                openingStack.push(c);
            } else {
                if (openingStack.size() > 0) {
                    openingStack.pop();
                } else {
                    unmatchedClosings++;
                }
            }
        }

        return unmatchedClosings + openingStack.size();
    }
};