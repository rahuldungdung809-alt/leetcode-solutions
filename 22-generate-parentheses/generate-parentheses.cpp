class Solution {
public:
    vector<string>result;
    void solve(string& curr,int n,int open,int close){
        if(curr.length()==2*n){
            result.push_back(curr);
        }
        if(open<n){
            curr.push_back('(');
            solve(curr,n,open+1,close);
            curr.pop_back();
        }
        if(close<open){
            curr.push_back(')');
            solve(curr,n,open,close+1);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n){
        string curr="";
        int open=0;
        int close=0;
        solve(curr,n,open,close);
        return result;
    }
    /*
    vector<string>ans;
    string curr;
    bool isValid(){
        int balance=0;
        for(char ch:curr){
            if( ch =='('){
                balance++;
            }
            else{
                balance--;
            }
            if(balance<0){
                return false;
            }
        }
        return balance==0;
    }
    void generate(int n){
        if (curr.size()==2*n){
            if (isValid()){
                ans.push_back(curr);
            }
            return;
        }
        curr.push_back('(');
        generate(n);
        curr.pop_back();

        curr.push_back(')');
        generate(n);
        curr.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        generate(n);
        return ans;
        
    }*/
};