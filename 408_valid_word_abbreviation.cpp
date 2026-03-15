class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int wPtr = 0;
        int abbrPtr = 0;

        for (int i = 0; i < abbr.length(); i++) {
            if (std::isdigit(abbr[i])) {
                if (abbr[i] == '0') return false;
                std::string number = "";
                while (i < abbr.length() && std::isdigit(abbr[i])) {
                    number += abbr[i];
                    i++;
                }
                i--;
                wPtr += std::stoi(number);
            } else {
                if (wPtr >= word.length() || word[wPtr] != abbr[i]) {
                    return false;
                }
                wPtr++;
            }
        }
        return wPtr == word.length();
    }