class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int upperMax = 1;

        while (!testMax(weights, days, upperMax)) {
            upperMax <<= 1;
        }

        int lowerMax = upperMax >> 1;
        int i = -1;

        while (lowerMax <= upperMax) {
            int mid = (upperMax + lowerMax) / 2;

            if (testMax(weights, days, mid)) {
                i = mid;
                upperMax = mid - 1;
            } else if (testMax(weights, days, upperMax)) {
                lowerMax = mid + 1;
            } else {
                break;
            }
        }

        return i;
    }

    bool testMax(std::vector<int>& weights, int days, int max) {
        
        int runningSum = 0;
        int testDays = 0;
        for (int i{}; i < weights.size(); i++) {
            if (weights[i] > max) {
                return false;
            }

            if (runningSum + weights[i] > max) {
                testDays++;
                runningSum = weights[i];
            } else {
                runningSum += weights[i];
            }
        }

        testDays++;

        if (testDays <= days) {
            return true;
        } else {
            return false;
        }
    }
};