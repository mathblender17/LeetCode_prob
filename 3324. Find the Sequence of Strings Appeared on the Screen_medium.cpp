class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> res;
        string temp="";

        for( char ch: target){
            temp+='a';
            res.push_back(temp);

            while(temp.back() != ch){
                temp.back()++;
                res.push_back(temp);
            }

        }
        return res;
    }
};
