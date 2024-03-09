
class Solution {
public:
    //using greedy approach
    //at each step from the 1st index it calculates 
    //the max betwen  it can go and the step from the previous step
    //then start jumping from the 0th index 
    //and setting updating index to it's value after each itr 
    int jump(vector<int>& nums) {

      for(int i = 1; i < nums.size(); i++)
      {
        nums[i] = max(nums[i] + i, nums[i-1]);
      }

      int ind = 0;
      int ans = 0;

      while(ind < nums.size() - 1)
      {
        ans++;
        ind = nums[ind];
      }

      return ans;
    }
};
