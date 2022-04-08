class KthLargest {
public:
    
    // using min heap data structure
    priority_queue<int,vector<int>,greater<int>> qq; //MIN HEAP -> MINIMUM element is at the top
    int k;
    
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(auto &nu :nums)
        {
            qq.push(nu);
            if(qq.size()> k) qq.pop();
        }
    }
    
    int add(int val) {
        qq.push(val); // after pushing the val HEAPIFY takes place as min heap
        
        if(qq.size()>k) qq.pop();
        return qq.top();
    }
};

