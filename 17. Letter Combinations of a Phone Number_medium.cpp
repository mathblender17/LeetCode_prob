class Solution {
public:
/**
CORE IDEA : recursion + backtracking + with proper loops for the chars
**/
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> m;//to store the values related to each char
        vector<string> res;
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        string temp;
        backtrack_pnc(0,digits,temp,res,m);
        return res;
    }
    void backtrack_pnc(int i,string& digits,string& temp,vector<string>& res,unordered_map<char,string>& m){
        //i keeps the track of levels of the tree or the length of each string in the results
        //
        if(i==digits.size()){//permutation hist it's limit - result permutation has to be of the same length of the no. of digits
            if(!temp.empty()){
                res.push_back(temp);
            }
                return;
        }

        string str = m[digits[i]];// at each level - decides the set of chars - if "23" 1st level str =abc and 2nd level str=def
        for(int j=0;j<str.size();j++){//to iterate through all the char in str - same level of tree
            temp.push_back(str[j]);
            backtrack_pnc(i+1,digits,temp,res,m);
            temp.pop_back();
        }
    }
};
