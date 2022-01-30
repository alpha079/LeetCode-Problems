class MinStack {
public:    
	vector<pair<int,int>> st;

	int size;
	MinStack() {
		size=0;
	}

	void push(int val) {
		if(!size)
		st.push_back({val,val});
		else
		st.push_back({val,min(st.back().second,val)}); 

		size++;
	}

	void pop() {
		st.pop_back();
		size--;
	}

	int top() {
		return st.back().first;
	}

	int getMin() {
	   return st.back().second;
	}
};