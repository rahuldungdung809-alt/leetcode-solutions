class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int m=s.size();
        while(i<m && s[i]==' '){
            i++;
        }
        int sign=1;
        if(i<m && (s[i]=='+' || s[i]=='-')){
            if(s[i]=='-'){
                sign=-1;
            }
            i++;
        }
        long long num=0;
        while(i<m && isdigit(s[i])){
            int digit=s[i]-'0';
            num=num*10+digit;
            if(sign*num>INT_MAX){
                return INT_MAX;
            }
            if(sign*num<INT_MIN){
                return INT_MIN;
            }
            i++;
        }
        return sign*num;
        
    }
};