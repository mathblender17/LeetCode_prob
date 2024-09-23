class Solution {
public:
/**
CORE IDEA : to fins the mediam in O(log(n+m)) time 
so merged the 2 lists is out of the question as it will lead to O(n+m)
so we so binary search only one one 

the core idea here is make pertitions on the lists such that both the partitions will have the same no. of elements
so we take the smaller of the 2 lists and make it's partitions on it and 
then make a partition on the bigger list of size  m-i where m=total elements of both lists and i id the mimdpoint of smaller list

we do this to get ot right that all the elments on the left partititon are smaller than all the elements on the right partition
we check and compare the elemnts on left partition and right partition to determine the right positon of the the partition


**/
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();

        //to set nums1 as the smaller list
        if(n>m) return findMedianSortedArrays(nums2,nums1);
        //if the list of same lenght dosen't matter;

        int l=0;
        int h=n;
        double res=0.0;

        while(l<=h){
            //setting the partitions 
            int i= l +(h-l)/2; // for the smaller list
            int j= (n+m+1)/2 - i; //for the larger list

            //assign left and right of the partitions 
            int left1 = (i>0) ? nums1[i-1] : INT_MIN; //max from the left parttion of smaller list - [possible due to the list being already sorted]
            int right1 = (i<n) ? nums1[i] : INT_MAX;
            int left2= (j>0) ? nums2[j-1] : INT_MIN;//for the list of bigger size 
            int right2 = (j<m)? nums2[j] : INT_MAX;

            //checking for partitions
            if(left1 < right2 && left2< right1){
                //even 
                if((n+m)%2==0){
                    res= ( max(left1,left2) + min(right1 , right2)) /2.0;
                }else{//odd
                     res=max(left1,left2);
                }break; //no need to check now as we have our median already
            }else if(left1 > right2){
                h=i-1;
            }else{
                l=i+1;
            }
        }
        return res;

    }
};
