class Solution {
public:
/**
esay just remmber the abs function and the sub of char(ASCII)
**/
    int scoreOfString(string s) {
        int n=s.length();
        int sum=0;
        for(int i=0;i<n-1;i++){
            sum+=abs(s[i]-s[i+1]);
        }
        return sum;
    }
};
