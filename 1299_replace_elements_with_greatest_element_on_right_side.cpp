class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        std::vector<int> prefixRight(arr.size(), -1);

        int currLargest = arr[arr.size() - 1];
        for (int i = (arr.size() - 2); i >= 0; i--) {
            if (arr[i + 1] > currLargest) {
                currLargest = arr[i + 1];
            }

            prefixRight[i] = currLargest;
        }

        return prefixRight;
    }
};