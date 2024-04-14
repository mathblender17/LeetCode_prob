class Solution {
public:
    int longestPalindrome(string s) {
/**
Here  for a plaindroime
1.check for pairs - if pairs are there they are to be dirtectly used
2. check for odd frequency - in a plaindrom only one odd frequemcy can be used
count the odd freq then subtract odd numered gfreq and +1 it
**/
        int oddCount = 0;
        unordered_map<char, int> ump;
        for(char ch : s) {
            ump[ch]++;
            if (ump[ch] % 2 == 1)
                oddCount++;
            else    
                oddCount--;
        }
        if (oddCount > 1)
            return s.length() - oddCount + 1;
        return s.length();
    }
};
