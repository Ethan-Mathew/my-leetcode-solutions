class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        std::string string1 = "";
        for (const std::string& word : word1) {
            string1 += word;
        }

        std::string string2 = "";
        for (const std::string& word : word2) {
            string2 += word;
        }

        return string1 == string2;
    }
};