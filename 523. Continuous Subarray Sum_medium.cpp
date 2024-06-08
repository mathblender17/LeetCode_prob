class Solution {
public:
/**
we can use the 2 pointer methid to do this but it fails in laregr numbers 
as - O(n^2) time complexity
So for to get O(n) - we use hash map to keep the remainderrs
1.intialise the hashmap to store the remainder values and thier first occurance index
2.find the culmulative sum from each index from i=0 and check for remainder values
3.if values found return true else add it in the hash map
4. if all fails return false in the end
*/
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> remInd;
        rem[-1]=0;
        int cumSum=0;

        for(int i=0;i<n;i++){
            cumSum+=nums[i];

            int r= k==0 ? cumSum: (cumSum%k);

            if(remInd.count(r)){

                if(i - remInd[r] > 1){
                    return true;
                }
            }
            else{
                    remInd[r]=i;
                }
        }
        return false;
    }
};
