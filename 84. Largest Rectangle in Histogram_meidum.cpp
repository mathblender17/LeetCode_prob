class Solution {
public:
/** Core lo;gic to take care of in the problem 
1. to pop when encounterd a number lesser than the previos appear 
2. to pop till the encouneterd and the top matches 
3. also remember to calculate the popped elements
to use a monotonic stack as the the T=O(n) instead of T=O(N^2) but takes space complexity as O(N) 
**/
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> stk;

        int result=0;
        //does check if the element to be inserted is greater than or less than the currennt top element
        //if greater no problem just add in the monotonic increasing stack
        // but if lesser then pop and calculate the rectangle 
        //then pop till elements till the top element becomes less then the curr
        //if ther elemnets get left in the stakc after going through all then calc them and pop them as well

      
        for(int i=0;i<heights.size();i++){
            int start=i;
        
            while(!stk.empty() && heights[i]<stk.top().second){
                int index = stk.top().first;
                int width = i-index;
                int height=stk.top().second;
                stk.pop();
                result=max(result, width*height);
                start=index;//counts the indewx this way to make for easier calculation of width
            }
            stk.push({start,heights[i]});
        }
        //for the elements left in the stack 
        while(!stk.empty()){
            int width = heights.size()-stk.top().first;
            int height = stk.top().second;
            stk.pop();
            result=max(result,width *height);

        }
        return result;
    }
};
