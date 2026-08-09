class Solution {
public:
    vector<vector<int> > ans;
    vector<int> result;
    void solve(int index,  vector<int> &nums) {
        if(index >= nums.size()) {
            ans.push_back(result);
            return;
        }
        result.push_back(nums[index]);
        solve(index + 1, nums);
        result.pop_back();
        solve(index + 1, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        
        solve(0, nums);
        return ans;
    }
    /*
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {*/



        /*
        int n=nums.size();
        for(int mask=0;mask<(1<<n);mask++){
            vector<int>temp;
            for(int i=0;i<n;i++){
                if(mask & (1<<i)){
                    temp.push_back(nums[i]);
                }
            }
            ans.push_back(temp);
        }
        return ans;*/
        




















        /*int n=nums.size();
        for(int mask=0;mask<(1<<n);mask++){
            vector<int>temp;
            for(int i=0;i<n;i++){
                if(mask & (1<<i)){
                    temp.push_back(nums[i]);
                }
            }
            ans.push_back(temp);
        }
        return ans;*/
        
    
};