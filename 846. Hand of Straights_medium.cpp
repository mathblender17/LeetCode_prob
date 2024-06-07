class Solution {
public:
/**
1.sort it
2.check each num if there exist next(succesirs of it) - use a helper function
3.int he helper function  - check for next number consequetive - mark the used ones
3.As here we only have to check the possiblily of the groups - this much is enough 
**/
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        sort(hand.begin(),hand.end());
        for(int i=0;i<n;i++){
            if(hand[i]>=0){
                if(!findNext(hand,groupSize, i, n)){
                    return false;
                }
            }
        }
        return true;
    }
    bool findNext(vector<int>& hand, int groupSize,int i,int n){
        int next = hand[i]+1;
        hand[i]=-1;
        i+=1;
        int count=1;
        while(i<n && count<groupSize){
            if(hand[i] == next){
                next = hand[i]+1;
                hand[i]=-1;
                count++;
            }
            i++;
        }
        return count == groupSize;
    }
};
