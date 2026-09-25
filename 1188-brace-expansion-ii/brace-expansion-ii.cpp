class Solution {
public:

    set<string> ans;

    void dfs(string exp) {

        // No more braces
        if (exp.find('}') == string::npos) {
            ans.insert(exp);
            return;
        }

        // Find first '}'
        int j = exp.find('}');

        // Find matching '{'
        int i = exp.rfind('{', j);

        // Part before '{'
        string left = exp.substr(0, i);

        // Part after '}'
        string right = exp.substr(j + 1);

        // Content inside braces
        string inside = exp.substr(i + 1, j - i - 1);

        // Split using comma
        string temp = "";

        for (char c : inside) {

            if (c == ',') {
                dfs(left + temp + right);
                temp = "";
            }
            else {
                temp += c;
            }
        }

        // Last part
        dfs(left + temp + right);
    }

    vector<string> braceExpansionII(string expression) {

        dfs(expression);

        return vector<string>(ans.begin(), ans.end());
    }
};