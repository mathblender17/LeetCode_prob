class Solution {
public:
    int singleNumber(vector<int>& nums) {
       // int n=nums.size();
     //   int count,itr;

     //   for(int i=0;i<n;i++){
    //        itr= nums[i];
     //       count=0;
     //       for(int j=0;j<n;j++){
     //           if(itr == nums[j]){
    //                count++;
     //           }
    //        }
    //        if(count == 1){
    //            break;
    //       }
            
    //    }
   // return itr;
    //O(N^N) - t
//----------------------------------------------------------------------------

//   unordered_map<int,int> a;
//   for(auto x: nums){
//    a[x]++;
//   }
//   for(auto z:a){
//    if(z.second == 1){
//        return z.first;
//    }
//   }
//   return -1;
// O(N)
//-----------------------------------------------------------------------
     sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i+=2)
        {
            if(nums[i]!=nums[i-1])
                return nums[i-1];
        }
        return nums[nums.size()-1];
//O(NlogN)

    }
};
