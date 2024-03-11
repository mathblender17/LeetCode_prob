class Solution {
public:
    int maxProfit(vector<int>& prices) {
       // Approach 1 :- 
        int n = prices.size();
        if (n <= 1) {
            return 0;  // No profit can be made with less than two prices
        }

        int maxProfit = 0;
        int i = 0;

        while (i < n - 1) {
            // Find the local minimum (buy point)
            while (i < n - 1 && prices[i] >= prices[i + 1]) {
                i++;
            }
            int bp = prices[i];

            // Find the local maximum (sell point)
            while (i < n - 1 && prices[i] <= prices[i + 1]) {
                i++;
            }
            int sp = prices[i];

            // Calculate and accumulate profit
            maxProfit += std::max(0, sp - bp);
        }

        return maxProfit;
        
    }
};
// approasch 2:
//int maxProfit(vector<int>& prices) {
//        int max = 0;
//        int start = prices[0];
//        int len = prices.size();
//        for(int i = 1;i<len; i++){
//            if(start < prices[i]){
//                max += prices[i] - start;
 //           }
//            start = prices[i];
//        }
//        return max;
