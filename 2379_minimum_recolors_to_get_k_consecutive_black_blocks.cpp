class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int currInWindow = 0;

        // init window
        for (int i{}; i < k; i++) {
            if (blocks[i] == 'B') {
                currInWindow++;
            }
        }

        int currentBestOps = k - currInWindow;
        int left = 0;
        int right = k - 1;

        while(right < blocks.size() - 1) {
            if (blocks[left] == 'B') {
                currInWindow--;
            }
            left++;

            right++;
            if (blocks[right] == 'B') {
                currInWindow++;
            }

            currentBestOps = std::min(k - currInWindow, currentBestOps);
        }

        return currentBestOps;
    }
};