class Solution {
public:
    int guessNumber(int n) {
        long left = 1;
        long right = n;

        while (left <= right) {
            long mid = (right + left) / 2;

            if (guess(mid) == 0) {
                return mid;
            } else if (guess(mid) == -1) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
};