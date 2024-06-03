class Solution {
public:
    int help(int i, int j, int n, int m, string s, string t) {
        while (i < n && j<m) {
            if (t[j] == s[i]) {
                j++;
            } 
                i++;
            
        }
        return j;
    }
    int appendCharacters(string s, string t) {
        int n = s.length(), m = t.length();
        int i = 0, j = 0;

        if (m == 1) {
            if (n == 1 && t[j] == s[i]) {
                return 0;
            } else if (n == 1 && t[j] != s[i]) {
                return 1;
            } else {
                j=help(i,j,n,m,s,t);
                if (j == 1)
                    return 0;
                else
                    return 1;
            }
        }
        i=0,j=0;
        j=help(i,j,n,m,s,t);
        
        return m - j;
      
    }
};
