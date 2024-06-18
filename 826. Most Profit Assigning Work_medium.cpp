class Solution {
public:
/**
1.use vector of pair  - as they can sorted as a pair
2. sort the vector of pairs
3. use a for and while to travese and check for the matching conditions 
- do keep the time cimplexity low
**/
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> jobs;
       
        for(int i=0;i<difficulty.size();i++){
            jobs.emplace_back(difficulty[i],profit[i]);
        }
        sort(jobs.begin(),jobs.end());
        sort(worker.begin(),worker.end());
        int j=0, maxProfit=0, tempProfit=0;

        for(int capabale : worker){
            while(j<jobs.size() && jobs[j].first<=capabale){
                tempProfit=max(jobs[j].second,tempProfit);
                j++;
            }
            maxProfit+=tempProfit;
        }
        return maxProfit;
    }
};
