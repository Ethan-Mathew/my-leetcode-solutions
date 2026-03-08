class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        // Construct solution matrix
        int n = mat1.size();
        int m = mat2[0].size();
        std::vector<std::vector<int>> matrixSoln;
        
        for (int i{}; i < n; i++) {
            matrixSoln.push_back(std::vector<int>(m, 0));
        }

        for (int i{}; i < m; i++) {
            // gather data from the i'th column
            std::vector<int> ithColumn;
            for (int j{}; j < mat2.size(); j++) {
                ithColumn.push_back(mat2[j][i]);
            }

            // multiply the column with mat1
            for (int x{}; x < n; x++) {
                for (int y{}; y < ithColumn.size(); y++) {
                    matrixSoln[x][i] += (ithColumn[y] * mat1[x][y]);
                }
            }
        }

        return matrixSoln;
    }
};
