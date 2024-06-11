class Solution {
public:
/**
1.create and intilise a hash map  for the arr2 elements
2.count the frequency and update it in the hash map - and if no occurance add it in the reamining vector
3.insert the elemnts as the order and freq from the hash table 
4.add the the sorted reming elements 
**/
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>countMap;
        vector<int> ans,remaining;
        //hash map intialised 
        for(int i=0;i<arr2.size();i++){
            countMap[arr2[i]]=0;
        }
        //freq count
        for(int i=0;i<arr1.size();i++){
            if(countMap.find(arr1[i]) != countMap.end()){
                countMap[arr1[i]]++;
            }else{
                remaining.push_back(arr1[i]);
            }
        }
        //sort the reainder
        sort(remaining.begin(),remaining.end());
        //final values
        for(int i=0;i<arr2.size();i++){
            for(int j=0;j<countMap[arr2[i]];j++){
                ans.push_back(arr2[i]);
            }
        }
        for(int i=0;i<remaining.size();i++){
            ans.push_back(remaining[i]);
        }
        return ans;

    }
};
