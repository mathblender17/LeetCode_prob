class Solution {
public:
/**
CORE IDEA: to use back tracking to get all the unique possible subsets(power set)
think of it as a tree with 2 choices - to take the num or not take the num

other ways :- iteartive method - empty set is already added 
then we iterate through all the elements in the num array will combing it existing sunsets in res

other way:- bit manipulation - num.size will be the no. of bits we use
from 0 to 2^n - 1, will give all the possible combination of soltions(1-take , 0-leave)
**/
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums,0,subset,res);
        return res;
    }
private:
    void dfs(vector<int>& nums,int i,vector<int>& subset,vector<vector<int>>& res){
        if(i>=nums.size()){//i is the index in num - to know where to stop - like the leveles of the tree
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);//with the num included 
        dfs(nums,i+1,subset,res);
        subset.pop_back();//without the num 
        dfs(nums,i+1,subset,res);
    }
};
