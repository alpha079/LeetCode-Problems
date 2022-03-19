class Node{
   public:
    int first;
    int second;
    int count;
};

class comparator{
    public:
     bool operator()(Node &a,Node &b){
         
         return (a.first!=b.first ?a.first<b.first: a.count<b.count);
         
     }
};

class FreqStack {
public:
    unordered_map<int,int> map;
    priority_queue<Node,vector<Node>,comparator> pq;
    int count;
    FreqStack() {
        count=0;
        
    }
    
    void push(int val) {
        ++map[val];
        count++;
        pq.push({map[val],val,count});
        
        
    }
    
    int pop() {
        Node node=pq.top();
        pq.pop();
        --map[node.second];
        return node.second;
        
        
    }
};

