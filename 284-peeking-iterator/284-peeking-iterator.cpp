class PeekingIterator : public Iterator {
public:
   vector<int> num;
    int i=0;
   PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    num=nums;
	}
    
	int peek() {
        return num[i];
	}

	int next() {
	   int vl= num[i];
        i++;
        return vl;
	}
	
	bool hasNext() const {
       return i< num.size();
	}
};