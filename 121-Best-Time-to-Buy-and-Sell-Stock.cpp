class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;  
        int maxProfit = 0;      

        for (int price : prices) 
        {
            // Update minPrice if we find a lower price
            minPrice = min(minPrice, price);

            // Calculate potential profit and update maxProfit
            maxProfit = max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
};
