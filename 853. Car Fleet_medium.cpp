class Solution {
public:
/**
used a vector pair to simply the problem 
if thought carefully this problem is just like linear equations (postion and time)
better to use a vector pair instead of a hash map?
while calculating the fleets the time < the maxTime means it is fleet if time is > then may be part of the next fleet 
imp to know that the sort will sort the 1st element pair - 
and while checking for the time do iteration from back
**/
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n =position.size();
        vector<pair<int,double>> cars; 
        int fleet=0;

        for(int i=0;i<n;i++){
            double time=(double)(target-position[i])/speed[i];
            cars.push_back({position[i],time});
        }sort(cars.begin(),cars.end());

        double maxTime=0.0;
        for(int i=n-1;i>=0;i--){
            double time=cars[i].second;
            if(time > maxTime){
                maxTime=time;
                fleet++;
            }
        }
        return fleet;

        
    }
};
