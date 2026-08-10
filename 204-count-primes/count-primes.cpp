class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        vector<int>isPrime(n,1);
        isPrime[0]=0;
        isPrime[1]=0;
        for(long long i=2;i*i<n;i++){
            if(isPrime[i]==1){
                for(int j=i*i;j<n;j+=i){
                    isPrime[j]=0;
                }
            }
        }
        int count=0;
        for(int i=2;i<n;i++){
            if(isPrime[i]==1){
                count++;
            }
        }
        return count;
    }
        
    /*bool isPrime(int m){
        if(m<=1){
            return false;
        }
        for(int i=2;i*i<m;i++){
            if(m%i==0){
                return false;

            }
        }
        return true;
    }*/
        /*int count=0;
        for(int i=0;i<n;i++){
            if(isPrime(i)){
                count++;
            }
        }
        return count;*/
};