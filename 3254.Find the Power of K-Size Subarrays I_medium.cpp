class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        int t= n-k+1;
        vector<int> result(t,-1);
        int comp = 0;
        //edge cases
        if(n<k){
            return result;
        }
        if(n==1 || k == 1){
            for(int i=0;i<n;i++){
                result[i]=nums[i];
            }return result;
        }
        // step 1: take a look at each k sub array

        for (int i = 0; i <= n - k; i++) {
            comp = 0;
            for (int j = i; j < i + k - 1; j++) {

                // getting the subarray done
                // step 2: to check if they are in asending and consequtive
                if (nums[j] < nums[j + 1] && nums[j] + 1 == nums[j + 1]) {
                    comp++;
                }
            }

            // step 3: tally the no. of comparison
            if (comp == k - 1) {
                result[i] = nums[i + k - 1];
            } //else {
               // result[i] = -1;
            //}
        }
        return result;
    }
};
