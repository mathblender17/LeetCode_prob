class Solution {
    //1st solution was done with 2 pinter approach but one key point was missing - it was always starting w.r.t. 1st element 
    //- so if the 1st element was differtn while all other were same curr algo would take only the 1st element as  index  and move forward - so error in output 
/**THE SOLUTION:
here we use a sliding window appraoch - a frequnecy vector and maxCount to solve the problem

**/


public:
    int characterReplacement(string s, int k) {
        //int n=s.length();
        int  maxCount=0;
        vector<int> alpha(26,0);
        int i=0;int j=0;
        int result=0;

        while(j<s.length()){
            alpha[s[j]-'A']++;//counts the freq of each char passing through the window

            maxCount=max(maxCount,alpha[s[j]-'A']);//decides which element to take coreresponding maxCount

            if(j-i+1 - maxCount > k){//if the no. of repacement needed exceed k push the window forward
                alpha[s[i]-'A']--;
                i++;
            }
            result=max(result,j-i+1);
            j++;
        }
        return result;
    }
};
