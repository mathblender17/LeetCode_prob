class TimeMap {
/**CORE IDEA : to have a data structure that can store - key , value  and timestamps
we use a hash map for a string(key) and a vector of pair holding timestamp and value
and we use binary search as the tiemstamps are already in sorted order

hm[key] gives the vector<pair<int,string>>corresponding to the key
hm[key][mid] gives the pair<int,string> of the mth
**/
public:
unordered_map<string,vector<pair<int,string>>>hm;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hm[key].push_back({timestamp,value}); // pushing key -> timestamp,value in the hash map
    }
    
    string get(string key, int timestamp) {
        if(hm.find(key)==hm.end())return ""; //when the key dosem't exist in the hashmap
        //now we search using modeified binary search 
        int l=0;int h=hm[key].size()-1;
        string res="";
        while(l<=h){
            int mid=l+(h-l)/2;
            
           if(hm[key][mid].first <= timestamp){//becus if there is no mathing timestamp we should take the one one closest "<="
                 l=mid+1;
                 res=hm[key][mid].second;
                 }
            else{
                h=mid-1;
            }
        }
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
