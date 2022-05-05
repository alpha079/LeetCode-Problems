class MyStack {
    queue<int> q;
public:
    MyStack() {
        // queue<int> q1;
        // queue<int> q2;
    }
    
    void push(int x) {
        int sz = q.size();
        q.push(x);
        for(int i = 0; i<sz; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int top = q.front();
        q.pop();
        return top;
        
    }
    
    int top() {
         return q.front();
    }
    
    bool empty() {
        if(q.size() == 0)
            return true;
        else return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */