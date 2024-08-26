class Solution {
public:
/**
using array it is possible but time complexity will be O(N^2)
to optimise we use stack TC : O(N)

**/
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n =temp.size();
        vector<int> result(n,0);
        stack<int> stk;

        for(int i=0;i<n;i++){

            while(!stk.empty() && temp[i] > temp[stk.top()]){
                int j = stk.top();
                stk.pop();
                result[j]=i-j;

            }
            stk.push(i);
        }
        return result;
    }
};
