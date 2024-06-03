class Solution {
public:
/**
possibles approaches 
1. two pointer
2. recursive(might take more than O(1)
**/
    void reverseString(vector<char>& s) {
        int n=s.size();
        int l=0, r=n-1;
        while(l<r){
            swap(s[l],s[r]);
            l++;
            r--;
        }      
       
    }
};
