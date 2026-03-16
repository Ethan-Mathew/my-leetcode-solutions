class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        std::string& longerString = (word1.length() > word2.length()) ? word1 : word2;
        std::string merged = "";
        for (int i{}; i < std::min(word1.length(), word2.length()); i++) {
            merged += word1[i];
            merged += word2[i];
        }

        for (std::size_t i{std::min(word1.length(), word2.length())}; i < longerString.length(); i++) {
            merged += longerString[i];
        }

        return merged;
    }
};