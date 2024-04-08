class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
     /** 
     Core logic behind this code is that we have to 
     find the range till the curr numbers can form 
     i.e. turns out to be number<=range+1
     the range will give you the max number that can be formed

     if the range+1 number is not there then add it in 
     1.e. res++ ,  range+=(range+1)

     finally, return res

     we use the greedy approach - to find the local maximum 1st 
     Time complexity :- O(n)

     **/
      int n2=nums.size();
      long range=0;
      int res=0,i=0;
      while(range<n){
         
            if(i<n2 && nums[i]<=range+1){
              range+=nums[i]; 
              i++; 
            }
            else{
                res++;
                range+=(range+1);

            }
         
      }
      return res;
    }
};
