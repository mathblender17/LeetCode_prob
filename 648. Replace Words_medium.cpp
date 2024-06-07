class Solution {
public:
/**
1. declare and intialise the set (only need to check)
2. check for the prefix of the woerd to be replacxed 
3. cehck for the black paces after the words - they mark the end of it
4. 
**/
    string replaceWords(vector<string>& dict, string sent) {
        set<string> s;
        for(auto i: dict){
            s.insert(i);
        }
        string ans="";
        string temp="";
        sent.push_back(' ');//to handle the last word
        for(int i=0;i<sent.size();i++){
            if(sent[i] == ' '){
                ans+=temp;
                ans+=(char)(' ');
                temp="";
            }
            else{
                temp+=(char)sent[i];
                if(s.count(temp)){
                    ans+=temp;
                    ans+=(char)(' ');
                    temp="";
                    while(sent[i]!=' ')i++;//to get to end after the prefix is matched
                }
            }
        }
        ans.pop_back();
        return ans;
    }
};
