class Solution {
    /** CORE IDEA : to go through the prices list and have the min price as well as the max profit
    for each price min price is upadated if the curr price < min price
    also the profit is calculated for each price and comapared to the max profit
    kinda like DP  
    **/
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n <=1 )return 0;

        int maxProfit = 0;
        int minPrice= prices[0];

        for(int i=1;i<n;i++){
            maxProfit=max(maxProfit , prices[i]-minPrice);
            minPrice=min(minPrice , prices[i]);
        }
        return maxProfit;
    }
};
