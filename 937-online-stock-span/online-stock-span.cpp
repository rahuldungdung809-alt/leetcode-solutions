class StockSpanner {
public:
    //vector<int>prices;
    //vector<pair<int,int>>st;
    stack<pair<int,int>>st;
    StockSpanner() {
        
        
    }
    
    int next(int price) {
        //OPTIMAL SOLUTION 
        int span=1;
        while(!st.empty() && st.top().first <= price){
            span+=st.top().second;
            st.pop();
        }
        st.push({price,span});
        return span;

        //BETTER SOLUTION 
        /*int span=1;
        int i=st.size()-1;
        while(i>=0 && st[i].first<=price){
            span+=st[i].second;
            i-=st[i].second;
        }
        st.push_back({price,span});
        return span;*/

        //BRUTE FORC SOLUTION TC:O(N)  SC:O(N)
        /*prices.push_back(price);
        int span=1;
        for(int i=prices.size()-2;i>=0;i--){
            if(prices[i]<=price){
                span++;
            }
            else{
                break;
            }
        }
        return span;*/
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */