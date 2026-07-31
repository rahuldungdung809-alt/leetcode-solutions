class Solution {
public:
    long long power(long long a,long long b,long long MOD){
        long long result=1;
        while(b>0){
            if(b % 2==1 ){
                result=(__int128)result*a%MOD;            
            }
            a=(__int128)a*a%MOD;
            b=b/2;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        //Optimal solution
        const long long MOD=1000000007LL;
        long long even=(n+1)/2;
        long long odd=n/2;
        return (__int128)power(5,even,MOD)*power(4,odd,MOD)%MOD;
        //ITERATIVE BETTER SOLUTION
        /*long mod=1000000007LL;
        long ans=1;

        for(long long  i=0;i<n;i++){
            if (i%2==0){
                ans=(ans*5)%mod;
            }
            else{
                ans=(ans*4)%mod;
            }
        }
        return (int) ans;*/
        
    }
};