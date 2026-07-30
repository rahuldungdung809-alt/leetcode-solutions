class Solution {
public:
    double myPow(double x, int n) {
        //BETTER SOLUTION (USING RECRURSSION)
        long M=n;
        if(M<0){
            x=1/x;
            M=-M;
        }
        return power(x,M);
    }
    private: 
    double power(double x,long n){
        if (n==0){
            return 1;
        }
        double half=power(x,n/2);
        if(n%2==0){
            return half*half;
        }
        else{
            return half*half*x;
        }
    }
        //BRUTE FORCE SOLUTION
        /*long N=n;
        if(N<0){
            x=1/x;
            N=-N;
        }
        double ans =1;
        while(N>0){
            if((N&1)==1){
                ans*=x;

            }
            x*=x;
            N>>=1;
        }
        return ans;*/
        //*****************************
        /*if (n==0)return 1.0;
        if (x==0)return 0.0;
        if (x==1)return 1.0;
        if(x==-1 && n%2==0)return 1.0;
        if (x==-1 && n%2!=0)return -1.0;*/
        /*long biniform=n;
        if(n<0){
            x=1/x;
            biniform=-biniform;
        }
        double ans=1;
        while(biniform>0){
            if(biniform %2==1){
                ans*=x;
            }
            x*=x;
            biniform/=2;
        }
        return ans;*/

        
    //}
};