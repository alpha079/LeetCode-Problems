class StockSpanner {
public:
    /// dry run on [58 45 59 42 57 60 30 25 33 45] for clear understanding
    stack<pair<int,int>> s;
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        int cnt=1; // Result is always 1 for self element
        while(!s.empty() and price >=s.top().first)
        {
            cnt+=s.top().second;
            s.pop();
        }
        s.push({price,cnt});
        return s.top().second;
            
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */