//TC:- O(N)
//SC:- O(N)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area=0;
        stack<int> index;
        heights.push_back(0);
        
        for(int i=0;i<heights.size();i++)
        {
            
            while(!index.empty() and heights[index.top()]>heights[i])
            {
                int ht=heights[index.top()];
                index.pop();
                int l=index.empty() ?-1 : index.top();
                area=max(area,ht*(i-l-1));
            }
            index.push(i);
        }
        return area;
        
    }
};