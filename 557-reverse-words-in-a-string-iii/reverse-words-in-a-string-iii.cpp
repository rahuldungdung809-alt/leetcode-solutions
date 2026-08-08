class Solution {
public:
    string reverseWords(string s) {
        s.push_back(' ');
        int start=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                int left=start;
                int right=i-1;

                while(left<right){
                    swap(s[left],s[right]);
                    left++;
                    right--;
                }
                start=i+1;
            }
        }
        s.pop_back();
        return s;
    }
};