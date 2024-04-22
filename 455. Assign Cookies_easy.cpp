class Solution {
public:
/**
1.sort both the lists
2.for each eleent in the greed list try to match it from the size list
3.if match found sc++ and i++ else j++
4.return sc
**/
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int sc = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) {
                sc++;
                i++;
            }
            j++;
        }
        return sc;
    }
};
