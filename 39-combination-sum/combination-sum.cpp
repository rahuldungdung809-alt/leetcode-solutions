class Solution {
public:
    vector<vector<int>>ans;
    vector<int>path;
    void dfs(vector<int>& candidates,int target,int start){
        if(target==0){
            ans.push_back(path);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            if (candidates[i]>target){
                continue;
            }
            path.push_back(candidates[i]);
            dfs(candidates,target-candidates[i],i);
            path.pop_back();
            
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        dfs(candidates,target,0);
        return ans;

    }
/*
    vector<vector<int>>ans;
    vector<int>curr;
    void backtrack(vector<int>& candidates,int target,int index){
        if (target==0){
            ans.push_back(curr);
            return;
        }
        if (target<0 || index==candidates.size()){
            return;
        }
        curr.push_back(candidates[index]);
        backtrack(candidates,target-candidates[index],index);
        curr.pop_back();
        backtrack(candidates,target,index+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates,target,0);
        return ans;
    }*/
};