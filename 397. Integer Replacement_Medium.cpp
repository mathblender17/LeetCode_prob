class Solution {
public:
/**
An easy question - only point ot remember is 
1.The use of long
2.as we want the min steps for the work - we add +1 in odd numbers when num 
is divisible by 4 so as later it can be halved twice - Crucial for larger numbers 
avoid if after +1 it becomes 4 as it will only add an extra step
**/
    int integerReplacement(int n) {
        return helper(long (n));
    }
    int helper(long n){
        int c=0;
        while(n>1){
            if(n%2==0){
                n=n/2;
            }
            //imp step
            else if((n+1)%4==0 && n+1!=4)n=n+1;
            else{
                    n=n-1;
                }
            
            c++;
        }
        return c;
    }
};
