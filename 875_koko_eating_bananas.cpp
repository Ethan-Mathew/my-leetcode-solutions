class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if (h < piles.size()) {
            return -1;
        }

        double upperK = 1;

        while (true) {
            if (testK(upperK, piles, h)) break;
            upperK *= 2;
        }

        int left = upperK / 2;
        int right = upperK;
        int i = -1;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (testK(mid, piles, h)) {
                i = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (i == 0) {
            return 1;
        }

        return i;
    }

    bool testK(double k, std::vector<int>& piles, int h) {
        uint64_t hours = 0;
        for (int i{}; i < piles.size(); i++) {
            hours += std::ceil(piles[i] / k);
        }
        if (hours <= h) {
            return true;
        } 
        return false;
    }
};