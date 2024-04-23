class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        /**
        step 1 : declare, populate and sort  the vector of pairs , declare the priority queue
        **/
        int n =p.size();
        vector<pair<int,int>> u;
        priority_queue<int> cp;
        for(int i=0;i<n;i++){
            u.push_back({c[i],p[i]});
        }
        sort(u.begin(),u.end());

        /**
        step 2: find the range till current w is valid  - when it w is smaller do a project(" k--;  i++; ") and update the value of w - using the priority queue
        **/
        for(int i=0;i<n;i++){
            if(u[i].first <= w ){
                cp.push(u[i].second);
            }
            else{
                if( k && !cp.empty()){
                    w+=cp.top();
                    cp.pop();
                    k--;
                    i--;
                }
            }
        }
        
        /**
        Step 3: if project still left to be done (k!=0) and priority queue is not empty - complete the projects from the available projects in the priority queue and update the w
        **/
        while( k && !cp.empty()){
            w+=cp.top();
            cp.pop();
            k--;
        }
        // Step 4: return w
        return w;
    }
};
