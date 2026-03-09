class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int allLonelyBlacks = 0;
        std::unordered_map<int, std::pair<int, bool>> takenColumns;

        for (int n{}; n < picture.size(); n++) {
            std::vector<int> columns;
            for (int m{}; m < picture[0].size(); m++) {
                if (picture[n][m] == 'B') {
                    columns.push_back(m);
                }
            }

            if (columns.size() == 1) {
                if (takenColumns[columns[0]].first == 0) {
                    takenColumns[columns[0]].first++;
                    takenColumns[columns[0]].second = true;
                    allLonelyBlacks++;
                } else if (takenColumns[columns[0]].first == 1 && takenColumns[columns[0]].second) {
                    allLonelyBlacks--;
                    takenColumns[columns[0]].first++;
                    takenColumns[columns[0]].second = false;
                } else {
                    takenColumns[columns[0]].first++;
                }
            } else if (columns.size() > 1) {
                for (int col : columns) {
                    if (takenColumns[col].first == 1 && takenColumns[col].second) {
                        allLonelyBlacks--;
                        takenColumns[col].second = false;
                    } else {
                        takenColumns[col].first++;
                        takenColumns[col].second = false;
                    }
                }
            }
        }

        return allLonelyBlacks;
    }