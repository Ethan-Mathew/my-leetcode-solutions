class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        std::stack<int> pushedSequence;
        int poppedPtr = 0;

        for (int num : pushed) {
            pushedSequence.push(num);

            while (!pushedSequence.empty() && pushedSequence.top() == popped[poppedPtr]) {
                pushedSequence.pop();
                poppedPtr++;
            }
        }
        

        return pushedSequence.empty();
    }
};