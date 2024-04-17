class Solution {
public:
/**
here
1. sorting the intervals
2. campare the end of the previous interval with the next 1st interval , if previous greater do c++  and update the end take min between previous nad current 
else
3. update the end to current and proceed 
4. return c
   
**/
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        if(intervals.empty() || intervals.size()==1) return 0;
        sort(intervals.begin(),intervals.end()); 
        int end = intervals[0][1];
        int c=0;

        for(int i =1;i<intervals.size();i++){
            if(end > intervals[i][0] ){
                c++;
                end=min(end,intervals[i][1]);
            }else{
                end=intervals[i][1];
            }
        }
        return c;
    }
};
