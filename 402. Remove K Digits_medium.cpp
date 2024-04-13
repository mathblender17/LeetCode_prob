#include <vector>
class Solution {
public:
/**
A elemetry question  - O(n)
1.to remove elements from the front to make it smaller - like in "1432" ,4 and 3 are to be removed 
can be implemented by check the predecessor and remove if greater
2.from back also number may be need to to removed as with smaller examples removing from the solves them - like in "112" we should remove "2" nand not 1
3.skip the leading zeros
**/

    string removeKdigits(string num, int k) {
        int n= num.length();
        vector<int> nums;

        for(int i=0;i<n;i++){
        nums.push_back(num[i]-'0');
        }

        if( n==k)return "0";

        int i = 0;
        while (k > 0 && i < nums.size()) {
            if (i > 0 && nums[i] < nums[i - 1]) {
                nums.erase(nums.begin() + i - 1); // Erase element at i-1
                k--;
                i--; // Adjust index after erasing
            } else {
                i++; // Move to next element
            }
        }
        while (k > 0) {
            nums.pop_back();
            k--;
        }

       string m;
       for (int digit : nums) {
       m += to_string(digit);
       } 

       int j=0;
       while(j<m.length() && m[j] == '0'){
        j++;
       } 

       string ms=m.substr(j,m.length());
       if(ms == "")return "0";

        return ms;
    }
};
