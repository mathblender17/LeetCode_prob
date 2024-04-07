class Solution {
public:
//A great question
/**
it can be divided in to 3 parts -
1.to find the max num in the arrays
2.mergeing them
3. taking the best from different merging combination to take from the 2 arrays
**/ 
   vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1=nums1.size(),n2=nums2.size();
        vector<int> best;
        for(int k1=max(k-n2,0);k1<=min(k,n1);++k1){
            //goping throuhg all combinations and selecting the best         
            best = max(best, maxNumber(maxNumber(nums1, k1),
                                       maxNumber(nums2, k-k1)));
        }
        return best;
    }

    vector<int>maxNumber(vector<int> nums, int k){
        //to find the greater number inthe given array for each combination
        int drop=nums.size()-k;
        vector<int> out;
        for(int num : nums){
            while(drop && out.size() && out.back()<num ){
                out.pop_back();
                drop--;
            }
            out.push_back(num);
        }out.resize(k);
        return out;
    }

    vector<int> maxNumber(vector<int> nums1, vector<int> nums2){
        //to merge the marray of greater nums into one and
        //then to be compared with the previous best and update it 
        // after going throuhg all the combination the best is returned
        vector<int> out;
        while(nums1.size()+nums2.size()){
        vector<int>& now= nums1>nums2?nums1:nums2;
        out.push_back(now[0]);
        now.erase(now.begin()); 
        } 
        return out;
    }
};
