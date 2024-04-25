class Solution {
public:
/**
subtract from the target the candidates[i] if it goes below 0 backtrack else ==0 add in the seq

**/
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> seq;
        backtrack(seq,res,0,target,candidates);
        return res;
    }
    void backtrack(vector<int>& seq, vector<vector<int>>& res, int start, int target, const vector<int>& candidates ){
        if(target == 0){
            res.push_back(seq);
            return ;
        }
        if(target < 0){
            return;
        }
        for(int i= start;i<candidates.size();++i){
            seq.push_back(candidates[i]);
            backtrack(seq,res,i,target-candidates[i],candidates);
            seq.pop_back();
        }
    }
};
