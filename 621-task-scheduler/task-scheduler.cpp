class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>freq;
        for(char task:tasks){
            freq[task]++;
        }
        priority_queue<int>pq;
        for(auto& entry:freq){
            pq.push(entry.second);
        }
        int time=0;
        while(!pq.empty()){
            vector<int>temp;
            int cycle=n+1;
            int i=0;
            while(i<cycle && !pq.empty()){
                int cnt=pq.top();
                pq.pop();
                cnt--;
                if(cnt>0){
                    temp.push_back(cnt);
                }
                time++;
                i++;
            }
            for(int val:temp){
                pq.push(val);
            }
            if(pq.empty())break;
            time+=(cycle-i);

        }
        return time;
        
    }
};