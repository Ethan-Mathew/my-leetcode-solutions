class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 0 || num == 1) {
            return true;
        }
        
        long left = 0;
        long right = num;

        while (left <= right) {
            long mid = (left + right) / 2;
            long squared = mid * mid;
            long nextSquared = (mid + 1) * (mid + 1);

            if (squared == num) {
                return true;
            } else if (squared < num && nextSquared > num) {
                return false;
            } else if (squared < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
};