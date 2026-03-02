class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int units = matrix.size() * matrix[0].size();
        int numCols = matrix[0].size();

        int left = 0;
        int right = units - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            
            int midVal = matrix[static_cast<int>(mid / numCols)][mid % numCols];

            if (midVal == target) {
                return true;
            } else if (midVal > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return false;
    }
};