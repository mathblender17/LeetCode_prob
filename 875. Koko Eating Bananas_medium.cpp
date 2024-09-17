class Solution {
public:
/**COre idea : to use binary serch on the eating speeds (lowest =1  and highest= *max_element() )
not to be distracted from the lists arragement 
for each k calc the pile value and then 
check for the valid k and from there if valid go check for a smaller one 
if not valid check for the bigger one 
**/
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1; int r=*max_element(piles.begin(),piles.end());//*max_element imp

        while(l<r){
            int mid=(l+r)/2;
            int hours=0;
            for(int pile: piles){
                hours+= (pile+mid-1)/mid;//important
            }

            if(hours<=h){
                r=mid;//try for lesser value
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};
