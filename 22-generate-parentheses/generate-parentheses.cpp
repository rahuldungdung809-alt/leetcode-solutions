class Solution {
public:
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
        
    }
};