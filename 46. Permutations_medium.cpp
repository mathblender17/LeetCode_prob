class Solution {
public:
/**CORE Idea: decesion trees with a freq/pick arr to specify if is it picked or not - then recurse and backtrack
**/
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        int freq[n]; keeps track of picked not picked
        for(int i=0;i<nums.size();i++){
            freq[i]=0;
        }
        vector<int> cur;
        vector<vector<int>> res;
        backtrack(freq,nums,cur,res);
        return res;
    }
    void backtrack(int freq[],vector<int>& nums,vector<int>& cur,vector<vector<int>>& res){

        if(cur.size()==nums.size()){ //when the  cur is full - a possile permutation add in he res 
            res.push_back(cur);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(freq[i]!=1){//skip the picked elements
                cur.push_back(nums[i]);
                freq[i]=1;

                backtrack(freq,nums,cur,res);//recursive check till base case is hit 
                freq[i]=0;
                cur.pop_back();//move to another prolly RST after popping - backtrack
            }
        }
        
    }
};
