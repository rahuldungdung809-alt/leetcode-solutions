class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //OPTIMAL SOLUTION
        unordered_map<int,int>mp;
        int left=0;
        int MaxFruit=0;
        for(int right=0;right<fruits.size();right++){
            mp[fruits[right]]++;
            if(mp.size()>2){
                mp[fruits[left]]--;
                if(mp[fruits[left]]==0){
                    mp.erase(fruits[left]);
                }
                left++;
            }
            MaxFruit=max(MaxFruit,right-left+1);

        }
        return MaxFruit;
        //BETTER SOLUTION TC:      SC:
        /*unordered_map<int,int>mp;
        int left=0;
        int MaxFruit=0;
        for(int right=0;right<fruits.size();right++){
            mp[fruits[right]]++;
            while(mp.size()>2){
                mp[fruits[left]]--;
                if(fruits[left]==0){
                    left++;
                }
            }
            MaxFruit=max(MaxFruit,right-left+1);

        }
        return MaxFruit;*/

        //BRUTE FORCE SOLUTION TC:O(N^2)  SC:O(N)
        /*int n=fruits.size();
        int res=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int>mp;
            for(int j=i;j<n;j++){
                mp[fruits[j]]++;
                if(mp.size()>2){
                    break;
                }
                res=max(res,j-i+1);
            }
        }
        return res;*/
        
    }
};