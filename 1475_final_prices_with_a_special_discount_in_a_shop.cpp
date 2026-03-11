class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        if (prices.size() == 1) {
            return prices;
        }

        std::vector<int> finalPrices(prices.begin(), prices.end());

        std::stack<int> passedPrices;
        passedPrices.push(prices[prices.size() - 1]);

        std::stack<int> passedPricesHolder;

        
        for (int i{static_cast<int>(prices.size() - 2)}; i >= 0; i--) {
            
            while (true) {
                if (!passedPrices.empty()) {
                    if (prices[i] >= passedPrices.top()) {
                        finalPrices[i] -= passedPrices.top();
                        break;
                    } else {
                        passedPricesHolder.push(passedPrices.top());
                        passedPrices.pop();
                    }
                } else {
                    break;
                }
            }
            
            while (passedPricesHolder.size() > 0) {
                passedPrices.push(passedPricesHolder.top());
                passedPricesHolder.pop();
            }
            

            passedPrices.push(prices[i]);
        }
       
        return finalPrices;
    }
};