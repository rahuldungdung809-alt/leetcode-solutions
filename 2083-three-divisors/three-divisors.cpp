class Solution {
public:
    bool isPrime(int root){
        if(root<2){
            return false;
        }
        for(int i=2;i*i<=root;i++){
            if(root%i==0){
                return false;
            }
        }
        return true;
    }
    bool isThree(int n) {
        int root=sqrt(n);
        return (root*root==n && isPrime(root));
    }
};