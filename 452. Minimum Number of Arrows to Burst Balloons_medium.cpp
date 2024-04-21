class Solution {
public:
/**
to maximaise the ballon bursting with minium number of arrow
1.sort the points array
2.intialise the x-end of the first element and compare it with the x-start of the second element
3.if greater ans++ adn update the end to the the x end of the current element
4.if not greter check for min between end and x-end of the current element 
**/

    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int end=points[0][1];
        int ans=1;
        for(int i=1;i<points.size();i++){
            if(points[i][0] > end){
                ans++;
                end=points[i][1];
            }
            end=min(points[i][1],end);
        }
        return ans;
    }
};
