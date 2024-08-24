class Solution {
public:
    /**
    Another method to solve for the parenthesisi problem
    simple change in the we keep the count - core idea to solve still the same
    the integer n is being called for every recursion calls no major use of it
    **/

    void solve(int n, string temp, int ip, int lp, vector<string>& ans) {
        if (lp == n) {
            ans.push_back(temp);
            return;
        }
        if (ip < n) {
            temp.push_back('(');
            solve(n, temp, ip + 1, lp, ans);
            temp.pop_back();
        }
        if (lp < n && lp < ip) {
            temp.push_back(')');
            solve(n, temp, ip, lp + 1, ans);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        int ip = 0, lp = 0;
        solve(n, temp, ip, lp, ans);
        return ans;
    }
};
