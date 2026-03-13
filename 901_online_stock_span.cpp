class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int totalSpan = 1;
        while (spans.size() > 0) {
            if (price >= spans.top().first) {
                totalSpan += spans.top().second;
                
                spans.pop();

            } else {
                break;
            }
        }

        spans.push(std::pair<int,int>{price, totalSpan});
        return totalSpan;
    }

    std::stack<std::pair<int, int>> spans;
};