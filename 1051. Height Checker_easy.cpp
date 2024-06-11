class Solution {
public:
/*
sort the expected and check for incostensies
*/
    int heightChecker(vector<int>& heights) {
        vector<int> expected;
        for(int i=0;i<heights.size();i++){
            expected.push_back(heights[i]);
        }

        int count=0;
        sort(expected.begin(),expected.end());
        for(int i=0;i<heights.size();i++){
            if(heights[i] != expected[i]) count++;
        }
        return count;
    }
};
