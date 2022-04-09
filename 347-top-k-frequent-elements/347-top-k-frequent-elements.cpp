class Solution {
public:
    vector<int> topKFrequent(vector<int>&a, int k) {
	// find the frequency of an element
        unordered_map<int,int>m;
        for(int i=0;i<a.size();i++)
            m[a[i]]++;
			// putting the frequency and element in min heap  
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>mi;
        for(auto &i:m)
        {
		// smaller frequency element is pop out 
            mi.push({i.second,i.first});
            if(mi.size()>k)
                mi.pop();
        }
        vector<int>arr;
		// rest element is store in resultant vector and then return
        while(mi.size()>0)
        {
            arr.emplace_back(mi.top().second);
            mi.pop();
        }
        return arr;
    }
};