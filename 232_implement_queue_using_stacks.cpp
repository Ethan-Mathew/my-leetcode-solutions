class MyQueue {
private:
    std::stack<int> activeStack;
    std::stack<int> inactiveStack;
public:
    MyQueue() {
    }
    
    void push(int x) {
        activeStack.push(x);
    }
    
    int pop() {
        while(activeStack.size() > 1) {
            inactiveStack.push(activeStack.top());
            activeStack.pop();
        }

        int ret = activeStack.top();
        activeStack.pop();

        while(!inactiveStack.empty()) {
            activeStack.push(inactiveStack.top());
            inactiveStack.pop();
        }

        return ret;
    }
    
    int peek() {
        while(activeStack.size() > 1) {
            inactiveStack.push(activeStack.top());
            activeStack.pop();
        }

        int ret = activeStack.top();

        while(!inactiveStack.empty()) {
            activeStack.push(inactiveStack.top());
            inactiveStack.pop();
        }

        return ret;
    }
    
    bool empty() {
        return activeStack.empty();
    }
};