class Solution {
public:
/**
step 1 - declare and intialise a r(result string) and vector pair with romam numerals values
step 2 - iterate to check if the num is bigger than the max. value representation in roman  numersals
 if yes then add the rokan char corresponding to the value in r and subtract the same from the num
step 3 - this will go on till we check for alll the roman char
step 4 - return  r
**/
    string intToRoman(int num) {
        string r="";
        vector<pair<int,string>> rel = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, 
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, 
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
           
            };
        
        for(int i =0;i<rel.size();i++){
            while(num >= rel[i].first){
                r+=rel[i].second;
                num-=rel[i].first;
            }
        }
        return r;
    }
};
