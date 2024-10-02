class Solution {
    //looking at it a mix of 2 pinter and siding window likey to be used 
    /**CORE IDEA: first to find the window where exist all the element of t in s 
    this is done using 2 pointers i and j - where j is extendsed till all the elements are found 
    then left will be extended till the minimum viable string
    this string then will be printed
    -we use a start and minLenght pointer to keep the track of the shortest string
    -also we have to the both left and right independant 
    -2 hash maps as well as need and have counters 
    **/
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size())return "";

        unordered_map<char,int> tCount;
        unordered_map<char,int> window;

        for(int i=0;i<t.size();i++){
            tCount[t[i]]++;
        }

        int left=0;int right=0;
        int  have=0; int need = tCount.size();//tCount size for unique values
        int minLength=INT_MAX; int start=0;

        while(right<s.size()){
            window[s[right]]++;
            if(tCount.find(s[right]) != tCount.end() && window[s[right]] == tCount[s[right]]){
                have++;
            }

            while(have == need){

                if(right-left+1<minLength){
                    minLength=right-left+1;
                    start=left;
                }
                window[s[left]]--;
                if(tCount.find(s[left]) != tCount.end() && window[s[left]] < tCount[s[left]]){
                    have--;
                }
                left++;
            }
            right++;
        }
        return minLength==INT_MAX?"":s.substr(start,minLength);
    }
};
