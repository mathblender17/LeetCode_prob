class Solution {
public:
/**
CORE IDEA: deceion tree where we take char from string incrementally - 
prune the barch that is not a palindrome 
main trick to check for each substring 
**/
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        vector<string> word;
        backtrack(s,word,0);
        return res;
    }
    void backtrack(string& s,vector<string>& word,int i){
        if(i==s.length()){
            res.push_back(word);
            return;
        }
        //int j=0;
        for(int k=i;k<s.length();k++){
            string Nstr=s.substr(i,k-i+1);
            if(check_palindrome(Nstr)){
                word.push_back(Nstr);
                backtrack(s,word,k+1);
                word.pop_back();
            }
            
        }
    }
    bool check_palindrome(string ss){
        
        string rev = ss;
        reverse(rev.begin(),rev.end());
        return ss == rev;
    }
};
