class Solution {
public:
    void sortColors(vector<int>& nums) {
      //3 poiinter used
      // low,high mid, to set 0's  to low 
      //and 2's to high 
      //and 1's between low and high
      int low=0,mid=0,high=nums.size()-1;

      while(mid<=high){
          if(nums[mid]==0){
              swap(nums[low],nums[mid]);
              low++;
              mid++;
          }else if(nums[mid]==1){
              mid++;
          }else{
              swap(nums[high],nums[mid]);
              high--;
          }
      }
      //return nums;
    }
};
