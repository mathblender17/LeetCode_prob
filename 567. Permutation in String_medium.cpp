class Solution {
public:
/** CORE IDEA  : to check for permutaion of s1 in s2
for permutaionn checkwe use the frequency( as if the permutation is present those char freq should be the same)
also to use a a sliding window of the size of s1 on s2 and match for frequencies as well as permutations
**/

    bool checkInclusion(string s1, string s2) {
         int n =s1.size();
         int m=s2.size();
         if(n>m)return false;//if s1>S2 then just notpossible

         vector<int>C1(26,0); vector<int>window(26,0);

        
         for(int i=0;i<n;i++){//window of size n ( size of s1)
            window[s2[i]-'a']++;
            C1[s1[i]-'a']++;
         }

         for(int i=n;i<m;i++){
            if(C1==window)return true;

            window[s2[i]-'a']++; // new element 
            window[s2[i-n]-'a']--; // old element removed
         }
         return C1 == window;       
    }
};
