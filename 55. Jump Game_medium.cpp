class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n<2)return true;
        int flag =n-1;
        
        for(int i = n-2;i>=0;i--){
            if(i+nums[i] >= flag){
               flag=i;
               
            }
            

        }
        if(flag == 0)return true;
        else{return false;}
    }
};
