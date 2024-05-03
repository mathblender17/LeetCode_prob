class Solution {
public:
/**
quite easy - use a hash map to store the roman char and it's values
for converison -- the next char has greater  value than the curr char just subtract it from the sum
if not then just add the char value in it
**/
    int romanToInt(string s) {
        int n = s.length();
        unordered_map<char, int> hm;
        int sum = 0;
        hm['I'] = 1;
        hm['V'] = 5;
        hm['X'] = 10;
        hm['L'] = 50;
        hm['C'] = 100;
        hm['D'] = 500;
        hm['M'] = 1000;

        for (int i = 0; i < n; i++) {
            if (hm[s[i]] < hm[s[i + 1]]) {
                sum -= hm[s[i]];
            } else {
                sum += hm[s[i]];
            }
        }
        return sum;
    }
};
