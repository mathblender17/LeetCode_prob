class Solution {
public:
    bool isValid(string s) {
        ///we knoow from the 2. poit that they should be clsed in the same order
        stack<char> st;
        for(char c : s){//to traverse through all the char in s
            if(c=='(' || c=='{' || c=='['){
                st.push(c);
            }else{
                if(st.empty()||
                (c==')'&&st.top()!='(') ||
                (c=='}'&&st.top()!='{') ||
                (c==']'&&st.top()!='[')){
                    return false;
                }st.pop();
            }
        }return st.empty();

    }
};
