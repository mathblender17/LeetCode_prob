class Solution {
public:
/**
its a very simpple algo - i over comlicazted it 
sticking to the basics - making soime modification on 
how to take the number diffeently instead of doing it completly differnt method
here we use the same logic aas that of checking palindrome or something like that 
we just use a ectra factor 
**/
    int generateKey(int num1, int num2, int num3) {
        int f=1;
        int res=0;

        while(num1>0 || num2>0 || num3>0){
            int d1 = num1%10;
            int d2 = num2%10;
            int d3 = num3%10;
            int d = min({d1,d2,d3});
            res=res+ f*d;

            f*=10;
            num1/=10;
            num2/=10;
            num3/=10;
        }
        return res;
    }
};
