class Solution {
public:
/**
to remember the position of number when opeinig or solving a RPN 
stoi - converts the whole string directy to num
isdigit() - check if the it is a digit or not - does not work for multidigit num
try to reduce the code by reducing the ifs and loops
**/
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for(auto token : tokens){
            if(token=="+" || token=="-" || token=="*" || token=="/"){
                int b=s.top();s.pop();
                int a=s.top();s.pop();

                if(token == "+")s.push(a+b);
                else if(token == "-")s.push(a-b);
                else if(token == "*")s.push(a*b);
                else if(token == "/")s.push(a/b);
                
            }else{
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};
