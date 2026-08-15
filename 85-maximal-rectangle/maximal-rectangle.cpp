class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>left(n),right(n);

        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();    
            }
            left[i] = st.empty() ? 0 : st.top() + 1;
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            right[i] = st.empty() ? n - 1 : st.top() - 1;
            st.push(i);
        }
        int maxArea=0;
        for(int i=0;i<n;i++){
            maxArea=max(maxArea,heights[i]*(right[i]-left[i]+1));
        }
        return maxArea;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        vector<int>height(n);

        for(int i=0;i<n;i++){
            height[i]=(matrix[0][i]=='1') ?1 :0;
        }
        int maxArea=largestRectangleArea(height);
        for(int row=1;row<m;row++){
            for(int col=0;col<n;col++){
                if(matrix[row][col]=='0'){
                    height[col]=0;
                }
                else{
                    height[col]+=1;
                }

            }
            maxArea=max(maxArea,largestRectangleArea(height));
        }
        return maxArea;


        
    }
};