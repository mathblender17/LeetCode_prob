class Solution {
public:
    int candy(std::vector<int>& ratings) {
        //store the candies in a separate vecrtor
        ///ieterate 1st from start and then 2nd from the end
        // the just calc the the candies 
        int n = ratings.size();
        vector<int> candies(n, 1);

        for (int i = 1; i < n; ++i) { // compared with the predecuyssor - from start
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; --i) {//compared withe the succesor - from end
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        int totalCandies = 0;
        for (int candy : candies) {
            totalCandies += candy;
        }

        return totalCandies;
    }
};
