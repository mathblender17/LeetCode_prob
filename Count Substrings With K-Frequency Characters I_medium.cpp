class Solution {
public:
/**
Sliding window approach with prequency check 
**/
    int numberOfSubstrings(string s, int k) {
         int n=s.size();
         int result=0;

         for(int i=0;i<n;i++){
            vector<int> freq(26,0);
            int mf=0;

            for(int j= i;j<n;j++){
                char c=s[j];
                freq[c-'a']++;
                mf=max(mf,freq[c-'a']);

                if(mf>=k)result++;
            }
         }
         return result;
    }
};
