class Solution {
public:
    string decodeString(string s) {
        std::string finalString = "";
        std::string internalString = "";
        std::string multiplier = "";
        std::stack<char> brackets;

        bool extractingString = false;
        int sPtr = 0;

        while (sPtr < s.length()) {
            if (std::isdigit(s[sPtr]) && !extractingString) {
                multiplier += s[sPtr];
            } else if (s[sPtr] == '[') {
                if (extractingString) {
                    internalString += '[';
                } else {
                    extractingString = true;
                }

                brackets.push('[');
            } else if (s[sPtr] == ']') {
                brackets.pop();

                if (!brackets.empty()) {
                    internalString += ']';
                }
            } else if (extractingString) {
                internalString += s[sPtr];
            } else {
                finalString += s[sPtr];
            }

            if (brackets.empty() && extractingString) {
                std::string expandedString = decodeString(internalString);

                for (int i{}; i < std::stoi(multiplier); i++) {
                    finalString += expandedString;
                }
                
                internalString = "";
                multiplier = "";
                extractingString = false;
            }

            sPtr++;
        }

        return finalString;
    }
};