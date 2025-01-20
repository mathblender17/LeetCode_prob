class Solution {
public:
/**
CORE Idea: same as combiation I - at every level of decesion tree decide wheter to pick or not pick 
then move on with the other elements - 
TC;- O(n*2^n)
SC;- O(2^n)
BRUTE FORCE :- just the differece here is that we use a set to eleiminate duplicates
Backtracking - while loop till the last repeated element 
**/
vector<vector<int>>res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> cur;
        sort(nums.begin(),nums.end());
        backtrack(nums,cur,0);
        return res;
    }
    void backtrack(vector<int>& nums,vector<int>& cur,int i){
        if(i>=nums.size()){
            res.push_back(cur);
            return;
        }
        cur.push_back(nums[i]);
        backtrack(nums,cur,i+1);
        cur.pop_back();
        while(i+1<nums.size() && nums[i]==nums[i+1]){
            i++;
        }
        backtrack(nums,cur,i+1);
        
    }
};
