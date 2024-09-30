class Solution {
    /** CORE IDEAS : to use a set to main teh set of once iseds elements
    if repeasted lelement encountered increase the i and check of the repeated lement is removed if not check agaion after increading the 1dt pointer agaion
   - to do this till right most end reaches the end of the of the string

    **/

public:
    int lengthOfLongestSubstring(string s) {
        int n =s.length();
        unordered_set<char> chs;
        int i=0;int j=0;int ms=0;
        if(n==1)return 1;
        
        while(j<n){
            while(chs.find(s[j]) != chs.end()){
                chs.erase(s[i]);
                i++;
            }
            ms=max(ms,j-i+1);
            chs.insert(s[j]);
            j++;
        }
        return ms;
    }
};
