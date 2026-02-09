class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        int shortest_string = strs[0].length();

        for (int i{1}; i < strs.size(); i++)
        {
            shortest_string = std::min(shortest_string, static_cast<int>(strs[i].length()));
        }

        int letter_index = 0;
        std::string prefix = "";
        bool done = false;

        while (letter_index < shortest_string)
        {
            char current_letter = strs[0][letter_index];

            for (int i{1}; i < strs.size(); i++)
            {
                if (strs[i][letter_index] != current_letter)
                {
                    done = true;
                    break;
                }
            }

            if (done) break;
            
            prefix += current_letter;
            letter_index++;
        }

        return prefix;
    }
};