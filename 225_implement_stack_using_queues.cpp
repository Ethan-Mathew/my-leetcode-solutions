class MyStack {
    std::queue<int> q1;
    std::queue<int> q2;
    std::queue<int>* activeQueue;
    std::queue<int>* inactiveQueue;
    
public:
    MyStack() {
        activeQueue = &q1;
        inactiveQueue = &q2;
    }
    
    void push(int x) {
        activeQueue->push(x);
    }
    
    int pop() {
        while (activeQueue->size() > 1) {
            inactiveQueue->push(activeQueue->front());
            activeQueue->pop();
        }
        int ret = activeQueue->front();
        activeQueue->pop();
        std::swap(activeQueue, inactiveQueue);
        
        return ret;
    }
    
    int top() {
        return activeQueue->back();
    }
    
    bool empty() {
        return activeQueue->size() == 0;
    }
};
