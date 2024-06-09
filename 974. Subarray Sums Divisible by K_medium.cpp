class Solution {
public:
/**
same here using 2 pointer method take O(n^2) timne complexity
so hence we a hash map to store the reaminder from modulus operation
for the  count we add the frequency of the repeated remainders it shows
'''
Whenever we encounter the same remainder again, 
it means the subarray between the previous index where this remainder was found 
and the current index has a sum that is divisible by k.
'''

**/
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> remainder;
        remainder[0]=1;
        int count=0,sum=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem = ((sum%k)+k)%k;

            if(remainder.count(rem)){
                count+=remainder[rem];
            }
            remainder[rem]++;
        }  
        return count;
    }
};
