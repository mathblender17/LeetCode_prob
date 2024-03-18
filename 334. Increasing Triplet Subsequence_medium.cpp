class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX;// to keep th3 count of the 1st number in teh incresing sequence
        int b = INT_MAX;// 2nd num in the sequence
        for(int i=0; i<nums.size(); i++) {// i foe the 3rd num inthe sequence
            if(nums[i] <= a) a = nums[i];// if ith num is smaller then update a
            if(nums[i] > a && nums[i] <= b) b = nums[i];// if ith num is between a and b update b
            if(nums[i] > a && nums[i] > b) return 1;// if ith num is greater than both a and b
            //return true
        }
        return 0;
    }
};
