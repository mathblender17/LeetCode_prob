class Solution {
public:// TC O(N)  technically 2n as the array is travesed twice
//        SC O(1)

// Floyd's tortoise and hare algo  - i.e fast and slow pointers
// we treat this array/vector as a linkedlist and find ac cycle {here the nums[i] = j, pointer from index i to index j.}
// 1 trwsversal is for finding the cycl;e existance
// 2nd one is for finding the start of the cycle - i.e finding the number repeated
    int findDuplicate(vector<int>& nums) {
        int fast = nums[0];
        int slow= nums[0];

        do{
            slow=nums[slow];
            fast=nums[nums[fast]];

        }while(slow != fast);
        slow=nums[0];

        while(slow != fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return fast;
    }
};
