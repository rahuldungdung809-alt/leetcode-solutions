class Solution {
public:
    int calculate(string s) {
        long long ans=0;
        long long last=0;
        long long num=0;
        char op='+';
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(isdigit(ch)){
                num=num*10+(ch-'0');
            }
            if(!isdigit(ch) && ch !=' ' || i==s.length()-1){
                if(op=='+'){
                    ans+=last;
                    last=num;
                }
                else if(op=='-'){
                    ans+=last;
                    last=-num;
                }
                else if(op=='*'){
                    last=last*num;
                }
                else if(op=='/'){
                    last=last/num;
                }
                op=ch;
                num=0;
            }
        }
        return ans+last;
        
    }
};