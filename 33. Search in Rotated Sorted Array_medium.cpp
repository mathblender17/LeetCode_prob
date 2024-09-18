class Solution {
public:
/**
Core idea : to use a modifiesd binary search which is able to deal with a roatated array/list
-to find the point of rotaion eith the use of mid - if found go to the left sorted subarray and applynormal BS
-if that is false go to the right subarray(prolly not sorted) and check ith BS there 
**/
    int search(vector<int>& nums, int target) {
        int l=0;int r=nums.size()-1;
        while(l<=r){
            int mid= l+(r-l)/2;

            if(nums[mid]==target) return mid;

            else if(nums[l]<=nums[mid]){// t->mid are sorted and try  to check there
                if(nums[l]<=target && nums[mid]>=target){//if taregt lies between them - go further in left sorted subarray
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            } 
            else{//when the mid is not a part of the sorted left subarray
                if(target <= nums[r] && nums[mid]<=target){ // if it lies in the right subarray which needs not be sorted
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
            
        }
        return -1; 
    }
};
