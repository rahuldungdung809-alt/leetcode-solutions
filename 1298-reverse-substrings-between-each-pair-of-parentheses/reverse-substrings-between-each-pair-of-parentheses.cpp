class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string curr = "";

        for (char ch : s) {
            
            if (ch == '(') {
                // Save current string
                st.push(curr);
                curr = "";
            }
            
            else if (ch == ')') {
                // Reverse current substring
                reverse(curr.begin(), curr.end());

                // Add it to previous string
                curr = st.top() + curr;
                st.pop();
            }
            
            else {
                // Normal character
                curr += ch;
            }
        }

        return curr;
        
    }
};