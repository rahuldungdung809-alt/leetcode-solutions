class Solution {
public:
    int calculate(string s) {
        stack<long long>st;
        long long res=0;
        long long sign=1;
        long long num=0;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                num=num*10+(s[i]-'0');
            }
            else if(s[i]=='+'){
                res+=sign*num;
                num=0;
                sign=1;
            }
            else if(s[i]=='-'){
                res+=sign*num;
                num=0;
                sign=-1;
            }
            else if(s[i]=='('){
                st.push(res);
                st.push(sign);
                res=0;
                sign=1;
            }
            else if(s[i]==')'){
                res+=sign*num;
                num=0;
                int savedsign=st.top();st.pop();
                int savedres=st.top();st.pop();
                res=savedres+savedsign*res;
            }
        }
        return res+sign*num;
    }
};