class Solution {
public:
/**
We solve the problem using Binary search
where high is the sum of all elemets and low is the max element
the partition must be less than the mid if the sum is not less then
then they become a part of the new partition - hence no need to worry about the no. of partitions
check() is used to check the sum of the partitions return true or false
as we want the Minimum amoung the Maximum we move in that part in binary search
**/
    bool check(int mid,vector<int>& nums,int k){
        int sum=0,c=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mid)false;
            sum+=nums[i];
            if(sum>mid){
                c++;
                sum=nums[i];
            }
            
        }
        if(c<=k)return true;
        return false;
    }

     int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end()),h=accumulate(nums.begin(),nums.end(),0);
        int ans;
        while(l<=h){
            int mid=(l+h)/2;
            if(check(mid,nums,k)){
            ans = mid;
            h=mid-1;
            }
            else{
            l=mid+1;
            }
        }
        return ans;
    }


};
