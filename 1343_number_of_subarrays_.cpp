class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int total = 0;
        double current_avg = 0;

        for (int i{}; i < k; i++)
        {
            current_avg += arr[i];
        }

        current_avg /= k;
        if (current_avg >= threshold) total++;

        int left_ptr = 0;
        for (int right_ptr{k}; right_ptr < arr.size(); right_ptr++)
        {
            current_avg *= k;
            current_avg -= arr[left_ptr];
            left_ptr++;

            current_avg += arr[right_ptr];
            current_avg /= k;

            if (current_avg >= threshold) total++;
        }

        return total;
    }
};