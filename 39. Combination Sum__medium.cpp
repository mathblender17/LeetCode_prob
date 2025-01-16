class Solution {
public:
/**
CORE IDEA: Using recuring "Pick not Pick method " 
A type of decesion tree we use where if we pick a element on left decesion tree we never pick that element on  the right decesion tree - solvese the uniquess problem
When picked subtract the eleemtn from the target and recurse & when not picked increment the i by 1
while changing from left(pick) sundtree to right - we pop the picked element from the list
if target==0 push curr in the res & if target<0 || i>=size(condidates) backtrack
**/
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        backtrack(candidates,target,curr,0);
        return res;
    }
    void backtrack(vector<int>& candidates,int target,vector<int>& curr,int i){
        if(target==0){
            res.push_back(curr);
            return;
        }
        if(target<0 || i>=candidates.size()){
            return;
        }
        curr.push_back(candidates[i]);
        backtrack(candidates,target-candidates[i],curr,i);
        curr.pop_back();
        backtrack(candidates,target,curr,i+1);
    }
};
