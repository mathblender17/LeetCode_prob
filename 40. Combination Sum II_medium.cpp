class Solution {
public:
/**CORE IDEA: 
Similiar to combination sum I - here repetive of the same element is not allowed  - main problem here is of the duplicates
so we sort the candidates before hand and then a loop to skip till the duplicate elememts - 
this way the LST will include element x then RST will not have x even is duplicate is present ahead(loop used for this)
Time complexity:-O(n*2^n)
Space complexity;-O(n)
This is better than using set vector as space goes to O(n*2^n)

if we are in a situation where we cannot sort the vector - then hash map
**/
    vector<vector<int>>res; 
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cur;
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,target,cur,0,0);
        return res;
    }
    void backtrack(vector<int>& candidates, int target,vector<int>& cur,int i,int total ){
        if(target==total){//satisfying base case
            res.push_back(cur);
            return;
        }
        if(target<total || i==candidates.size()){ //base case if combination not found 
            return;
        }


        cur.push_back(candidates[i]);
        backtrack(candidates,target,cur,i+1,total+candidates[i]);//pick
        cur.pop_back();//popping the picked element before moving to the not pick
        while(i+1 < candidates.size() && candidates[i]==candidates[i+1] ){
            i++;
        }
        backtrack(candidates,target,cur,i+1,total);//not pick

    }
};
