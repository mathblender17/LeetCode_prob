bool compare(int a,int b)
{
    return to_string(a)+to_string(b)>to_string(b)+to_string(a);
}
class Solution {
public: 
// here we use a custom sorting dunction 
// that cheks the the umer value after transferinf from the strim 

// number -> string(then join) -> number(check value)

    string largestNumber(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        string ans = "";
        for(int i = 0;i<arr.size();i++)
        ans+=to_string(arr[i]);
        if(ans[0]=='0') return "0";
        return ans; 
    }
};
