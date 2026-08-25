class Solution {
public:
    struct Class{
        double gain;
        int pass;
        int total;
        bool operator<(const Class&other)const{
            return gain < other.gain;
        }
    };
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<Class>pq;
        for(auto c:classes){
            int pass=c[0];
            int total=c[1];
            double gain=(double)(pass+1)/(total+1) - (double)pass/total;
            pq.push({gain,pass,total});
        }
        while(extraStudents>0){
            Class current=pq.top();
            pq.pop();
            current.pass++;
            current.total++;
            extraStudents--;
            current.gain=(double)(current.pass+1)/(current.total+1) -(double)current.pass/current.total;
            pq.push(current);
        }
        double sum=0;
        while(!pq.empty()){
            Class current=pq.top();
            pq.pop();
            sum+=(double)current.pass/current.total;
        }
        
        return sum/classes.size();
    }
};