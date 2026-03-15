class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int spacesPtr = 0;
        int sPtr = 0;
        std::string finalString = "";

        while (spacesPtr < spaces.size()) {
            for (int i{sPtr}; i < spaces[spacesPtr]; i++) {
                finalString += s[i];
            }

            finalString += " ";
            sPtr = spaces[spacesPtr];
            spacesPtr++;
        }

        for (int i{sPtr}; i < s.length(); i++) {
            finalString += s[i];
        }

        return finalString;
    }
};