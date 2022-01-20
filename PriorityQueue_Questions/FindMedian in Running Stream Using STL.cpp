//Time:- NlogN
//median in O(1)
//Space:- O(N)

class MyHeap{

    private: 
    	priority_queue<int> maxHeap;
    	priority_queue<int,vector<int>,greater<int>> minHeap;
    public:
    	void push(int num)
    	{
    		if(minHeap.empty())
    		{
    			minHeap.push(num);
    			return;
    		}

    		//if current num is greater then top of MinHeap.
    		//First Insert in Minheap. then Pop the top element from MinHeap and insert into MaxHeap

    		if(num>minHeap.top())
    		  minHeap.push(num);
    		else 
    		  maxHeap.push(num);

    		 if(minHeap.size() != maxHeap.size()){
                if(minHeap.size()>maxHeap.size()){
                    int t = minHeap.top();
                    minHeap.pop();
                    maxHeap.push(t);
                }
                else{
                    int t = maxHeap.top();
                    maxHeap.pop();
                    minHeap.push(t);
                }
                    
            }
    	}

    	float GetMedian()
    	{
    		 if(minHeap.size()==maxHeap.size()){
                return (minHeap.top()+maxHeap.top())/2.0;
            }
            else{
                if(minHeap.size()>maxHeap.size()) 
                    return minHeap.top();
                else
                    return maxHeap.top();
            }
    	}
    };

    int main()
    {
    	int n;
    	cin>>n;
    	vector<int> ar(n);
    	MyHeap mh;

    	for(int i=0;i<n;i++)
    	{
    		cin>>ar[i];
    		mh.push(ar[i]);
    		cout<<hm.GetMedian()<<" ";

    	}
    	return 0;
    }
