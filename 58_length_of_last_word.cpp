class Solution {
public:
    int lengthOfLastWord(string s) {
        int wordLength;
        bool stringOn = false;

        for(char c : s) {
            if (c != ' ') {
                if (stringOn) {
                    wordLength++;
                } else {
                    wordLength = 1;
                    stringOn = true;
                }
            } else {
                stringOn = false;
            }
        }

        return wordLength;
    }
};