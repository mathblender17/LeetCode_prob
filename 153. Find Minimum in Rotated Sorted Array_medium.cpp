class Solution {
public:
    int findMin(vector<int>& nums) {
        // O(n)
        // return *min_element(nums.begin(),nums.end());

        // O(log n)
        //  to implemt a binary search - modified binary search
        // there will be 2 sorted sub arrays in the list - to fid there endand start 
        int res = nums[0];
        int l = 0;
        int r = nums.size()-1;
        while (l <= r) {
            if (nums[l] < nums[r]) { // to find the least element - sepeariton between the 2 sorted subarray ( not valid for 1 rotaion)
                                     // chance not rotated
                res = min(res, nums[l]);
                break;
            }
            int mid = l + (r - l) / 2;
            res = min(res, nums[mid]);
            if (nums[l] <= nums[mid]) { // mid present in the left sorted array
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
};
